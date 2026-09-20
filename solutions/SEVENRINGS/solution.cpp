#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A valid phone number consists of exactly 5 digits with no leading zeros.
 * This means the number must be in the range [10000, 99999].
 * 
 * Given N items at cost X, the total bill is B = N * X.
 * Constraints: 1 <= N, X <= 1000.
 * Max B = 1000 * 1000 = 1,000,000.
 * Since the max value fits in a standard 32-bit integer, 'long long' is safe.
 * 
 * Logic:
 * Check if 10000 <= B <= 99999.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        long long total_bill = n * x;
        
        // A 5-digit number with no leading zeros is exactly in [10000, 99999]
        if (total_bill >= 10000 && total_bill <= 99999) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}