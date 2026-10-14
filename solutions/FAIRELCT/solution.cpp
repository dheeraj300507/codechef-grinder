#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * We want to minimize the number of swaps.
 * To maximize John's total votes while minimizing swaps, we should always swap
 * the smallest pack from A with the largest pack from B, provided the smallest
 * pack from A is smaller than the largest pack from B.
 * 
 * Strategy:
 * 1. Calculate current sum of A and B.
 * 2. If sumA > sumB, 0 swaps needed.
 * 3. Sort A in ascending order and B in descending order.
 * 4. Iterate through the sorted arrays, swapping A[i] and B[i] as long as
 *    sumA <= sumB and A[i] < B[i].
 * 5. If after all possible beneficial swaps sumA is still <= sumB, return -1.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int swaps = 0;
    int i = 0;
    while (sumA <= sumB) {
        // If we run out of elements to swap or the smallest A is not smaller than largest B
        if (i >= N || i >= M || A[i] >= B[i]) {
            cout << -1 << "\n";
            return;
        }
        
        // Perform swap
        sumA = sumA - A[i] + B[i];
        sumB = sumB - B[i] + A[i];
        swaps++;
        i++;
    }

    cout << swaps << "\n";
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