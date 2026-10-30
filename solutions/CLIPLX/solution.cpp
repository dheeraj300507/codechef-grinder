#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the minimum number of wins (w) such that:
 * 2*w + t = X
 * w + t + l = Y
 * where w, t, l >= 0.
 * 
 * Substituting t = X - 2*w into the inequality w + t <= Y:
 * w + (X - 2*w) <= Y
 * X - w <= Y
 * w >= X - Y
 * 
 * Since w must also be non-negative, w >= max(0, X - Y).
 * The constraints are small (X, Y <= 100), so this O(1) calculation per test case is optimal.
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;
    
    // If X <= Y, we can achieve X points using only ties (t=X, w=0).
    // If X > Y, we must win at least (X - Y) matches to reach the target.
    if (X <= Y) {
        cout << 0 << "\n";
    } else {
        cout << (X - Y) << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}