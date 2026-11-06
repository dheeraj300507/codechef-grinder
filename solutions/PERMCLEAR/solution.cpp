#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a permutation A of length N and a set of K numbers B.
 * We need to remove all elements present in B from A while maintaining the relative order.
 * 
 * Optimal Approach:
 * 1. Use a boolean array (or a hash set) to mark all elements present in B.
 *    Since 1 <= B_i <= N, a boolean array of size N+1 is efficient (O(1) lookup).
 * 2. Iterate through the original array A.
 * 3. If the current element A[i] is not marked in the boolean array, print it.
 * 
 * Complexity:
 * - Time Complexity: O(N) per test case, where N is the length of the array.
 *   Sum of N over all test cases is 2*10^5, which fits well within the 2.5s limit.
 * - Space Complexity: O(N) to store the boolean array and the input array.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int K;
    cin >> K;
    
    // Using a boolean vector to keep track of elements to be removed.
    // Size N+1 because elements are 1-indexed up to N.
    vector<bool> to_remove(N + 1, false);
    for (int i = 0; i < K; ++i) {
        int b;
        cin >> b;
        to_remove[b] = true;
    }
    
    bool first = true;
    for (int i = 0; i < N; ++i) {
        if (!to_remove[A[i]]) {
            if (!first) {
                cout << " ";
            }
            cout << A[i];
            first = false;
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}