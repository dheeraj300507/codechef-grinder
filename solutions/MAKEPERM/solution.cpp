#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We need to find if there exists an array B 
 * of non-negative integers such that C_i = A_i + B_i forms a permutation of 1 to N.
 * 
 * Since B_i >= 0, it implies C_i >= A_i.
 * For C to be a permutation of 1 to N, every value from 1 to N must appear exactly once.
 * 
 * Let's sort the array A in non-decreasing order.
 * If we sort A, we have A_1 <= A_2 <= ... <= A_N.
 * To make C a permutation, we need to map these A_i values to the set {1, 2, ..., N}
 * such that A_i <= C_i.
 * 
 * If we sort A, the condition A_i <= C_i is most easily satisfied if we match
 * the sorted A_i with the sorted permutation values (1, 2, ..., N).
 * Specifically, if we sort A, we must have A_i <= i for all i (using 1-based indexing).
 * If for any i, A_i > i, then even if we pick the smallest available values for C,
 * we will be forced to pick a value smaller than A_i, which is impossible since B_i >= 0.
 * 
 * Thus, the condition is: Sort A, and check if A[i] <= i+1 for all i from 0 to N-1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        // After sorting, A[i] is the (i+1)-th smallest element.
        // It must be able to reach at least the value (i+1) in the permutation.
        // Since B_i >= 0, A[i] + B_i >= A[i].
        // So we need A[i] <= i + 1.
        if (A[i] > (i + 1)) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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