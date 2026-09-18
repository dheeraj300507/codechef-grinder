#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Easy problems = 1 point each
 * Hard problems = 2 points each
 * Total score = (A * 1) + (B * 2)
 * Qualification condition: Total score >= X
 * 
 * Constraints:
 * T <= 100
 * X, A, B <= 100
 * The maximum possible score is 100*1 + 100*2 = 300, which fits in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long x, a, b;
        cin >> x >> a >> b;

        // Calculate total score
        long long total_score = (a * 1) + (b * 2);

        // Check qualification condition
        if (total_score >= x) {
            cout << "Qualify" << "\n";
        } else {
            cout << "NotQualify" << "\n";
        }
    }

    return 0;
}