#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Car efficiency: 15 km / 1 liter
 * - Total distance to travel: 2 * Y (round trip)
 * - Petrol available: X liters
 * - Maximum distance possible: 15 * X
 * - Condition: 15 * X >= 2 * Y
 * 
 * Constraints:
 * - T <= 1000, X, Y <= 1000
 * - 15 * 1000 = 15000, 2 * 1000 = 2000. 
 * - These values fit comfortably within a standard 32-bit integer.
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;
    
    // Total distance required is 2 * Y
    // Total distance possible is X * 15
    if (X * 15 >= 2 * Y) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}