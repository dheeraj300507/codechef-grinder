#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a goal X.
 * If Y <= X, he earns 1 rupee per chocolate sold. Total = Y * 1.
 * If Y > X, he earns 1 rupee for the first X chocolates, and 2 rupees for each extra chocolate (Y - X).
 * Total = X + (Y - X) * 2.
 * 
 * Constraints are small (X, Y <= 10), so standard integer types are sufficient.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        if (y <= x) {
            // Goal not exceeded
            cout << y << "\n";
        } else {
            // Goal exceeded: X chocolates at 1 rupee, (Y-X) chocolates at 2 rupees
            long long total = x + (y - x) * 2;
            cout << total << "\n";
        }
    }
    
    return 0;
}