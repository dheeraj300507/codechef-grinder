#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with the set S = {1, 2, ..., N}.
 * We want to reach a subset Q. This means we need to remove all elements in {1, ..., N} \ Q.
 * The operation: Choose k, remove the smallest multiple of k currently in S. Cost = k.
 * 
 * Key insight:
 * If we want to remove an element x, we can choose k = x. The smallest multiple of x 
 * currently in S is x itself (provided x hasn't been removed yet).
 * If we remove all elements in {1, ..., N} \ Q by choosing k = x for each x in the 
 * set to be removed, the total cost is the sum of all elements in {1, ..., N} \ Q.
 * 
 * Is this the maximum cost?
 * Yes. For any element x that needs to be removed, we can always choose k = x 
 * to remove it, provided x is still in the set. Since we want to remove all 
 * elements in {1, ..., N} \ Q, and the cost of removing x is x, the total cost 
 * is simply the sum of all integers from 1 to N minus the sum of elements in Q.
 * 
 * Sum of 1 to N = N * (N + 1) / 2.
 * Total cost = (N * (N + 1) / 2) - sum(elements in Q).
 */

void solve() {
    long long N;
    int M;
    if (!(cin >> N >> M)) return;
    
    long long sum_Q = 0;
    for (int i = 0; i < M; ++i) {
        long long val;
        cin >> val;
        sum_Q += val;
    }
    
    long long total_sum = N * (N + 1) / 2;
    long long result = total_sum - sum_Q;
    
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}