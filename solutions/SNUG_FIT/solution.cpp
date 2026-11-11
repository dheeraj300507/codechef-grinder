#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a rectangle with dimensions A_i x B_j, the diameter of the largest 
 * inscribed circle is min(A_i, B_j).
 * We want to maximize the sum of min(A_i, B_{P_i}) for all i=1 to N,
 * where P is a permutation of 1 to N.
 * 
 * By the Rearrangement Inequality (or simply greedy logic), to maximize the 
 * sum of minimums of pairs, we should sort both arrays A and B in non-decreasing 
 * order and pair them up: A_sorted[i] with B_sorted[i].
 * 
 * Proof sketch: If we have sorted arrays A and B, pairing A[i] with B[i] 
 * ensures that we are matching the smallest with the smallest, which 
 * maximizes the sum of the minimums.
 * 
 * Constraints:
 * N <= 10^4, A_i, B_i <= 10^9.
 * The sum can exceed 2^31 - 1, so we must use long long.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    // Sort both arrays to apply the greedy strategy
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        // The diameter of the inscribed circle is min(A[i], B[i])
        total_sum += min(A[i], B[i]);
    }
    
    cout << total_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}