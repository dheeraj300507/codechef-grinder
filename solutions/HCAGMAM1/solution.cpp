#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We are given a binary string of length 30.
 * - '1' represents a working day, '0' represents a leave day.
 * - Salary = (Total number of '1's * X) + (Length of longest consecutive '1's * Y).
 * - Constraints: T <= 10^4, X, Y <= 999, |S| = 30.
 * - Since the string length is small (30), a simple linear scan is optimal.
 * - Time Complexity: O(T * |S|), which is ~3 * 10^5 operations, well within the 0.5s limit.
 * - Space Complexity: O(|S|) to store the string.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    string s;
    cin >> s;

    long long total_working_days = 0;
    long long max_streak = 0;
    long long current_streak = 0;

    for (char c : s) {
        if (c == '1') {
            total_working_days++;
            current_streak++;
        } else {
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 0;
        }
    }
    // Final check in case the string ends with a streak
    if (current_streak > max_streak) {
        max_streak = current_streak;
    }

    long long salary = (total_working_days * X) + (max_streak * Y);
    cout << salary << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}