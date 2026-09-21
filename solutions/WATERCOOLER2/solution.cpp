#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum integer M such that:
 * M * X < Y
 * 
 * Rearranging the inequality:
 * M < Y / X
 * 
 * Since M must be an integer, M = floor((Y - 1) / X).
 * 
 * If Y <= X, then even for M = 1, M * X >= Y.
 * In this case, the condition "strictly less" cannot be satisfied for any M >= 1,
 * so the answer is 0.
 * 
 * Constraints:
 * X, Y up to 10^9. Calculations fit in long long.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // If renting for 1 month is already >= purchasing, answer is 0.
        if (x >= y) {
            cout << 0 << "\n";
        } else {
            // We want max M such that M * X < Y.
            // This is equivalent to M = (Y - 1) / X using integer division.
            // Since we already checked x >= y, we know y > x, so y-1 >= x.
            long long ans = (y - 1) / x;
            cout << ans << "\n";
        }
    }

    return 0;
}