#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Daily consumption = 5 * X.
 * Number of days the buns last = N / (5 * X) (integer division).
 * Total survival days = (Days buns last) + D.
 * 
 * Constraints:
 * N < 500, X <= 10, D < 20.
 * The values are small enough that standard integer types are sufficient,
 * but using long long is good practice for competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, d;
        cin >> n >> x >> d;

        // Total buns consumed by the family per day
        long long daily_consumption = 5 * x;

        // Days the buns last
        // If N < daily_consumption, the family survives for 0 days on buns,
        // then D days extra.
        long long days_with_buns = n / daily_consumption;

        // Total survival time
        long long total_days = days_with_buns + d;

        cout << total_days << "\n";
    }

    return 0;
}