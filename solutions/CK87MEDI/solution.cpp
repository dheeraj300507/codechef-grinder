#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of N elements and we need to add K elements.
 * The total number of elements will be M = N + K.
 * The median of an array of size M (where M is odd) is the element at index (M/2) 
 * in the sorted array (0-indexed).
 * 
 * To maximize the median, we want the element at index (M/2) to be as large as possible.
 * We have N existing elements and we can add K elements.
 * To make the median as large as possible, we should add K elements that are 
 * very large (effectively infinity).
 * 
 * If we add K very large elements, the sorted array will consist of the original N 
 * elements sorted, followed by the K large elements.
 * The new array size is N + K. The median index is (N + K) / 2.
 * 
 * Let's sort the original array A in non-decreasing order.
 * If we add K elements that are larger than any element in A, the new sorted array 
 * will be: A[0], A[1], ..., A[N-1], INF, INF, ..., INF (K times).
 * 
 * The median will be the element at index (N + K) / 2 in this combined sequence.
 * Since we want to maximize this, we should pick the K elements to be as large as 
 * possible so that they occupy the rightmost positions.
 * 
 * The index of the median is target = (N + K) / 2.
 * If target < N, the median is simply the element at A[target] after sorting A.
 * If target >= N, the median will be one of the K elements we added. Since we can 
 * choose these to be as large as we want, we can effectively make the median 
 * the largest element in the original array (or even larger, but the problem 
 * constraints on Ai suggest we just need to pick the largest available).
 * Actually, if we add K elements, the largest possible median is the largest 
 * element currently in the array, because we can't make the median larger than 
 * the existing maximum if we are forced to keep the original elements.
 * Wait, let's re-check: if we add K elements, we can make them all equal to 
 * the maximum element of the original array. Then the median will be the 
 * maximum element.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    // After adding K elements, the total size is N + K.
    // The median is at index (N + K) / 2.
    // To maximize the median, we add K elements that are larger than or equal to 
    // the current maximum.
    // The sorted array will look like: 
    // [A_0, A_1, ..., A_{N-1}, INF, ..., INF]
    // The element at index (N + K) / 2 will be:
    // If (N + K) / 2 < N, it is A[(N + K) / 2].
    // If (N + K) / 2 >= N, it is the largest element A[N-1].
    
    int target_idx = (N + K) / 2;
    if (target_idx < N) {
        cout << A[target_idx] << "\n";
    } else {
        cout << A[N - 1] << "\n";
    }
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