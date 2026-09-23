#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef rents if (X * M) < Y.
 * Otherwise, he purchases (NO).
 * 
 * Constraints:
 * X, M <= 10^4, Y <= 10^8.
 * X * M can be up to 10^8, which fits in a standard 32-bit signed integer.
 * However, using long long is safer practice in competitive programming to prevent
 * potential overflow if constraints were slightly larger.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, m;
        cin >> x >> y >> m;
        
        // Calculate total cost of renting
        long long rent_cost = x * m;
        
        // Check if renting is strictly less than purchasing
        if (rent_cost < y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}