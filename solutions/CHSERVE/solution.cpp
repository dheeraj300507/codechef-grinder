#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points scored is S = P1 + P2.
 * The serve changes every K points.
 * 
 * - Points 0 to K-1: Chef serves (0 // K = 0)
 * - Points K to 2K-1: Cook serves (1 // K = 0)
 * - Points 2K to 3K-1: Chef serves (2 // K = 0)
 * 
 * The number of times the serve has changed is (P1 + P2) / K.
 * If this value is even, it is Chef's turn.
 * If this value is odd, it is Cook's turn.
 * 
 * Constraints:
 * P1, P2, K up to 10^9.
 * P1 + P2 can be up to 2 * 10^9, which fits in a standard 32-bit signed integer,
 * but using long long is safer and good practice for competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;

        long long total_points = p1 + p2;
        long long serve_cycles = total_points / k;

        if (serve_cycles % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }

    return 0;
}