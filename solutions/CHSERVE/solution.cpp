#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points scored is S = P1 + P2.
 * The serve changes every K points.
 * - Points 0 to K-1: Chef serves (0 // K = 0)
 * - Points K to 2K-1: Cook serves (1 // K = 0, but wait, let's look at the pattern)
 * 
 * Let's trace:
 * If K=2:
 * Points 0, 1: Chef serves. (0/2 = 0, 1/2 = 0) -> Even quotient
 * Points 2, 3: Cook serves. (2/2 = 1, 3/2 = 1) -> Odd quotient
 * Points 4, 5: Chef serves. (4/2 = 2, 5/2 = 2) -> Even quotient
 * 
 * The rule is:
 * Calculate total points S = P1 + P2.
 * Calculate the number of completed service cycles: cycles = S / K.
 * If cycles is even, it is Chef's turn.
 * If cycles is odd, it is Cook's turn.
 * 
 * Constraints:
 * P1, P2, K up to 10^9. S can be up to 2*10^9, which fits in a standard 32-bit signed integer,
 * but using long long is safer and good practice for competitive programming.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;

        long long total_points = p1 + p2;
        long long cycles = total_points / k;

        if (cycles % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }

    return 0;
}