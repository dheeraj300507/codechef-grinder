#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Nitin starts with A coins, Sobhagya with B coins.
 * Winning condition: Sobhagya wins if B > A, otherwise Nitin wins (A >= B).
 * 
 * Step 1: Ritik gives C coins to the player who is not winning.
 * Step 2: Satyarth gives D coins to the player who is not winning.
 * 
 * We simulate these two steps sequentially.
 * Since A, B, C, D <= 10^6, the values will not exceed 2*10^6 + 10^6 = 3*10^6,
 * which fits comfortably within a standard 32-bit integer, but we use long long
 * to be safe and follow best practices.
 */

void solve() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    // First step: Ritik gives C coins
    if (B > A) {
        // Sobhagya is winning, so Nitin gets C
        A += C;
    } else {
        // Nitin is winning, so Sobhagya gets C
        B += C;
    }

    // Second step: Satyarth gives D coins
    if (B > A) {
        // Sobhagya is winning, so Nitin gets D
        A += D;
    } else {
        // Nitin is winning, so Sobhagya gets D
        B += D;
    }

    // Final check
    if (B > A) {
        cout << "S" << "\n";
    } else {
        cout << "N" << "\n";
    }
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