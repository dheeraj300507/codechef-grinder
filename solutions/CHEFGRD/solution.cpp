#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid is N x N where N is odd. The center is (C, C) where C = (N + 1) / 2.
 * Diagonal moves cost 0. Horizontal/Vertical moves cost 1.
 * 
 * Let the current position be (x, y) and the center be (C, C).
 * The distance in terms of parity:
 * A diagonal move changes both x and y by 1 (or -1).
 * Note that (x + y) changes by 2, 0, or -2.
 * Thus, the parity of (x + y) is invariant under diagonal moves.
 * 
 * If (x + y) has the same parity as (C + C), it means (x + y) and 2C have the same parity.
 * Since 2C is always even, this implies (x + y) must be even.
 * If (x + y) is even, the target (C, C) is reachable via diagonal moves (cost 0).
 * If (x + y) is odd, the target (C, C) is not reachable via diagonal moves alone.
 * One horizontal or vertical move will change the parity of (x + y), 
 * making it even, and then the target can be reached with 0 additional cost.
 * Thus, the cost is 1.
 * 
 * Summary:
 * If (x_s + y_s) % 2 == (C + C) % 2, cost is 0.
 * Otherwise, cost is 1.
 */

void solve() {
    long long N, xs, ys;
    if (!(cin >> N >> xs >> ys)) return;
    
    long long center = (N + 1) / 2;
    
    // Parity of center coordinates sum: (center + center) = 2 * center (always even)
    // Parity of current coordinates sum: (xs + ys)
    
    if ((xs + ys) % 2 == (center + center) % 2) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}