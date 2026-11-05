#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's distance to the bottle: dist1 = |X3 - X1|
 * Kefa's distance to the bottle: dist2 = |X2 - X3|
 * Time taken by Chef: time1 = dist1 / V1
 * Time taken by Kefa: time2 = dist2 / V2
 * 
 * To compare time1 and time2 without floating point precision issues:
 * time1 < time2  <=> dist1 / V1 < dist2 / V2
 *                <=> dist1 * V2 < dist2 * V1
 * 
 * Given constraints:
 * X1 < X3 < X2, so dist1 = X3 - X1 and dist2 = X2 - X3.
 * All values are within 10^5, so products will be at most 10^10,
 * which fits in a 64-bit integer (long long).
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, x2, x3, v1, v2;
        cin >> x1 >> x2 >> x3 >> v1 >> v2;

        long long dist1 = x3 - x1;
        long long dist2 = x2 - x3;

        // Compare dist1/v1 and dist2/v2 using cross-multiplication
        // time1 = dist1 * v2
        // time2 = dist2 * v1
        long long time1_scaled = dist1 * v2;
        long long time2_scaled = dist2 * v1;

        if (time1_scaled < time2_scaled) {
            cout << "Chef" << "\n";
        } else if (time1_scaled > time2_scaled) {
            cout << "Kefa" << "\n";
        } else {
            cout << "Draw" << "\n";
        }
    }

    return 0;
}