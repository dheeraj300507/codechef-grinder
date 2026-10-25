#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We must change exactly one element to minimize (max(A) - min(A)).
 * 
 * Let the sorted array be S_1, S_2, ..., S_N.
 * The current range is S_N - S_1.
 * 
 * To minimize the range by changing one element:
 * 1. We can change the minimum element (S_1) to be equal to S_2. The new range becomes S_N - S_2.
 * 2. We can change the maximum element (S_N) to be equal to S_{N-1}. The new range becomes S_{N-1} - S_1.
 * 
 * Since we want the minimum of these two possibilities, the answer is min(S_N - S_2, S_{N-1} - S_1).
 * 
 * Special case: If N=2, we can always make the two elements equal, resulting in a range of 0.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N <= 2) {
        cout << 0 << "\n";
        return;
    }

    sort(A.begin(), A.end());

    // Option 1: Change the smallest element to match the second smallest
    int range1 = A[N - 1] - A[1];
    
    // Option 2: Change the largest element to match the second largest
    int range2 = A[N - 2] - A[0];

    cout << min(range1, range2) << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}