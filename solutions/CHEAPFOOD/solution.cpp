#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a bill amount X.
 * Coupon 1: 10% discount = X * 0.10 = X / 10
 * Coupon 2: Flat discount = 100
 * We need to find the maximum of (X / 10) and 100.
 * 
 * Constraints:
 * 100 <= X <= 10000
 * X is a multiple of 100.
 * Time complexity per test case: O(1)
 * Space complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        // Calculate the two possible discounts
        long long discount1 = x / 10;
        long long discount2 = 100;
        
        // Output the maximum of the two
        cout << max(discount1, discount2) << "\n";
    }
    
    return 0;
}