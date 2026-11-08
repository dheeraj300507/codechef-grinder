#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation P of length N such that:
 * 1. P[i] != i (1-indexed)
 * 2. P[i] % K == i % K
 * 
 * The condition P[i] % K == i % K implies that P[i] must belong to the same 
 * residue class modulo K as i.
 * For each residue r in {1, 2, ..., K} (where r = i % K, treating 0 as K),
 * we collect all indices i such that i % K == r.
 * Let this set of indices be S_r.
 * For any i in S_r, P[i] must also be in S_r.
 * Since we need P[i] != i, each set S_r must have at least 2 elements 
 * to allow a derangement within that set.
 * If any set S_r has only 1 element, it is impossible to satisfy P[i] != i,
 * because P[i] must be in S_r, and the only element in S_r is i itself.
 * 
 * If every set S_r has size >= 2, we can perform a cyclic shift on each set:
 * If S_r = {a_1, a_2, ..., a_m}, we can set P[a_1] = a_2, P[a_2] = a_3, ..., P[a_m] = a_1.
 * This ensures P[i] != i and P[i] % K == i % K.
 */

void solve() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> groups(K);
    for (int i = 1; i <= N; ++i) {
        groups[i % K].push_back(i);
    }

    // Check if any group has size 1
    for (int i = 0; i < K; ++i) {
        if (groups[i].size() == 1) {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> P(N + 1);
    for (int i = 0; i < K; ++i) {
        int sz = groups[i].size();
        if (sz == 0) continue;
        // Cyclic shift: P[groups[i][j]] = groups[i][(j + 1) % sz]
        for (int j = 0; j < sz; ++j) {
            P[groups[i][j]] = groups[i][(j + 1) % sz];
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << P[i] << (i == N ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}