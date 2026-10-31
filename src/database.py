"""Account-scoped persistence for solved / failed / pending CodeChef problems.

Why this module exists
----------------------
The original database was a bare JSON file with no notion of *which CodeChef
account* its records belonged to. When the repository was forked, the fork
inherited the upstream owner's ``solved_problems.json`` (hundreds of problems
solved on *their* account). The bot then skipped all of those problems and
reported them as "solved", even though the fork owner's account had never
submitted them.

Schema v2 binds the database to a CodeChef username and stores the evidence
(submission id) for every accepted record. A database belonging to a different
(or unknown) account is never silently reused: it is archived untouched and a
fresh database is started for the configured account.
"""

import datetime
import json
import logging
import shutil
from pathlib import Path
from typing import Any, Dict, List, Optional

logger = logging.getLogger("SolvedDatabase")

SCHEMA_VERSION = 2


def utc_now() -> datetime.datetime:
    return datetime.datetime.now(datetime.timezone.utc)


def _timestamp(dt: Optional[datetime.datetime] = None) -> str:
    return (dt or utc_now()).strftime("%Y-%m-%d %H:%M:%S")


def empty_database(account: str) -> Dict[str, Any]:
    return {
        "schema_version": SCHEMA_VERSION,
        "account": account,
        "total_solved": 0,
        "solved_codes": [],
        "failed_codes": [],
        "pending": [],
        "history": [],
    }


def archive_database(data_path: Path, reason: str) -> Path:
    """Copy the existing database to data/archive/ without modifying it."""
    archive_dir = data_path.parent / "archive"
    archive_dir.mkdir(parents=True, exist_ok=True)
    stamp = utc_now().strftime("%Y%m%dT%H%M%SZ")
    target = archive_dir / f"{data_path.stem}.{reason}.{stamp}{data_path.suffix}"
    shutil.copy2(data_path, target)
    return target


def load_database(data_path: Path, account: str) -> Dict[str, Any]:
    """Load the database for ``account``.

    If the file is missing, unreadable, or belongs to a different / unknown
    account, the old file is archived (never deleted) and a fresh database is
    returned. The fresh database is written to disk only when ``save_database``
    is called.
    """
    if not account:
        raise ValueError("A CodeChef username is required to load the solved database.")

    if not data_path.exists():
        logger.info(f"No database at {data_path}; starting fresh for account '{account}'.")
        return empty_database(account)

    try:
        with open(data_path, "r", encoding="utf-8") as f:
            db = json.load(f)
    except Exception as e:
        archived = archive_database(data_path, "unreadable")
        logger.warning(f"Could not parse {data_path} ({e}); archived to {archived} and starting fresh.")
        return empty_database(account)

    owner = db.get("account")
    if owner != account:
        archived = archive_database(data_path, f"account-{owner or 'unbound'}")
        logger.warning(
            f"Database at {data_path} belongs to account '{owner or 'UNKNOWN'}' "
            f"(configured account: '{account}'). Its {len(db.get('solved_codes', []))} 'solved' "
            f"records were NOT produced by this account and will not be counted. "
            f"Archived original to {archived}; starting a fresh database."
        )
        return empty_database(account)

    # Fill in any fields missing from an older v2 file.
    for key, default in empty_database(account).items():
        db.setdefault(key, default)
    db["total_solved"] = len(set(db["solved_codes"]))
    return db


def save_database(data_path: Path, db: Dict[str, Any]) -> None:
    """Atomically persist the database."""
    data_path.parent.mkdir(parents=True, exist_ok=True)
    db["total_solved"] = len(set(db.get("solved_codes", [])))
    tmp = data_path.with_suffix(data_path.suffix + ".tmp")
    with open(tmp, "w", encoding="utf-8") as f:
        json.dump(db, f, indent=2)
        f.write("\n")
    tmp.replace(data_path)


def record_accepted(
    db: Dict[str, Any],
    code: str,
    name: str,
    solution_id: str,
    attempts: Optional[int],
    when: Optional[datetime.datetime] = None,
) -> bool:
    """Record an accepted submission. Returns False if the problem was already solved."""
    if not solution_id:
        raise ValueError("Refusing to mark a problem accepted without a submission id.")

    clear_pending(db, code)
    if code in db["failed_codes"]:
        db["failed_codes"].remove(code)
    if code in db["solved_codes"]:
        return False

    db["solved_codes"].append(code)
    db["history"].append({
        "code": code,
        "name": name,
        "status": "Accepted",
        "solution_id": str(solution_id),
        "attempts": attempts,
        "account": db["account"],
        "time": _timestamp(when),
    })
    db["total_solved"] = len(set(db["solved_codes"]))
    return True


def record_failed(db: Dict[str, Any], code: str) -> None:
    """Mark a problem as failed (judge rejected every attempt / tutorial problem)."""
    if code not in db["failed_codes"] and code not in db["solved_codes"]:
        db["failed_codes"].append(code)


def add_pending(db: Dict[str, Any], code: str, name: str, solution_id: str) -> None:
    """Remember a submission whose verdict was not yet known."""
    clear_pending(db, code)
    db["pending"].append({
        "code": code,
        "name": name,
        "solution_id": str(solution_id),
        "submitted_at": _timestamp(),
    })


def clear_pending(db: Dict[str, Any], code: str) -> None:
    db["pending"] = [p for p in db.get("pending", []) if p.get("code") != code]


def pending_codes(db: Dict[str, Any]) -> set:
    return {p["code"] for p in db.get("pending", [])}


def count_solved_on(history: List[Dict[str, Any]], account: str, day: datetime.date) -> int:
    """Count accepted records for ``account`` on the given UTC date."""
    day_str = day.isoformat()
    return sum(
        1
        for item in history
        if item.get("account") == account
        and item.get("status") == "Accepted"
        and str(item.get("time", "")).startswith(day_str)
    )
