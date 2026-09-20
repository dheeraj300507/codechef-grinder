#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Bullet speed: X pixels/frame (or pixels/second)
 * - Distance to goomba: Y pixels
 * - Time taken for bullet to travel: T_travel = Y / X
 * - Target time to hit: T_total >= Z
 * - Let S be the time Mario waits before shooting.
 * - The bullet hits at time: S + T_travel
 * - We need: S + (Y / X) >= Z
 * - Therefore: S >= Z - (Y / X)
 * - Since S must be non-negative (Mario cannot shoot before "now"),
 *   S = max(0, Z - (Y / X))
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate travel time
        long long travel_time = y / x;

        // Calculate required wait time
        long long wait_time = z - travel_time;

        // If wait_time is negative, Mario can shoot immediately (0 seconds)
        if (wait_time < 0) {
            cout << 0 << "\n";
        } else {
            cout << wait_time << "\n";
        }
    }

    return 0;
}