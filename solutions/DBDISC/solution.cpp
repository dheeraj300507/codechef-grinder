#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to select exactly two items (i, j) where i != j.
 * Let the costs be A[i] and A[j].
 * Let the more expensive item be M = max(A[i], A[j]) and the cheaper be m = min(A[i], A[j]).
 * The discount on M is min(M / 2, 100).
 * The final cost is m + (M - min(M / 2, 100)).
 * We need to maximize B[i] + B[j] such that final cost <= K.
 * 
 * Constraints:
 * N <= 100, A_i, B_i, K <= 400.
 * An O(N^2) approach per test case is perfectly fine (100 * 100^2 = 1,000,000 operations).
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int max_tastiness = 0;
    bool possible = false;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int cost1 = A[i];
            int cost2 = A[j];
            
            int M = max(cost1, cost2);
            int m = min(cost1, cost2);
            
            int discount = min(M / 2, 100);
            int final_cost = m + (M - discount);
            
            if (final_cost <= K) {
                possible = true;
                max_tastiness = max(max_tastiness, B[i] + B[j]);
            }
        }
    }

    if (!possible) {
        cout << 0 << "\n";
    } else {
        cout << max_tastiness << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}