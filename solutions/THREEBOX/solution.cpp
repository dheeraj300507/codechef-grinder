#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three boxes A, B, C and bags of size D.
 * Constraints: 1 <= A <= B <= C <= D <= 100.
 * 
 * Logic:
 * 1. If A + B + C <= D, we can fit all in 1 bag.
 * 2. If A + B + C > D, we check if we can fit two boxes in one bag.
 *    Since A <= B <= C, the largest possible pairs are (A+B) and C, or (A+C) and B.
 *    However, since A <= B <= C, the most efficient way to group is to check:
 *    - If A + B + C <= D: 1 bag
 *    - Else if A + B <= D or A + C <= D: 2 bags
 *    - Else: 3 bags
 * 
 * Actually, a simpler greedy approach:
 * - If (A + B + C <= D), return 1.
 * - If (A + B <= D) or (A + C <= D), return 2.
 * - Otherwise, return 3.
 */

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (A + B + C <= D) {
        cout << 1 << "\n";
    } else if (A + B <= D || A + C <= D) {
        // We can fit at least two in one bag
        cout << 2 << "\n";
    } else {
        // Must put each in its own bag
        cout << 3 << "\n";
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