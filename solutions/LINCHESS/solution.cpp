#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at position K. A player at position P_i can capture Chef if K is a multiple of P_i.
 * That is, K % P_i == 0.
 * If this condition is met, the number of moves required is K / P_i.
 * We want to minimize the number of moves, which is equivalent to maximizing P_i 
 * among all P_i that satisfy K % P_i == 0.
 * 
 * Constraints:
 * T <= 100, N <= 1000, K <= 10^9, P_i <= 10^9.
 * An O(N) approach per test case is well within the time limit (100 * 1000 = 10^5 operations).
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;

    long long best_p = -1;
    long long min_moves = -1;

    for (int i = 0; i < N; ++i) {
        long long p;
        cin >> p;

        // Check if player can reach K
        if (K % p == 0) {
            long long moves = K / p;
            // We want the smallest number of moves.
            // If we haven't found a player yet, or this player is faster:
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
                best_p = p;
            }
        }
    }

    cout << best_p << "\n";
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