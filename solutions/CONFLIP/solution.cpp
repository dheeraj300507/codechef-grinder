#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N coins. In round k (1 <= k <= N), we flip coins 1 to k.
 * Let's observe the state of coin i after N rounds.
 * Coin i is flipped in rounds k = i, i+1, ..., N.
 * The total number of times coin i is flipped is (N - i + 1).
 * 
 * If (N - i + 1) is even, the coin remains in its initial state.
 * If (N - i + 1) is odd, the coin changes its state.
 * 
 * Total coins = N.
 * Number of coins flipped an odd number of times = floor(N / 2).
 * Number of coins flipped an even number of times = ceil(N / 2).
 * 
 * Let I=1 be Head, I=2 be Tail.
 * If I=1 (all Heads):
 *   - Coins flipped odd times become Tails. Count = floor(N/2).
 *   - Coins flipped even times stay Heads. Count = ceil(N/2).
 * If I=2 (all Tails):
 *   - Coins flipped odd times become Heads. Count = floor(N/2).
 *   - Coins flipped even times stay Tails. Count = ceil(N/2).
 * 
 * If Q=1 (count Heads):
 *   - If I=1: Result is ceil(N/2).
 *   - If I=2: Result is floor(N/2).
 * If Q=2 (count Tails):
 *   - If I=1: Result is floor(N/2).
 *   - If I=2: Result is ceil(N/2).
 * 
 * Special case: If N is even, floor(N/2) == ceil(N/2) == N/2.
 */

void solve() {
    int G;
    cin >> G;
    while (G--) {
        long long I, N, Q;
        cin >> I >> N >> Q;

        long long heads, tails;
        if (N % 2 == 0) {
            heads = N / 2;
            tails = N / 2;
        } else {
            if (I == 1) {
                // Initial Heads
                // Odd flips (N/2 + 1 coins) -> Tails
                // Even flips (N/2 coins) -> Heads
                heads = N / 2;
                tails = N / 2 + 1;
            } else {
                // Initial Tails
                // Odd flips (N/2 + 1 coins) -> Heads
                // Even flips (N/2 coins) -> Tails
                heads = N / 2 + 1;
                tails = N / 2;
            }
        }

        if (Q == 1) {
            cout << heads << "\n";
        } else {
            cout << tails << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}