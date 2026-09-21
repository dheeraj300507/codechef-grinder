#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Team A scored R runs.
 * Team B has played O overs and scored C runs.
 * Remaining overs = 20 - O.
 * Each over has 6 balls, and each ball can score a maximum of 6 runs.
 * Maximum runs per over = 6 * 6 = 36.
 * Maximum runs possible in remaining overs = (20 - O) * 36.
 * Maximum total score for Team B = C + (20 - O) * 36.
 * Team B wins if (Maximum total score) > R.
 * 
 * Constraints:
 * R, O, C are within integer limits (max 720), so 'int' is sufficient.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, O, C;
    // The problem description implies a single test case per run based on the format,
    // but standard competitive programming practice handles input as specified.
    if (cin >> R >> O >> C) {
        int remaining_overs = 20 - O;
        int max_additional_runs = remaining_overs * 36;
        int max_total_score = C + max_additional_runs;

        if (max_total_score > R) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}