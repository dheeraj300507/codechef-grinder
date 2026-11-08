#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the MEX of an array of length N, the best we can achieve is a MEX of N.
 * This happens if the array contains all integers from 0 to N-1.
 * 
 * Strategy:
 * 1. Sort the input array A in non-decreasing order.
 * 2. To minimize the total operations to transform A into the set {0, 1, 2, ..., N-1},
 *    we should map the smallest element of A to 0, the second smallest to 1, and so on.
 *    This is because if we have sorted arrays A and B, the sum of |A[i] - B[i]| 
 *    is minimized when both are sorted.
 * 3. The target array is {0, 1, 2, ..., N-1}.
 * 4. The total operations required will be the sum of |A[i] - i| for i from 0 to N-1.
 * 
 * Complexity:
 * Time: O(N log N) due to sorting.
 * Space: O(N) to store the array.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to greedily match the smallest elements to 0, 1, ..., N-1
    sort(A.begin(), A.end());
    
    long long operations = 0;
    for (int i = 0; i < N; ++i) {
        // We want to transform A[i] to i
        operations += abs(A[i] - i);
    }
    
    cout << operations << "\n";
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