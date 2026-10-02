#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The month has 30 days.
 * Day 1 is Monday.
 * Days are numbered 1 to 30.
 * A day 'd' is a Saturday if d % 7 == 6.
 * A day 'd' is a Sunday if d % 7 == 0.
 * Holidays are:
 * 1. All Saturdays (6, 13, 20, 27)
 * 2. All Sundays (7, 14, 21, 28)
 * 3. Given festival days A_i.
 * 
 * We need to count the number of unique days that are holidays.
 * Using a boolean array of size 31 to mark holidays is efficient.
 */

void solve() {
    int n;
    cin >> n;
    
    // Use a boolean array to track holidays. 
    // Index 1 to 30 represents the days of the month.
    vector<bool> is_holiday(31, false);
    
    // Mark all Saturdays and Sundays as holidays
    // Saturday: 6, 13, 20, 27
    // Sunday: 7, 14, 21, 28
    for (int i = 1; i <= 30; ++i) {
        if (i % 7 == 6 || i % 7 == 0) {
            is_holiday[i] = true;
        }
    }
    
    // Mark festival days as holidays
    for (int i = 0; i < n; ++i) {
        int day;
        cin >> day;
        is_holiday[day] = true;
    }
    
    // Count total true values in the array
    int count = 0;
    for (int i = 1; i <= 30; ++i) {
        if (is_holiday[i]) {
            count++;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}