#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial balance = W
 * Monthly deposit = X
 * Monthly deduction = Y
 * Net change per month = (X - Y)
 * Total change after Z months = (X - Y) * Z
 * Final balance = W + (X - Y) * Z
 * 
 * Constraints:
 * W, X, Y, Z <= 10^4
 * The result can be negative, and the maximum possible value is 10^4 + (10^4 * 10^4) = 10^8 + 10^4,
 * which fits comfortably within a standard 32-bit signed integer. 
 * However, using 'long long' is a best practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long w, x, y, z;
        cin >> w >> x >> y >> z;
        
        // Calculate final balance
        // Final = Initial + (Net Monthly Change * Months)
        long long final_balance = w + (x - y) * z;
        
        cout << final_balance << "\n";
    }
    
    return 0;
}