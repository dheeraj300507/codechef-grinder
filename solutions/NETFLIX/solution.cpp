#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three amounts A, B, and C, and a target cost X.
 * We need to check if any pair of the three can sum up to at least X.
 * The possible pairs are:
 * 1. Alice + Bob (A + B)
 * 2. Alice + Charlie (A + C)
 * 3. Bob + Charlie (B + C)
 * 
 * If any of these sums are >= X, the answer is YES, otherwise NO.
 * 
 * Constraints:
 * A, B, C, X are between 1 and 100.
 * The sum of any two will not exceed 200, so standard 'int' is sufficient.
 */

void solve() {
    int A, B, C, X;
    if (!(cin >> A >> B >> C >> X)) return;

    // Check all three possible combinations
    if ((A + B >= X) || (A + C >= X) || (B + C >= X)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}