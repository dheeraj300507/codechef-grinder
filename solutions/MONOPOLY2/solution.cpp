#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A monopoly exists if any company's profit is strictly greater than the sum of the other three.
 * Let the profits be P, Q, R, S.
 * Total sum = P + Q + R + S.
 * For company A: P > (Q + R + S)
 * This is equivalent to: P > (Total - P)
 * Or: 2 * P > Total
 * We check this condition for all four companies.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p, q, r, s;
        cin >> p >> q >> r >> s;

        long long total = p + q + r + s;

        // Check if any company has a profit strictly greater than the sum of others
        // Condition: profit > (total - profit) => 2 * profit > total
        if ((2 * p > total) || (2 * q > total) || (2 * r > total) || (2 * s > total)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}