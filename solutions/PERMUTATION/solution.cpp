#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to transform array A into a permutation of {1, 2, ..., N} using only increments.
 * 1. Sort the array A.
 * 2. The smallest element must eventually become 1, the second smallest 2, ..., the N-th smallest N.
 * 3. If any element A[i] is already greater than its target (i + 1), it's impossible.
 * 4. Otherwise, the cost is the sum of (target - A[i]).
 * 
 * Complexity: O(T * N log N), which is efficient enough for N=1000, T=500.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to match the smallest elements to the smallest targets
    sort(A.begin(), A.end());

    long long operations = 0;
    for (int i = 0; i < N; ++i) {
        int target = i + 1;
        
        // If the current element is already greater than the target,
        // we cannot decrease it to reach the target.
        if (A[i] > target) {
            cout << -1 << "\n";
            return;
        }
        
        // Add the difference to operations
        operations += (long long)(target - A[i]);
    }

    cout << operations << "\n";
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}