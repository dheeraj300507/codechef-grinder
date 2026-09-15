#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The insurance policy states:
 * - Maximum rebate is X.
 * - If damage Y <= X, rebate is Y.
 * - If damage Y > X, rebate is X.
 * This is equivalent to finding the minimum of X and Y: min(X, Y).
 * 
 * Constraints: 1 <= X, Y <= 30.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
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
        
        // The rebate is the smaller of the repair cost (y) and the cap (x)
        if (y <= x) {
            cout << y << "\n";
        } else {
            cout << x << "\n";
        }
    }
    
    return 0;
}