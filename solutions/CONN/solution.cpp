#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find non-negative integers X and Y such that 2X + 7Y = N.
 * This is a variation of the Frobenius Coin Problem (or Change-making problem).
 * Since we have 2 and 7, we can represent any number N as long as N is not 
 * too small or specifically impossible.
 * 
 * Specifically:
 * - If N is odd, we must use at least one 7 (since 2X is always even).
 *   If we use one 7, we need (N - 7) to be non-negative and even.
 * - If N is even, we can always represent it as 2X (using only 2s) 
 *   provided N >= 0.
 * 
 * So, for any N:
 * 1. If N < 0, impossible.
 * 2. If N is even, it's always possible (N = 2 * (N/2)).
 * 3. If N is odd, we check if (N - 7) is non-negative and even.
 *    (N - 7) >= 0 implies N >= 7.
 *    If N >= 7 and N is odd, then (N - 7) is even, so it can be represented by 2s.
 * 
 * Combining these:
 * - N = 1: NO
 * - N = 3: NO
 * - N = 5: NO
 * - All other N are YES.
 */

void solve() {
    long long N;
    cin >> N;

    // Based on the logic:
    // 1, 3, 5 are impossible.
    // 2, 4, 6, 7, 8, 9, 10, 11... are possible.
    if (N == 1 || N == 3 || N == 5) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
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