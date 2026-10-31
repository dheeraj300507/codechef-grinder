import datetime
import logging
import random
import sys
import time
from pathlib import Path

from src.config import config
from src.codechef_client import CodeChefAuthError, CodeChefClient, VerdictTimeout
from src.solver import CodeChefSolver
from src import database as dbm

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    handlers=[logging.StreamHandler(sys.stdout)],
)
logger = logging.getLogger("CodeChefAutoGrinder")


def save_solution_files(
    solutions_dir: Path,
    problem_code: str,
    code: str,
    doc: str,
    language: str
) -> None:
    """Save code and explanation markdown inside problem folder."""
    target_dir = solutions_dir / problem_code
    target_dir.mkdir(parents=True, exist_ok=True)

    ext = "cpp" if "cpp" in language.lower() or "c++" in language.lower() else "py"
    code_path = target_dir / f"solution.{ext}"
    with open(code_path, "w", encoding="utf-8") as f:
        f.write(code)

    readme_path = target_dir / "README.md"
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(doc)

    logger.info(f"Saved problem solution files at: {target_dir}")


def fallback_doc(details: dict, attempts: int) -> str:
    code = details.get("problem_code", "")
    name = details.get("problem_name", code)
    return (
        f"# [{name} ({code})](https://www.codechef.com/problems/{code})\n\n"
        f"- **Difficulty Rating**: {details.get('difficulty_rating', 'Unrated')}\n"
        f"- **Solved in**: {attempts} attempt(s)\n\n"
        "_Explanation could not be generated automatically for this problem._\n"
    )


def reconcile_pending(client: CodeChefClient, db: dict) -> None:
    """Re-check submissions whose verdict was unknown when a previous run ended."""
    for item in list(db.get("pending", [])):
        code, sid = item.get("code"), item.get("solution_id")
        verdict = client.check_verdict_once(sid)
        if verdict is None:
            logger.info(f"Pending submission {sid} for {code} is still being judged; will check again next run.")
            continue
        if verdict["passed"]:
            logger.info(f"Pending submission {sid} for {code} was ACCEPTED. Recording it.")
            dbm.record_accepted(db, code, item.get("name", code), sid, attempts=None)
        else:
            logger.info(f"Pending submission {sid} for {code} ended as {verdict['result_code']}; problem is eligible again.")
            dbm.clear_pending(db, code)


