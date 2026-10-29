#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * We are given an initial sequence X and a transformed sequence Y.
 * We need to find if there exists a pivot index i (1 <= i <= N) such that
 * if we set P = X[i], the sorted list of pairs (|X[j] - P|, X[j])
 * results in the sequence Y.
 * 
 * Complexity:
 * For each test case:
 * - We try N possible pivots.
 * - For each pivot, we create N pairs and sort them: O(N log N).
 * - Total complexity: O(T * N^2 log N).
 * With N=100, T=100, this is ~10^6 operations, which is very efficient.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    vector<int> Y(N);
    for (int i = 0; i < N; ++i) cin >> Y[i];

    // Try every possible pivot index i (0-indexed internally)
    for (int i = 0; i < N; ++i) {
        int P = X[i];
        vector<pair<int, int>> L(N);
        for (int j = 0; j < N; ++j) {
            L[j] = {abs(X[j] - P), X[j]};
        }

        // Sort based on the problem definition:
        // (A, B) < (C, D) if A < C or (A == C and B < D)
        // std::sort uses lexicographical comparison for pairs by default,
        // which matches the problem requirements exactly.
        sort(L.begin(), L.end());

        // Check if the resulting sequence matches Y
        bool match = true;
        for (int k = 0; k < N; ++k) {
            if (L[k].second != Y[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    // Fast I/O to ensure we stay well within time limits
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}