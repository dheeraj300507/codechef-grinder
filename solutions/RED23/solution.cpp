#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two operations:
 * 1. If X > 3, X = X - 3
 * 2. If X is even, X = X / 2
 * 
 * Since the constraints are small (X <= 100), we can use Breadth-First Search (BFS)
 * or simply observe the reachable states.
 * 
 * For any X:
 * - If X is even, we can reach X/2.
 * - If X > 3, we can reach X-3.
 * 
 * Let's trace small values:
 * 1: Cannot move. Min = 1.
 * 2: 2/2 = 1. Min = 1.
 * 3: Cannot move. Min = 3.
 * 4: 4-3 = 1, 4/2 = 2 -> 1. Min = 1.
 * 5: 5-3 = 2 -> 1. Min = 1.
 * 6: 6/2 = 3, 6-3 = 3. Min = 3.
 * 7: 7-3 = 4 -> 1. Min = 1.
 * 8: 8/2 = 4 -> 1. Min = 1.
 * 9: 9-3 = 6 -> 3. Min = 3.
 * 
 * Pattern:
 * If X is a multiple of 3, the minimum value is 3.
 * If X is not a multiple of 3, the minimum value is 1.
 * Exception: X=3 is a multiple of 3 and stays 3. 
 * X=6 is a multiple of 3, becomes 3.
 * X=1 is not a multiple of 3, stays 1.
 * 
 * The logic holds: if X % 3 == 0, the answer is 3. Otherwise, it is 1.
 */

void solve() {
    int X;
    cin >> X;
    if (X % 3 == 0) {
        cout << 3 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}