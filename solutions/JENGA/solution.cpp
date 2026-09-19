#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N people and X tiles.
 * In each round, every person takes 1 tile.
 * This means in one round, N tiles are consumed.
 * For the game to be valid:
 * 1. All tiles must be used (X must be divisible by N).
 * 2. All players must have a tile in each round (X must be >= N).
 * 
 * Combining these, the condition is simply:
 * (X % N == 0)
 * 
 * Constraints:
 * 1 <= T <= 10^4
 * 1 <= N, X <= 1000
 * Since N and X are small, standard integer types are sufficient.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x;
        cin >> n >> x;

        // The game is valid if the total number of tiles X is a multiple of N.
        // If X % N == 0, it implies X = k * N for some integer k >= 1.
        // This satisfies both conditions:
        // 1. All tiles are used (X / N rounds).
        // 2. Each round uses exactly N tiles, so everyone gets one.
        if (x % n == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}