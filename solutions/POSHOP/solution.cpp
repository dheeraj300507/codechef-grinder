#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N items with costs C_1, C_2, ..., C_N.
 * We can buy at most two items.
 * If we buy one item, we can pick any item i.
 * If we buy two items i and j (where i < j), we must have C_i <= C_j.
 * We want to maximize the total cost.
 * 
 * Constraints: N <= 100, C_i <= 100.
 * Since N is small, we can iterate through all possible pairs (i, j) 
 * where 0 <= i < j < N and check the condition C_i <= C_j.
 * We also consider buying only one item (the maximum single item cost).
 * 
 * Time Complexity: O(N^2) per test case.
 * Space Complexity: O(N) to store the costs.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> C(N);
    int max_single = 0;
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        if (C[i] > max_single) {
            max_single = C[i];
        }
    }

    long long max_spent = max_single;

    // Check all pairs (i, j) such that i < j
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (C[i] <= C[j]) {
                long long current_sum = (long long)C[i] + C[j];
                if (current_sum > max_spent) {
                    max_spent = current_sum;
                }
            }
        }
    }

    cout << max_spent << "\n";
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