#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with all fences colored 1.
 * We want the final state to be A_1, A_2, ..., A_N.
 * 
 * Strategy:
 * 1. We can perform a global color operation (all fences to color X).
 * 2. We can perform individual color operations (fence i to color X).
 * 
 * If we perform a global operation with color X, all fences become X.
 * Then, for every fence i where A_i != X, we need an individual operation.
 * The cost would be 1 (global) + (count of i where A_i != X).
 * 
 * If we perform NO global operation, we start with all fences as 1.
 * We only need to change fences where A_i != 1.
 * The cost would be (count of i where A_i != 1).
 * 
 * We should check:
 * Option 0: No global operation. Cost = count(A_i != 1).
 * Option X: Global operation with color X. Cost = 1 + count(A_i != X).
 * 
 * We want to minimize this over all possible X in {1, ..., N}.
 * Note: If we choose X = 1, the cost is 1 + count(A_i != 1). 
 * This is always worse than Option 0 (count(A_i != 1)).
 * So we only need to check Option 0 and Option X for X in {1, ..., N}.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
    }

    // Option 0: No global operation
    // Cost is the number of fences that are not already 1.
    int cost0 = N - counts[1];
    
    // Option X: Global operation with color X
    // Cost is 1 + (N - count of fences that are already X)
    int min_cost = cost0;
    
    for (auto const& [color, count] : counts) {
        if (color == 1) continue;
        int current_cost = 1 + (N - count);
        if (current_cost < min_cost) {
            min_cost = current_cost;
        }
    }
    
    cout << min_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}