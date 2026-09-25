#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Olympics Ranking
 * The problem asks us to compare the total number of medals (Gold + Silver + Bronze)
 * for two countries and determine which one has a higher total.
 * 
 * Constraints:
 * T <= 1000
 * Medals <= 30
 * Total medals per country <= 90
 * Integer overflow is not an issue as the sum fits in a standard int,
 * but using long long is safe practice.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long g1, s1, b1, g2, s2, b2;
        cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;

        long long total1 = g1 + s1 + b1;
        long long total2 = g2 + s2 + b2;

        // The problem guarantees no tie, so we only need to check > or <
        if (total1 > total2) {
            cout << "1" << "\n";
        } else {
            cout << "2" << "\n";
        }
    }

    return 0;
}