#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tuzik has N coins and can choose between 1 and K people.
 * When he chooses 'i' people, the coins are divided equally among them.
 * The number of coins each person gets is floor(N / i).
 * The number of coins left for Tuzik is N % i.
 * We need to find the maximum value of (N % i) for all i in the range [1, K].
 * 
 * Constraints:
 * T <= 50
 * N, K <= 10^5
 * 
 * Complexity:
 * For each test case, we can iterate from 1 to K and calculate N % i.
 * Total complexity: O(T * K), which is 50 * 10^5 = 5 * 10^6 operations.
 * This is well within the 1s time limit.
 */

void solve() {
    long long N, K;
    if (!(cin >> N >> K)) return;

    long long max_coins = 0;
    
    // We want to maximize N % i for 1 <= i <= K
    for (long long i = 1; i <= K; ++i) {
        long long remainder = N % i;
        if (remainder > max_coins) {
            max_coins = remainder;
        }
    }
    
    cout << max_coins << "\n";
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