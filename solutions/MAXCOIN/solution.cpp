#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * Chef wins X games and loses N-X games.
 * To maximize the total coins, Chef should win the games with the largest 
 * indices (N, N-1, ..., N-X+1) and lose the games with the smallest 
 * indices (1, 2, ..., N-X).
 * 
 * Total = (Sum of 2^i for i from N-X+1 to N) - (Sum of 2^i for i from 1 to N-X)
 * 
 * Using the formula for geometric series: sum_{i=1}^k 2^i = 2^{k+1} - 2
 */

void solve() {
    int N, X;
    if (!(cin >> N >> X)) return;

    long long total_coins = 0;

    // Chef wins games from N-X+1 to N
    // Chef loses games from 1 to N-X
    for (int i = 1; i <= N; ++i) {
        if (i > N - X) {
            total_coins += (1LL << i);
        } else {
            total_coins -= (1LL << i);
        }
    }

    cout << total_coins << "\n";
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