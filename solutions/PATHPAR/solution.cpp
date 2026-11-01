#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid is defined as A_{i, j} = i + N*(j-1).
 * Any path from (1, 1) to (N, N) consists of exactly (N-1) steps down and (N-1) steps right.
 * The total number of cells in any path is (N-1) + (N-1) + 1 = 2N - 1.
 * 
 * Let's analyze the parity of the sum of elements in a path.
 * A path consists of a sequence of cells (r_k, c_k) for k = 1 to 2N-1.
 * The value of a cell is r_k + N*(c_k - 1).
 * Sum = sum_{k=1}^{2N-1} (r_k + N*c_k - N)
 * Sum = sum(r_k) + N * sum(c_k) - (2N-1)*N
 * 
 * Parity analysis:
 * If N is even:
 *   Sum = sum(r_k) + (even)*sum(c_k) - (odd)*(even)
 *   Sum = sum(r_k) + 0 - 0 (mod 2)
 *   Sum = sum(r_k) (mod 2)
 *   In any path, the sum of row indices is invariant for a fixed N.
 *   For N even, all paths have the same parity.
 *   Specifically, for N=2, path (1,1)->(1,2)->(2,2) sum is 1+3+4=8 (even).
 *   Path (1,1)->(2,1)->(2,2) sum is 1+2+4=7 (odd).
 *   Wait, let's re-evaluate:
 *   For N=2: 
 *   Path 1: (1,1), (1,2), (2,2) -> 1 + 3 + 4 = 8 (Even)
 *   Path 2: (1,1), (2,1), (2,2) -> 1 + 2 + 4 = 7 (Odd)
 *   So for N=2, both parities are possible.
 * 
 * General observation:
 * If N is odd, the parity of the path sum is always (N % 2).
 * If N is even, both parities (0 and 1) are possible.
 * 
 * Let's check:
 * N=1: Path is (1,1), value 1. Parity 1. K=0 -> NO, K=1 -> YES.
 * N=2: Parity 0 -> YES, Parity 1 -> YES.
 * N=3: Parity 1 -> YES, Parity 0 -> NO.
 * 
 * Pattern:
 * If N is odd, parity is always 1. So if K=1, YES; if K=0, NO.
 * If N is even, both parities are possible. So YES for both K=0 and K=1.
 */

void solve() {
    long long N;
    int K;
    cin >> N >> K;

    if (N % 2 != 0) {
        // N is odd
        if (K == 1) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    } else {
        // N is even
        cout << "Yes" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}