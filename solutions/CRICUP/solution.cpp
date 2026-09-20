#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two skill levels X and Y, and a maximum allowed difference D.
 * The condition for the game to be interesting is |X - Y| <= D.
 * 
 * Constraints:
 * T <= 2000
 * 1 <= X, Y <= 100
 * 0 <= D <= 100
 * 
 * Since the values are small, standard integer types are sufficient.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y, d;
        cin >> x >> y >> d;
        
        // Calculate absolute difference
        int diff = abs(x - y);
        
        // Check if difference is within the allowed limit
        if (diff <= d) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}