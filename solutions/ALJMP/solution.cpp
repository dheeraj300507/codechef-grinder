#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The frog starts at position N.
 * It makes N-1 jumps.
 * Jump i (1 <= i <= N-1):
 * If i is odd: X = X - (N - i)
 * If i is even: X = X + (N - i)
 * 
 * Let's trace for small N:
 * N=2: Start 2. Jump 1 (odd): 2 - (2-1) = 1. Final: 1.
 * N=3: Start 3. Jump 1 (odd): 3 - (3-1) = 1. Jump 2 (even): 1 + (3-2) = 2. Final: 2.
 * N=4: Start 4. Jump 1: 4 - 3 = 1. Jump 2: 1 + 2 = 3. Jump 3: 3 - 1 = 2. Final: 2.
 * N=5: Start 5. Jump 1: 5 - 4 = 1. Jump 2: 1 + 3 = 4. Jump 3: 4 - 2 = 2. Jump 4: 2 + 1 = 3. Final: 3.
 * N=6: Start 6. Jump 1: 6 - 5 = 1. Jump 2: 1 + 4 = 5. Jump 3: 5 - 3 = 2. Jump 4: 2 + 2 = 4. Jump 5: 4 - 1 = 3. Final: 3.
 * 
 * Sequence of results:
 * N=2 -> 1
 * N=3 -> 2
 * N=4 -> 2
 * N=5 -> 3
 * N=6 -> 3
 * N=7 -> 4
 * N=8 -> 4
 * 
 * Pattern: The result is ceil(N / 2).
 */

void solve() {
    long long N;
    cin >> N;
    // The pattern observed is ceil(N / 2.0)
    // Using integer arithmetic: (N + 1) / 2
    cout << (N + 1) / 2 << "\n";
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