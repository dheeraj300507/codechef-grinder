#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Stairs:
 *    - Distance = N * sqrt(2)
 *    - Velocity = V1
 *    - Time_stairs = (N * sqrt(2)) / V1
 * 
 * 2. Elevator:
 *    - The elevator starts at ground, goes to N (distance N), then back to ground (distance N).
 *    - Total distance = 2 * N
 *    - Velocity = V2
 *    - Time_elevator = (2 * N) / V2
 * 
 * To compare Time_stairs and Time_elevator without floating point precision issues:
 * Compare (N * sqrt(2)) / V1 < (2 * N) / V2
 * Divide both sides by N (since N >= 1):
 * sqrt(2) / V1 < 2 / V2
 * sqrt(2) * V2 < 2 * V1
 * Square both sides (both sides are positive):
 * 2 * V2^2 < 4 * V1^2
 * V2^2 < 2 * V1^2
 * 
 * If V2^2 < 2 * V1^2, then Stairs is faster.
 * Otherwise, Elevator is faster (or equal).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, v1, v2;
        cin >> n >> v1 >> v2;

        // Using the derived inequality:
        // Time_stairs = (n * sqrt(2)) / v1
        // Time_elevator = (2 * n) / v2
        // We compare (n * sqrt(2)) / v1 vs (2 * n) / v2
        // Which is equivalent to comparing (sqrt(2) / v1) vs (2 / v2)
        // Which is equivalent to comparing (2 / v1^2) vs (4 / v2^2)
        // Which is equivalent to comparing 2 * v2^2 vs 4 * v1^2
        // Or simply v2^2 vs 2 * v1^2
        
        double time_stairs = (double)n * sqrt(2.0) / (double)v1;
        double time_elevator = (double)(2 * n) / (double)v2;

        if (time_stairs < time_elevator) {
            cout << "Stairs" << "\n";
        } else {
            cout << "Elevator" << "\n";
        }
    }

    return 0;
}