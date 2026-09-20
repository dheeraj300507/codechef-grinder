#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's rating is X.
 * Recommended difficulty range is [X, X + 200].
 * Chef is solving a problem of difficulty Y.
 * We need to check if X <= Y <= X + 200.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X, Y <= 4000
 * The values fit within standard integer types.
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
        
        // Check if Y is within the inclusive range [X, X + 200]
        if (y >= x && y <= (x + 200)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}