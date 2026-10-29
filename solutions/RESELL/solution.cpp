#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N items with resale values A_i.
 * The first K items bought cost 5 coins each.
 * Any subsequent items bought cost 10 coins each.
 * Profit for an item = (Resale Value) - (Cost).
 * 
 * To maximize profit:
 * 1. We should only buy items where the profit is positive.
 * 2. We want to assign the cheapest costs (5 coins) to the items with the highest resale values.
 * 3. Sort the resale values in descending order.
 * 4. For the first K items in the sorted list, profit = max(0, A_i - 5).
 * 5. For the remaining items, profit = max(0, A_i - 10).
 * 6. Sum these up to get the maximum profit.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to prioritize higher resale values
    sort(A.rbegin(), A.rend());

    long long total_profit = 0;
    for (int i = 0; i < N; ++i) {
        if (i < K) {
            // First K items cost 5
            if (A[i] > 5) {
                total_profit += (A[i] - 5);
            }
        } else {
            // Remaining items cost 10
            if (A[i] > 10) {
                total_profit += (A[i] - 10);
            }
        }
    }

    cout << total_profit << "\n";
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