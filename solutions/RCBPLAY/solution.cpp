#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB currently has X points.
 * They need at least Y points to qualify.
 * They have Z games left.
 * In each game, they can earn a maximum of 2 points (a win).
 * Therefore, the maximum number of points they can earn in Z games is 2 * Z.
 * The total points they can reach is X + (2 * Z).
 * RCB qualifies if X + 2 * Z >= Y.
 * 
 * Constraints:
 * T <= 5000
 * X, Y, Z <= 1000
 * The values fit within standard integer types, but long long is used for safety.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Calculate the maximum possible points RCB can achieve
        long long max_points = x + (2 * z);
        
        // Check if the maximum possible points meet or exceed the requirement Y
        if (max_points >= y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}