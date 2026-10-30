#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LADDU
 * Approach:
 * 1. Calculate the total number of laddus earned by parsing each activity.
 * 2. Determine the redemption threshold based on the user's origin (INDIAN: 200, NON_INDIAN: 400).
 * 3. The number of months the user can redeem is total_laddus / threshold.
 * 4. Use long long for total_laddus to prevent overflow, although constraints 
 *    (100 activities * max 1000) fit in int, long long is safer practice.
 */

void solve() {
    int activities;
    string origin;
    cin >> activities >> origin;

    long long total_laddus = 0;

    for (int i = 0; i < activities; ++i) {
        string type;
        cin >> type;
        if (type == "CONTEST_WON") {
            int rank;
            cin >> rank;
            total_laddus += 300;
            if (rank < 20) {
                total_laddus += (20 - rank);
            }
        } else if (type == "TOP_CONTRIBUTOR") {
            total_laddus += 300;
        } else if (type == "BUG_FOUND") {
            int severity;
            cin >> severity;
            total_laddus += severity;
        } else if (type == "CONTEST_HOSTED") {
            total_laddus += 50;
        }
    }

    int threshold = (origin == "INDIAN") ? 200 : 400;
    cout << total_laddus / threshold << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}