def run():
    logger.info("=== Starting CodeChef Practice Archive Auto-Grinder ===")

    client = CodeChefClient()
    solver = CodeChefSolver()
    account = config.codechef_username

    # Pre-flight Credentials Verification
    if not solver.api_key:
        logger.error(
            "CRITICAL: GEMINI_API_KEY is missing! Please configure it in your environment or GitHub Secrets."
        )
        sys.exit(1)

    if not config.dry_run and not client.session_cookie:
        logger.error(
            "CRITICAL: CODECHEF_SESSION is missing! Please add your CodeChef session cookie to GitHub Secrets."
        )
        sys.exit(1)

    if not account:
        logger.error(
            "CRITICAL: CODECHEF_USERNAME is not set. It must be the CodeChef handle that owns "
            "CODECHEF_SESSION, so the solved database is never mixed with another account's history."
        )
        sys.exit(1)

    # 1. Load the database for THIS account (foreign databases are archived, not reused)
    db = dbm.load_database(config.data_file, account)
    dbm.save_database(config.data_file, db)

    if not config.dry_run:
        try:
            reconcile_pending(client, db)
        except CodeChefAuthError as e:
            logger.error(f"CRITICAL: CodeChef session is not valid: {e}")
            sys.exit(1)
        dbm.save_database(config.data_file, db)

    solved_set = set(db["solved_codes"])
    failed_set = set(db["failed_codes"])
    pending_set = dbm.pending_codes(db)

    today_solved = dbm.count_solved_on(db["history"], account, dbm.utc_now().date())
    logger.info(
        f"Database loaded for '{account}': {len(solved_set)} accepted (with submission ids), "
        f"{len(failed_set)} failed, {len(pending_set)} awaiting verdict."
    )
    logger.info(f"Problems solved today so far (UTC): {today_solved} (Daily Target Range: {config.daily_target_min}-{config.daily_target_max})")

    profile_count = client.fetch_profile_solved_count(account)
    if profile_count is not None:
        logger.info(f"CodeChef profile '{account}' reports {profile_count} problems solved.")
        if profile_count < len(solved_set):
            logger.warning(
                f"Local database claims {len(solved_set)} solved but the profile shows {profile_count}. "
                "Check that CODECHEF_SESSION belongs to this account."
            )

    # Check if daily upper bound is reached
    if today_solved >= config.daily_target_max:
        logger.info(f"Daily quota of {today_solved} problems reached for today! Resting until tomorrow to maintain human-like activity.")
        return

    # 2. Determine Random Session Target
    if config.randomize_batch:
        target_this_run = random.randint(config.min_problems_per_run, config.max_problems_per_run)
        remaining_today = config.daily_target_max - today_solved
        target_this_run = min(target_this_run, remaining_today)
    else:
        target_this_run = config.min_problems_per_run

    logger.info(f"Targeting {target_this_run} problem(s) in this randomized session.")

    # 3. Discover Unsolved Candidate Problems
    candidate_problems = []
    seen = set()
    page = 0
    while len(candidate_problems) < target_this_run and page < 50:
        try:
            problems = client.fetch_practice_problems(
                page=page,
                limit=30,
                sort_by="successful_submissions",
                sort_order="desc"
            )
        except Exception as e:
            logger.error(f"Failed to fetch problems page {page}: {e}")
            break

        if not problems:
            break

        for p in problems:
            code = p.get("code")
            if not code or code in seen:
                continue

            try:
                diff = int(p.get("difficulty_rating", -1))
            except (TypeError, ValueError):
                diff = -1
            if diff > 0 and (diff < config.min_difficulty or diff > config.max_difficulty):
                continue

            # Skip already solved, failed, or awaiting a verdict
            if code in solved_set or code in failed_set or code in pending_set:
                continue

            seen.add(code)
            candidate_problems.append(p)
            if len(candidate_problems) >= target_this_run:
                break

        page += 1

    if not candidate_problems:
        logger.info("No new candidate problems found in targeted range. All caught up!")
        return

    logger.info(f"Selected {len(candidate_problems)} problems to solve in this session:")
    for i, p in enumerate(candidate_problems, 1):
        logger.info(f"  {i}. {p.get('code')} - {p.get('name')} (Rating: {p.get('difficulty_rating')})")

    # 4. Solve & Submit Each Problem
    solved_this_run = 0
    max_infra_errors = 2

    for idx, p_meta in enumerate(candidate_problems, 1):
        code = p_meta.get("code")
        name = p_meta.get("name")
        logger.info(f"\n[{idx}/{len(candidate_problems)}] Processing Problem: {code} ({name})...")

        try:
            details = client.fetch_problem_details(code)
        except Exception as e:
            logger.error(f"Failed to fetch details for {code}: {e}")
            continue

        clean_content = details.get("cleanContent", "")
        if "example problem statement" in clean_content.lower() or "mini guide on writing statements" in clean_content.lower():
            logger.warning(f"Skipping dummy/tutorial template problem: {code}")
            dbm.record_failed(db, code)
            dbm.save_database(config.data_file, db)
            continue

        # judge_attempts counts only submissions the judge actually rejected.
        # Infrastructure errors (Gemini outage, network, auth) never blacklist a problem.
        judge_attempts = 0
        infra_errors = 0
        previous_code = ""
        diagnostic = ""
        outcome = "unresolved"   # accepted | rejected | pending | unresolved

        while judge_attempts < config.max_retries and infra_errors < max_infra_errors:
            attempt = judge_attempts + 1
            logger.info(f"--- Problem {code} | Attempt {attempt} of {config.max_retries} ---")
            try:
                if not previous_code:
                    logger.info("Generating initial solution using Gemini...")
                    sol_code = solver.generate_initial_solution(details, config.language)
                else:
                    logger.info("Triggering Self-Healing Reflection loop...")
                    sol_code = solver.generate_self_healing_solution(
                        problem_details=details,
                        previous_code=previous_code,
                        diagnostic=diagnostic,
                        attempt=judge_attempts,
                        language=config.language
                    )
            except Exception as gen_err:
                infra_errors += 1
                logger.error(f"Solution generation failed for {code}: {gen_err}")
                time.sleep(10)
                continue

            logger.info(f"Generated solution ({len(sol_code)} chars). Preview:\n{sol_code[:160]}...\n")

            if config.dry_run:
                logger.info("[DRY RUN] Skipping live submission; nothing is recorded as solved.")
                outcome = "dry_run"
                break

            try:
                logger.info("Submitting to CodeChef IDE...")
                solution_id = client.submit_solution(code, sol_code, config.language)
            except CodeChefAuthError as e:
                logger.error(f"CRITICAL: CodeChef session is not valid, aborting run without blacklisting anything: {e}")
                dbm.save_database(config.data_file, db)
                sys.exit(1)
            except Exception as sub_err:
                infra_errors += 1
                logger.error(f"Submission request failed for {code}: {sub_err}")
                time.sleep(10)
                continue

            logger.info(f"Submitted. Solution ID: {solution_id}. Polling verdict...")
            try:
                verdict = client.poll_verdict(solution_id)
            except VerdictTimeout as e:
                # The submission exists and may well be accepted. Do NOT resubmit;
                # park it and re-check on the next run.
                logger.warning(f"{e}. Recording {code} as pending; it will be re-checked next run.")
                dbm.add_pending(db, code, name, solution_id)
                dbm.save_database(config.data_file, db)
                outcome = "pending"
                break
            except CodeChefAuthError as e:
                logger.error(f"CRITICAL: CodeChef session became invalid while polling: {e}")
                dbm.add_pending(db, code, name, solution_id)
                dbm.save_database(config.data_file, db)
                sys.exit(1)

            logger.info(f"Verdict: {verdict.get('result_code')} (Passed: {verdict.get('passed')})")

            if verdict["passed"]:
                logger.info(f"[ACCEPTED] Problem {code} solved successfully! (submission {solution_id})")
                # Persist the evidence FIRST, so a later failure cannot cause a resubmission.
                dbm.record_accepted(db, code, name, solution_id, attempts=attempt)
                dbm.save_database(config.data_file, db)
                solved_this_run += 1
                outcome = "accepted"

                try:
                    doc = solver.generate_explanation_doc(details, sol_code, attempts=attempt, language=config.language)
                except Exception as doc_err:
                    logger.warning(f"Explanation generation failed for {code} ({doc_err}); writing a minimal README.")
                    doc = fallback_doc(details, attempt)
                save_solution_files(config.solutions_dir, code, sol_code, doc, config.language)
                break

            judge_attempts += 1
            logger.warning(f"Verdict failed: {verdict.get('result_code')}")
            diagnostic = verdict.get("diagnostic", "Submission failed.")
            previous_code = sol_code
            if judge_attempts < config.max_retries:
                time.sleep(10)
        else:
            if judge_attempts >= config.max_retries:
                outcome = "rejected"

        if outcome == "rejected":
            logger.warning(f"Problem {code} was rejected by the judge {judge_attempts} times. Adding to skip list.")
            dbm.record_failed(db, code)
            dbm.save_database(config.data_file, db)
        elif outcome == "unresolved":
            logger.warning(
                f"Problem {code} could not be attempted due to infrastructure errors; "
                "it is NOT blacklisted and will be retried in a later run."
            )

        # Human-like randomized delay between different problems
        if outcome in ("accepted", "pending", "rejected") and idx < len(candidate_problems) and not config.dry_run:
            pacing_delay = random.randint(config.min_delay_seconds, config.max_delay_seconds)
            logger.info(f"Waiting {pacing_delay}s before starting next problem (human randomized pacing)...")
            time.sleep(pacing_delay)

    logger.info(f"\n=== Session Finished: Solved {solved_this_run}/{len(candidate_problems)} problems ===")
    logger.info(f"Total problems accepted on '{account}' recorded by this bot: {db['total_solved']}")


if __name__ == "__main__":
    run()
