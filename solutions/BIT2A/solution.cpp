#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Given a sorted array A, for each A[i], we need the count of elements > A[i].
 * Since the array is sorted, all elements strictly greater than A[i] will 
 * appear after the last occurrence of A[i].
 * 
 * Complexity:
 * O(N) per test case using a simple loop or O(N log N) using upper_bound.
 * Given N <= 100, both are extremely fast.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // Find the first element strictly greater than A[i]
        // upper_bound returns an iterator to the first element > A[i]
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        
        // The number of elements strictly greater is the distance from 'it' to the end
        int count = (int)distance(it, A.end());
        
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}