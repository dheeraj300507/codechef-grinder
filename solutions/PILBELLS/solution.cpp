#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial mana: P
 * First X bells: +10 each
 * Remaining bells: +5 each
 * If K == N: +20 bonus
 * 
 * Logic:
 * 1. Start with mana = P.
 * 2. If K <= X:
 *    mana += K * 10
 * 3. If K > X:
 *    mana += (X * 10) + ((K - X) * 5)
 * 4. If K == N:
 *    mana += 20
 * 
 * Constraints:
 * N, X, P <= 10^5. Max mana will be around 10^5 + 10^5*10 + 20, 
 * which fits in a standard 32-bit integer, but using long long is safer.
 */

void solve() {
    long long N, X, K, P;
    cin >> N >> X >> K >> P;

    long long current_mana = P;

    if (K <= X) {
        current_mana += (K * 10);
    } else {
        // First X bells give 10 each
        current_mana += (X * 10);
        // Remaining (K - X) bells give 5 each
        current_mana += ((K - X) * 5);
    }

    // Bonus for ringing all bells
    if (K == N) {
        current_mana += 20;
    }

    cout << current_mana << "\n";
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