#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X, Y, Z. We want to check if they form an AP: Y - X = Z - Y,
 * which is equivalent to 2*Y = X + Z.
 * 
 * Possible outcomes:
 * 0 operations: If 2*Y == X + Z, it is already an AP.
 * 1 operation: 
 *    - Change X: We need X = 2*Y - Z. Since we can change X to any integer, 
 *      this is always possible in 1 move.
 *    - Change Y: We need Y = (X + Z) / 2. If (X + Z) is even, we can change Y 
 *      to (X + Z) / 2 in 1 move.
 *    - Change Z: We need Z = 2*Y - X. Since we can change Z to any integer, 
 *      this is always possible in 1 move.
 * 
 * Therefore:
 * - If 2*Y == X + Z, answer is 0.
 * - Else if (X + Z) % 2 == 0, answer is 1 (we can change Y to (X+Z)/2).
 * - Else, answer is 1 (we can change X or Z to satisfy the condition).
 * 
 * Wait, let's re-verify:
 * If 2*Y == X + Z, 0 moves.
 * If 2*Y != X + Z, can we always do it in 1 move?
 * Yes. We can change X to (2*Y - Z), or change Z to (2*Y - X).
 * So the answer is either 0 or 1.
 */

void solve() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;

    if (2 * Y == X + Z) {
        cout << 0 << "\n";
    } else {
        // We can always change one of the numbers to make it an AP.
        // For example, change X to (2*Y - Z).
        cout << 1 << "\n";
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