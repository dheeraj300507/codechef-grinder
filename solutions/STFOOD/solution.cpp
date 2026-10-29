#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each food type i, there are S_i stores already present.
 * Chef opens a new store, so the total number of stores becomes (S_i + 1).
 * The number of people P_i is distributed among (S_i + 1) stores.
 * The number of people who buy from Chef's new store is floor(P_i / (S_i + 1)).
 * The profit for food type i is: floor(P_i / (S_i + 1)) * V_i.
 * We need to find the maximum profit among all N types.
 * 
 * Constraints:
 * T <= 100, N <= 100, S_i, P_i, V_i <= 10,000.
 * Max profit per type = (10,000 / 1) * 10,000 = 100,000,000.
 * This fits within a standard 32-bit signed integer, but using long long is safer.
 */

void solve() {
    int N;
    cin >> N;
    
    long long max_profit = 0;
    
    for (int i = 0; i < N; ++i) {
        long long S, P, V;
        cin >> S >> P >> V;
        
        // Chef opens a new store, so total stores = S + 1
        // Number of people per store = floor(P / (S + 1))
        long long people_per_store = P / (S + 1);
        long long current_profit = people_per_store * V;
        
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
    }
    
    cout << max_profit << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}