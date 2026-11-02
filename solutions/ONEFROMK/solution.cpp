#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a fixed K, we have elements A_1, ..., A_{K-1} in the bucket initially.
 * Then for i = K to N, we add A_i to the bucket and pick one element to remove.
 * Total elements picked = (K-1) + (N - K + 1) = N.
 * Actually, let's re-read:
 * Initially bucket has A_1, ..., A_{K-1}.
 * For i = K to N:
 *   Add A_i.
 *   Pick one and remove.
 * Total elements picked = N - K + 1.
 * The elements available to be picked are {A_1, ..., A_N}.
 * Specifically, at any step i, we can pick any element currently in the bucket.
 * Since we want to maximize the sum, we should always pick the largest available elements.
 * 
 * For a fixed K, we have N - K + 1 slots to pick elements.
 * The elements A_1, ..., A_{K-1} are available from the start.
 * The elements A_K, ..., A_N become available one by one.
 * This is equivalent to saying we can pick any N - K + 1 elements from the set {A_1, ..., A_N}
 * such that the constraint of "availability" is satisfied.
 * However, notice that for any K, we can always pick the N - K + 1 largest elements
 * from the entire array A.
 * Why? Because if we want to pick a set of elements S where |S| = N - K + 1,
 * we can always pick them as long as we don't "run out" of elements.
 * The condition is simply that we must pick the N - K + 1 largest elements of the array.
 * Let the sorted array be S_1 <= S_2 <= ... <= S_N.
 * For a given K, the number of elements to pick is M = N - K + 1.
 * The maximum score is the sum of the M largest elements, which is sum(S_{N-M+1} ... S_N).
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to easily pick the largest elements
    sort(A.begin(), A.end());

    // Precompute suffix sums
    // suffix_sum[i] = sum of A[i...N-1]
    vector<long long> suffix_sum(N + 1, 0);
    for (int i = N - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + A[i];
    }

    // For each K from 1 to N:
    // Number of elements to pick is M = N - K + 1
    // We need the sum of the largest M elements.
    // These are A[N-M ... N-1]
    // Which is suffix_sum[N-M]
    for (int K = 1; K <= N; ++K) {
        int M = N - K + 1;
        cout << suffix_sum[N - M] << (K == N ? "" : " ");
    }
    cout << "\n";
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