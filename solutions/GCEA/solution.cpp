#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each Pekómon with difficulty A_i, we have two choices:
 * 1. Use Normal Pekóballs: Cost = A_i * X
 * 2. Use a Master Pekóball: Cost = Y
 * 
 * To minimize the total cost, for each Pekómon, we should choose the minimum
 * of these two options: min(A_i * X, Y).
 * 
 * Total cost = sum_{i=1 to N} min(A_i * X, Y)
 * 
 * Constraints:
 * N, X, Y, A_i are all <= 100.
 * The maximum possible cost is 100 * 100 * 100 = 1,000,000, which fits in a standard 32-bit int.
 * However, using long long is safer and good practice in competitive programming.
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        // Cost to catch the i-th Pekómon is the minimum of using Normal or Master balls
        total_cost += min((long long)A[i] * X, Y);
    }
    
    cout << total_cost << "\n";
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