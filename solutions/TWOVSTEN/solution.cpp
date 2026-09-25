#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with X. In each turn, X = X * 2.
 * We want X % 10 == 0.
 * 
 * Let's look at the last digit of X:
 * - If X % 10 == 0: Already divisible, 0 turns.
 * - If X % 10 == 5: 
 *      X * 2 will end in 0 (e.g., 5*2=10, 15*2=30, 25*2=50). 1 turn.
 * - Any other last digit:
 *      If X ends in 0, 2, 4, 6, 8:
 *          Multiplying by 2 will always result in an even number (ends in 0, 2, 4, 6, 8).
 *          If it doesn't end in 0 initially, it will never end in 0 because 
 *          the sequence of last digits for powers of 2 (multiplied by X) cycles.
 *          Specifically, if X is even but not divisible by 10, X*2, X*4... will 
 *          never be divisible by 10.
 *      If X ends in 1, 3, 7, 9:
 *          Multiplying by 2 will result in 2, 6, 4, 8. None of these are 0.
 * 
 * Conclusion:
 * 1. If X % 10 == 0, return 0.
 * 2. If X % 10 == 5, return 1.
 * 3. Otherwise, return -1.
 */

void solve() {
    long long x;
    cin >> x;
    
    if (x % 10 == 0) {
        cout << 0 << "\n";
    } else if (x % 5 == 0) {
        // Since x % 10 != 0 but x % 5 == 0, x must end in 5.
        // Multiplying by 2 makes it end in 0.
        cout << 1 << "\n";
    } else {
        // Any other case will never result in a number divisible by 10.
        cout << -1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}