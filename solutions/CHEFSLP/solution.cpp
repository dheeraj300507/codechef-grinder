#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total slippers = N
 * Left slippers = L
 * Right slippers = R = N - L
 * A pair consists of one left and one right slipper.
 * The number of pairs that can be formed is limited by the minimum of the 
 * number of left slippers and the number of right slippers.
 * Pairs = min(L, N - L)
 * Total revenue = Pairs * X
 * 
 * Constraints:
 * N, L, X <= 1000.
 * The maximum possible result is 1000 * 1000 = 1,000,000, which fits in a standard 32-bit int.
 * Using long long is safe practice for competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, l, x;
        cin >> n >> l >> x;

        // Calculate number of right slippers
        long long r = n - l;

        // The number of pairs is the minimum of left and right slippers
        long long pairs = min(l, r);

        // Total revenue
        long long revenue = pairs * x;

        cout << revenue << "\n";
    }

    return 0;
}