#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have coins of denominations 5 and 10.
 * To minimize the number of coins, we should use as many 10-rupee coins as possible.
 * 
 * Logic:
 * 1. If X is not divisible by 5, it is impossible to form the sum using only 5 and 10. Output -1.
 * 2. If X is divisible by 5:
 *    - We want to maximize the number of 10-rupee coins.
 *    - Let X = 10 * q + r, where r is either 0 or 5.
 *    - If r = 0, we need X/10 coins of 10 rupees.
 *    - If r = 5, we need (X-5)/10 coins of 10 rupees and 1 coin of 5 rupees.
 *    - This simplifies to:
 *      - If X % 10 == 0: coins = X / 10
 *      - If X % 10 != 0: coins = (X / 10) + 1
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // If X is not divisible by 5, it's impossible
        if (x % 5 != 0) {
            cout << -1 << "\n";
        } else {
            // Calculate minimum coins
            // If X is a multiple of 10, we use only 10-rupee coins.
            // If X ends in 5, we use (X-5)/10 coins of 10 and one 5-rupee coin.
            int coins = x / 10;
            if (x % 10 != 0) {
                coins += 1;
            }
            cout << coins << "\n";
        }
    }

    return 0;
}