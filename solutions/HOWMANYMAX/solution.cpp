#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N-1 where S[i] = '0' means A[i] < A[i+1]
 * and S[i] = '1' means A[i] > A[i+1].
 * 
 * An index i (1-indexed) can be a maximum if:
 * 1. For i = 1: S[0] must be '1' (A[1] > A[2]). If S[0] == '0', A[1] < A[2], so A[1] cannot be max.
 * 2. For i = N: S[N-2] must be '0' (A[N-1] < A[N]). If S[N-2] == '1', A[N-1] > A[N], so A[N] cannot be max.
 * 3. For 1 < i < N: A[i] can be a maximum if it is a local peak, i.e., A[i-1] < A[i] and A[i] > A[i+1].
 *    In terms of S, this means S[i-2] == '0' and S[i-1] == '1'.
 * 
 * Summary:
 * - Index 1 is a candidate if S[0] == '1'.
 * - Index N is a candidate if S[N-2] == '0'.
 * - Index i (1 < i < N) is a candidate if S[i-2] == '0' and S[i-1] == '1'.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 2) {
        // If S[0] == '0', A[1] < A[2], max is A[2]. If S[0] == '1', A[1] > A[2], max is A[1].
        // In both cases, exactly 1 element can be the maximum.
        cout << 1 << "\n";
        return;
    }

    int count = 0;

    // Check index 1
    if (S[0] == '1') {
        count++;
    }

    // Check indices 2 to N-1
    for (int i = 0; i < N - 2; ++i) {
        if (S[i] == '0' && S[i + 1] == '1') {
            count++;
        }
    }

    // Check index N
    if (S[N - 2] == '0') {
        count++;
    }

    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}