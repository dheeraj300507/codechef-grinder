#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N days with sales A_1, A_2, ..., A_N.
 * If Chef closes the shop on day k (1 <= k <= N), the total sales will be:
 * Total = (A_1 + A_2 + ... + A_{k-1}) + (2 * A_k)
 * Total = (A_1 + A_2 + ... + A_k) + A_k
 * 
 * Let S_k be the prefix sum of the first k days: S_k = A_1 + A_2 + ... + A_k.
 * Then the total sales if closed on day k is S_k + A_k.
 * We need to maximize (S_k + A_k) for 1 <= k <= N.
 * 
 * Constraints:
 * N <= 3*10^5, sum of N <= 3*10^5.
 * A_i <= 10^9.
 * The result can exceed 2^31 - 1, so we must use long long.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    long long current_prefix_sum = 0;
    long long max_sales = -1; // Since A_i >= 1, max_sales will be at least 2
    
    for (int i = 0; i < n; ++i) {
        current_prefix_sum += a[i];
        long long current_total = current_prefix_sum + a[i];
        if (current_total > max_sales) {
            max_sales = current_total;
        }
    }
    
    cout << max_sales << "\n";
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