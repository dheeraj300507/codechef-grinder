#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The degree of a polynomial is the highest power of x whose coefficient is non-zero.
 * We are given N coefficients A_0, A_1, ..., A_{N-1} corresponding to x^0, x^1, ..., x^{N-1}.
 * We need to find the largest index i such that A_i != 0.
 * 
 * Constraints:
 * T <= 100, N <= 1000.
 * Time complexity per test case: O(N).
 * Total time complexity: O(T * N), which is well within the 1s limit.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int degree = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // If the current coefficient is non-zero, update the degree.
        // Since we iterate from 0 to N-1, the last index i that satisfies 
        // A[i] != 0 will be the highest power.
        if (A[i] != 0) {
            degree = i;
        }
    }
    cout << degree << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}