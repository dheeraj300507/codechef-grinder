#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given 7 integers representing days of the week (1 for sunny, 0 for rainy).
 * We need to count the number of sunny days (sum of the array) and compare it 
 * with the number of rainy days (7 - sum of the array).
 * The weather is "Good" if sunny > rainy.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only store a few variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int sunny_days = 0;
        for (int i = 0; i < 7; ++i) {
            int day;
            cin >> day;
            if (day == 1) {
                sunny_days++;
            }
        }

        int rainy_days = 7 - sunny_days;

        // The condition for "Good" weather is strictly greater sunny days than rainy days
        if (sunny_days > rainy_days) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}