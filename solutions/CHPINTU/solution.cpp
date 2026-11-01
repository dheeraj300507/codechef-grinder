#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N baskets, each having a fruit type F_i and a price P_i.
 * We need to choose one fruit type (from 1 to M) such that we buy all baskets
 * containing that fruit type. We want to minimize the total cost.
 * 
 * Constraints:
 * N, M <= 50.
 * This allows an O(N + M) approach per test case.
 * We can maintain an array `total_cost` of size M+1 initialized to 0,
 * and a boolean array `exists` to track if a fruit type is present in any basket.
 */

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // total_cost[i] stores the sum of prices for fruit type i
    // exists[i] tracks if fruit type i is available in at least one basket
    vector<long long> total_cost(M + 1, 0);
    vector<bool> exists(M + 1, false);

    for (int i = 0; i < N; ++i) {
        total_cost[F[i]] += P[i];
        exists[F[i]] = true;
    }

    long long min_price = -1;

    for (int i = 1; i <= M; ++i) {
        if (exists[i]) {
            if (min_price == -1 || total_cost[i] < min_price) {
                min_price = total_cost[i];
            }
        }
    }

    cout << min_price << "\n";
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