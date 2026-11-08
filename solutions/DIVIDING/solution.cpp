#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N members. We want to redistribute the total number of stamps such that
 * the i-th member (1-indexed) gets exactly i stamps.
 * 
 * The total number of stamps required to satisfy the condition is the sum of 
 * the first N natural numbers: 1 + 2 + 3 + ... + N.
 * The formula for this sum is S = N * (N + 1) / 2.
 * 
 * If the sum of the given stamps (C1 + C2 + ... + CN) is exactly equal to S,
 * then it is possible to redistribute them as required. Otherwise, it is not.
 * 
 * Constraints:
 * N <= 100,000
 * Ci <= 10^9
 * Total sum can exceed 2^31 - 1, so we must use long long.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long total_stamps = 0;
    for (int i = 0; i < n; ++i) {
        long long c;
        cin >> c;
        total_stamps += c;
    }

    // The required sum is the sum of 1 to N
    // Using long long to prevent overflow during calculation
    long long required_sum = (long long)n * (n + 1) / 2;

    if (total_stamps == required_sum) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}