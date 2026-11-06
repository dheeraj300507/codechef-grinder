#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total marbles S = A + B.
 * After redistribution, let Chef have A' and his friend have B'.
 * A' + B' = S, where A' >= 1, B' >= 1.
 * We need A' % B' == 0.
 * This means A' = k * B' for some integer k >= 1.
 * Substituting: k * B' + B' = S => B'(k + 1) = S.
 * So, B' must be a divisor of S, and B' < S (since A' >= 1).
 * 
 * We want to minimize the number of marbles transferred.
 * The number of marbles transferred is |A - A'| = |A - (S - B')| = |A - S + B'| = |B' - B|.
 * 
 * We iterate through all possible values of B' (from 1 to S-1) such that S % B' == 0.
 * For each valid B', calculate the cost |B' - B| and find the minimum.
 */

void solve() {
    long long A, B;
    cin >> A >> B;
    long long S = A + B;
    long long min_transfers = -1;

    // B' is the number of marbles the friend has after redistribution.
    // B' must be a divisor of S, and 1 <= B' <= S-1.
    for (long long B_prime = 1; B_prime < S; ++B_prime) {
        if (S % B_prime == 0) {
            long long transfers = abs(B_prime - B);
            if (min_transfers == -1 || transfers < min_transfers) {
                min_transfers = transfers;
            }
        }
    }
    cout << min_transfers << "\n";
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