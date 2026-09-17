#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Akshat has X rupees.
 * Daily expenditure is Y rupees.
 * The month has 30 days.
 * Total expenditure for the month = 30 * Y.
 * We need to check if X >= 30 * Y.
 * 
 * Constraints:
 * X, Y <= 10^5.
 * 30 * Y <= 3 * 10^6.
 * This fits within a standard 32-bit integer, but using long long is safer
 * and good practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate total required budget for 30 days
        long long total_required = 30 * y;
        
        // Check if available money is sufficient
        if (x >= total_required) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}