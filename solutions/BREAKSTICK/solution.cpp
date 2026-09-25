#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a stick of length N and want to obtain a stick of length X.
 * We can break a stick of length L into k parts (k >= 2) such that all parts have the same parity.
 * 
 * Case 1: If X is odd:
 * If N is odd, we can always break N into (N-X) and X. Since N and X are both odd, 
 * (N-X) is even. This doesn't immediately satisfy the condition because the parts must have the same parity.
 * However, if X is odd, we can break N into parts of length 1. Since 1 is odd, we can 
 * break any odd length into odd parts. If N is odd, we can always reach any odd X < N.
 * If N is even and X is odd, we can break N into (N-X) and X. Since N is even and X is odd, 
 * (N-X) is odd. Now we have two parts of odd length (X and N-X). Thus, we can obtain X.
 * Conclusion: If X is odd, the answer is always YES.
 * 
 * Case 2: If X is even:
 * We can only obtain X if N is also even. If N is odd and X is even, we can only 
 * break N into odd parts (since N is odd, any partition into parts of same parity 
 * must consist of odd parts). Thus, we can never obtain an even length X from an odd N.
 * If N is even and X is even, we can break N into X and (N-X). Since both are even, 
 * this is a valid move.
 * Conclusion: If X is even, the answer is YES if N is even, and NO if N is odd.
 * 
 * Summary:
 * If X is odd: YES
 * If X is even: YES if N is even, NO if N is odd.
 * This can be simplified: If (N % 2 == 0) or (X % 2 != 0), then YES, else NO.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (x % 2 != 0) {
            // If X is odd, we can always achieve it
            cout << "YES" << "\n";
        } else {
            // If X is even, we can only achieve it if N is even
            if (n % 2 == 0) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}