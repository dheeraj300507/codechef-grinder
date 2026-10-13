#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N cars with initial prices P_i.
 * Each year, the price of every unsold car decreases by 1 (minimum 0).
 * To maximize profit, we should sell the most expensive cars as early as possible.
 * 
 * Strategy:
 * 1. Sort the car prices in descending order.
 * 2. In year 0, sell the most expensive car (price P_0).
 * 3. In year 1, sell the next most expensive car. Its price will be max(0, P_1 - 1).
 * 4. In year i, sell the car at index i. Its price will be max(0, P_i - i).
 * 5. Sum these values modulo 1,000,000,007.
 * 
 * Complexity:
 * Time: O(N log N) due to sorting.
 * Space: O(N) to store the prices.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Sort in descending order to sell the most expensive cars first
    sort(P.begin(), P.end(), greater<long long>());

    long long total_profit = 0;
    long long MOD = 1000000007;

    for (int i = 0; i < N; ++i) {
        // Price of the car at year i is max(0, P[i] - i)
        long long current_price = P[i] - i;
        if (current_price > 0) {
            total_profit = (total_profit + current_price) % MOD;
        }
    }

    cout << total_profit << "\n";
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