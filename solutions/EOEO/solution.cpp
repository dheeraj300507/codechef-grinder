#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * The game proceeds by dividing both TS and JS by 2 as long as both are even.
 * This is equivalent to removing the common power of 2 from both.
 * 
 * Let JS = 2^p * n, where n is odd.
 * The game ends when:
 * 1. Both are odd: TS/2^k and JS/2^p are both odd.
 * 2. TS is even, JS is odd: Tom wins.
 * 3. TS is odd, JS is even: Jerry wins.
 * 
 * After dividing both by 2^min(k, p), one of them becomes odd.
 * If TS becomes odd and JS becomes even, Jerry wins.
 * Since TS = 2^k * m, after dividing by 2^k, TS becomes m (odd).
 * For Jerry to win, JS must be divisible by a higher power of 2 than TS.
 * That is, if JS = 2^p * n, we need p > k.
 * 
 * So, JS must be a multiple of 2^(k+1).
 * We need to count how many JS such that 1 <= JS <= TS and JS is a multiple of 2^(k+1).
 * The number of such values is floor(TS / 2^(k+1)).
 */

void solve() {
    long long ts;
    cin >> ts;

    // Find the power of 2 that divides TS
    // We can use __builtin_ctzll for the number of trailing zeros
    long long temp_ts = ts;
    long long power_of_2 = 1;
    
    // Extract the power of 2 component
    // If ts is 12 (1100), trailing zeros = 2, power_of_2 = 4
    while ((temp_ts & 1) == 0) {
        temp_ts >>= 1;
        power_of_2 <<= 1;
    }
    
    // We need JS to be a multiple of (power_of_2 * 2)
    // The number of multiples of X in range [1, TS] is floor(TS / X)
    long long divisor = power_of_2 * 2;
    cout << ts / divisor << "\n";
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