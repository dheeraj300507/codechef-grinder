#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts at X and wants to reach Y.
 * Moves:
 * 1. k -> k + 2
 * 2. k -> k - 1
 * 
 * Let 'a' be the number of moonwalks (+2) and 'b' be the number of slides (-1).
 * We want to reach Y from X: X + 2a - b = Y
 * 2a - b = Y - X
 * Let D = Y - X.
 * If D <= 0:
 *   We only need to use slides. Since each slide is -1, we need |D| moves.
 * If D > 0:
 *   We want to minimize a + b subject to 2a - b = D, where a, b >= 0.
 *   From the equation, b = 2a - D.
 *   Since b >= 0, 2a >= D => a >= D/2.
 *   To minimize a + b = a + (2a - D) = 3a - D, we should pick the smallest possible 'a'.
 *   If D is even, let a = D/2. Then b = 0. Total moves = D/2.
 *   If D is odd, let a = (D+1)/2. Then b = 2((D+1)/2) - D = D + 1 - D = 1.
 *   Total moves = (D+1)/2 + 1 = (D+3)/2.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (X >= Y) {
        cout << (X - Y) << "\n";
    } else {
        long long D = Y - X;
        if (D % 2 == 0) {
            cout << (D / 2) << "\n";
        } else {
            cout << (D / 2 + 2) << "\n";
        }
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