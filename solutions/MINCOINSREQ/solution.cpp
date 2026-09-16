#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has coins of value 1 and notes of value 10.
 * We want to pay exactly X rupees using the minimum number of coins.
 * To minimize the number of coins, we should maximize the use of 10-rupee notes.
 * The number of 10-rupee notes used will be floor(X / 10).
 * The remaining amount, which must be paid in 1-rupee coins, is X % 10.
 * Therefore, the minimum number of coins is simply X % 10.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        // The number of 1-rupee coins needed is the remainder when X is divided by 10.
        // Since 10-rupee notes cover the maximum possible value without using coins,
        // the remainder is the minimum number of coins required.
        long long min_coins = x % 10;
        
        cout << min_coins << "\n";
    }
    
    return 0;
}