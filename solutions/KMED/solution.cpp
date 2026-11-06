#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size N. We must delete K elements, leaving M = N - K elements.
 * The median is defined as the ceil(M/2)-th smallest element.
 * Let M = N - K. The index of the median in a sorted version of the remaining array
 * (using 1-based indexing) is m_idx = ceil(M / 2.0).
 * 
 * If we sort the original array A such that A[0] <= A[1] <= ... <= A[N-1],
 * we want to pick m_idx elements from the left side of the chosen median and 
 * (M - m_idx) elements from the right side.
 * 
 * To make A[i] the median:
 * 1. We need at least (m_idx - 1) elements smaller than or equal to A[i] 
 *    available in the array (excluding A[i] itself).
 * 2. We need at least (M - m_idx) elements larger than or equal to A[i] 
 *    available in the array (excluding A[i] itself).
 * 
 * Let the sorted array be S.
 * If we pick S[i] as the median:
 * - We need to be able to pick (m_idx - 1) elements from indices 0 to i-1.
 *   This is possible if i >= (m_idx - 1).
 * - We need to be able to pick (M - m_idx) elements from indices i+1 to N-1.
 *   This is possible if (N - 1 - i) >= (M - m_idx).
 * 
 * Constraints: N <= 100. An O(N^2) or O(N log N) approach is perfectly fine.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int M = N - K;
    int m_idx = (M + 1) / 2; // 1-based index of median
    
    // We need to pick (m_idx - 1) elements from the left of the median
    // and (M - m_idx) elements from the right of the median.
    // If we choose A[i] as the median, we must have:
    // i >= (m_idx - 1)  [enough elements to the left]
    // (N - 1 - i) >= (M - m_idx) [enough elements to the right]
    
    set<long long> possible_medians;
    for (int i = 0; i < N; ++i) {
        if (i >= (m_idx - 1) && (N - 1 - i) >= (M - m_idx)) {
            possible_medians.insert(A[i]);
        }
    }

    bool first = true;
    for (long long val : possible_medians) {
        if (!first) cout << " ";
        cout << val;
        first = false;
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