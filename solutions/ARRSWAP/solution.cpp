#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two arrays A and B of size N. We can swap any element of A with any element of B.
 * Effectively, this means we can choose any subset of size N from the combined 2N elements
 * to form the new array A.
 * 
 * To minimize (max(A) - min(A)), we should sort the combined 2N elements.
 * Let the sorted combined array be C. Any subarray of length N in C, i.e.,
 * C[i], C[i+1], ..., C[i+N-1] for 0 <= i <= N, represents a possible set of 
 * elements for array A.
 * 
 * The range of this subset is C[i+N-1] - C[i].
 * We need to find the minimum value of (C[i+N-1] - C[i]) for all 0 <= i <= N.
 * 
 * Time Complexity: O(N log N) due to sorting.
 * Space Complexity: O(N) to store the combined array.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> combined(2 * N);
    for (int i = 0; i < N; ++i) {
        cin >> combined[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> combined[i + N];
    }

    sort(combined.begin(), combined.end());

    long long min_diff = -1;

    // We look at all windows of size N in the sorted combined array
    // The possible windows start at index i and end at index i + N - 1
    // i ranges from 0 to N
    for (int i = 0; i <= N; ++i) {
        long long current_diff = combined[i + N - 1] - combined[i];
        if (min_diff == -1 || current_diff < min_diff) {
            min_diff = current_diff;
        }
    }

    cout << min_diff << "\n";
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