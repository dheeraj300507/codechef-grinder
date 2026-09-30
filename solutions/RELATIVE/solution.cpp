#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given the formula v^2 = 2 * g * H.
 * We want to find the height H such that the velocity v equals the speed of light c.
 * Substituting v = c into the equation:
 * c^2 = 2 * g * H
 * H = c^2 / (2 * g)
 * 
 * Constraints:
 * 1 <= T <= 5000
 * 1 <= g <= 10
 * 1000 <= c <= 3000
 * 2 * g divides c^2.
 * 
 * Since c can be up to 3000, c^2 can be up to 9,000,000.
 * This fits comfortably within a standard 32-bit integer, but using 
 * long long is safer and good practice in competitive programming to 
 * prevent overflow in intermediate calculations.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long g, c;
        cin >> g >> c;
        
        // Calculate H = (c * c) / (2 * g)
        // Given that 2 * g always divides c^2, integer division is exact.
        long long h = (c * c) / (2 * g);
        
        cout << h << "\n";
    }
    
    return 0;
}