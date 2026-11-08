#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary array B of length N.
 * B_i = 1 if the frequency of element i in array A is odd.
 * B_i = 0 if the frequency of element i in array A is even.
 * 
 * Let f_i be the frequency of element i in array A.
 * The sum of frequencies must equal the total number of elements in A, which is N.
 * sum_{i=1}^N f_i = N
 * 
 * We know that f_i % 2 = B_i.
 * Therefore, f_i = 2 * k_i + B_i, where k_i >= 0.
 * Substituting this into the sum:
 * sum_{i=1}^N (2 * k_i + B_i) = N
 * 2 * sum_{i=1}^N k_i + sum_{i=1}^N B_i = N
 * 
 * Let S = sum_{i=1}^N B_i be the number of 1s in array B.
 * 2 * (sum k_i) = N - S
 * 
 * For a valid array A to exist, we need:
 * 1. N - S must be even (i.e., N and S must have the same parity).
 * 2. Since k_i >= 0, we need sum k_i >= 0, which implies N - S >= 0, or S <= N.
 *    Since S is the count of 1s in an array of length N, S <= N is always true.
 * 
 * Thus, the condition simplifies to: (N - S) % 2 == 0.
 * This is equivalent to saying N % 2 == S % 2.
 */

void solve() {
    int N;
    cin >> N;
    int S = 0;
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        if (b == 1) {
            S++;
        }
    }

    // Check if N and S have the same parity
    if ((N % 2) == (S % 2)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}