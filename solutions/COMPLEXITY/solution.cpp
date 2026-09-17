#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks us to compare two integers X and Y.
 * Algorithm A has more time complexity than B if X > Y.
 * If X > Y, we output "YES", otherwise "NO".
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X, Y <= 100
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
        long long x, y;
        cin >> x >> y;
        
        // Check if algorithm A has more comparisons than algorithm B
        if (x > y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}