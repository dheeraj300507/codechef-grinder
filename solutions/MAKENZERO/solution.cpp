#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 3*a + 4*b = N, where a, b >= 0.
 * This is a variation of the Frobenius Coin Problem (or Change-Making Problem).
 * For two numbers 3 and 4, the largest number that cannot be represented is 
 * (3*4) - 3 - 4 = 5.
 * Numbers that can be represented:
 * 0: Yes (0*3 + 0*4)
 * 1: No
 * 2: No
 * 3: Yes (1*3 + 0*4)
 * 4: Yes (0*3 + 1*4)
 * 5: No
 * 6: Yes (2*3 + 0*4)
 * 7: Yes (1*3 + 1*4)
 * 8: Yes (0*3 + 2*4)
 * 9: Yes (3*3 + 0*4)
 * ...
 * Any N >= 6 can be represented as 3*a + 4*b.
 * Specifically:
 * N=1: NO
 * N=2: NO
 * N=3: YES
 * N=4: YES
 * N=5: NO
 * N>=6: YES
 */

void solve() {
    int n;
    cin >> n;
    
    // Based on the analysis:
    // 1, 2, 5 are impossible.
    // 3, 4, and all integers >= 6 are possible.
    if (n == 1 || n == 2 || n == 5) {
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