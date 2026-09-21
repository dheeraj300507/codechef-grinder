#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef likes a match if:
 * 1. The match ends in a draw (X == Y).
 * 2. At least one goal has been scored (X > 0 or Y > 0).
 * 
 * Combining these, the condition is: (X == Y) AND (X > 0).
 * Since X == Y, if X > 0, then Y must also be > 0.
 * Thus, the condition simplifies to: (X == Y) && (X > 0).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // Check if it's a draw and at least one goal was scored
        if (x == y && x > 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}