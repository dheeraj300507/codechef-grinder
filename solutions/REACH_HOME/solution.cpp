#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X litres of fuel.
 * The motorcycle travels 5 km per 1 litre of fuel.
 * Maximum distance Chef can travel = X * 5 km.
 * Chef can reach home if (X * 5) >= Y.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X, Y <= 1000
 * X * 5 will be at most 5000, which fits in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate maximum distance possible with current fuel
        long long max_distance = x * 5;
        
        // Check if the distance to home is reachable
        if (max_distance >= y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}