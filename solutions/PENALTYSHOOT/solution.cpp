#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Team A has 3 turns completed, 2 turns remaining.
 * Team B has 4 turns completed, 1 turn remaining.
 * 
 * Team A's final score will be in the range [X, X + 2].
 * Team B's final score will be in the range [Y, Y + 1].
 * 
 * A draw is possible if there exists a score S such that:
 * X <= S <= X + 2 AND Y <= S <= Y + 1.
 * This is equivalent to checking if the intersection of [X, X+2] 
 * and [Y, Y+1] is non-empty.
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;

    int min_A = X;
    int max_A = X + 2;
    int min_B = Y;
    int max_B = Y + 1;

    // Two intervals [L1, R1] and [L2, R2] intersect if 
    // max(L1, L2) <= min(R1, R2)
    if (max(min_A, min_B) <= min(max_A, max_B)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}