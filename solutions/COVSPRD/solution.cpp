#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Day 0: 1 person infected.
 * - Days 1 to 10: Number of infected doubles each day (2^D).
 * - Days 11 onwards: Number of infected triples each day (2^10 * 3^(D-10)).
 * - The number of infected people cannot exceed the population N.
 * 
 * Constraints:
 * - N <= 10^8, D <= 10^8.
 * - Since N is up to 10^8, we can use long long to prevent overflow, 
 *   though the result will not exceed 10^8.
 */

void solve() {
    long long N, D;
    cin >> N >> D;

    long long infected = 1;

    if (D <= 10) {
        // For D <= 10, infected = 2^D
        // We must check if 2^D exceeds N at any step
        for (int i = 1; i <= D; ++i) {
            infected *= 2;
            if (infected > N) {
                infected = N;
                break;
            }
        }
    } else {
        // For D > 10, first calculate for day 10
        infected = 1024; // 2^10
        if (infected > N) {
            infected = N;
        } else {
            // Then calculate for days 11 to D, tripling each day
            for (int i = 11; i <= D; ++i) {
                infected *= 3;
                if (infected > N) {
                    infected = N;
                    break;
                }
            }
        }
    }

    cout << infected << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}