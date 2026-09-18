#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial water: W
 * Capacity: X
 * Inflow rate: Y
 * Time: Z
 * Total water after Z hours = W + (Y * Z)
 * 
 * Comparison:
 * If (W + Y * Z) > X: overflow
 * If (W + Y * Z) == X: filled
 * If (W + Y * Z) < X: unfilled
 * 
 * Constraints:
 * W, X, Y, Z <= 1000
 * Max possible value = 1000 + (1000 * 1000) = 1,001,000
 * This fits well within a standard 32-bit signed integer, 
 * but using long long is safer practice in competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long W, X, Y, Z;
        cin >> W >> X >> Y >> Z;
        
        long long total_water = W + (Y * Z);
        
        if (total_water > X) {
            cout << "overflow" << "\n";
        } else if (total_water == X) {
            cout << "filled" << "\n";
        } else {
            cout << "unfilled" << "\n";
        }
    }
    
    return 0;
}