#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has x units of food and y units of water.
 * He needs x_r units of food and y_r units of water per day.
 * He needs to survive for D days.
 * 
 * The number of days the food will last is floor(x / x_r).
 * The number of days the water will last is floor(y / y_r).
 * The total number of days he can survive is min(floor(x / x_r), floor(y / y_r)).
 * If this value is >= D, he can reach the shore.
 * 
 * Constraints are small (up to 100), so standard integer arithmetic is sufficient.
 * Time complexity per test case: O(1).
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, xr, yr, d;
        cin >> x >> y >> xr >> yr >> d;

        // Calculate how many days food and water will last
        long long food_days = x / xr;
        long long water_days = y / yr;

        // The limiting factor is the minimum of the two
        long long survival_days = min(food_days, water_days);

        // Check if he can survive for at least D days
        if (survival_days >= d) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}