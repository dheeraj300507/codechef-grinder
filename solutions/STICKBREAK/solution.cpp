#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to minimize sum_{i=1}^{K-1} |A_{i+1} - A_i| subject to sum(A_i) = L, A_i >= 1.
 * 
 * Let q = L / K and r = L % K.
 * If we distribute the lengths as evenly as possible, we have r parts of length (q+1) 
 * and (K-r) parts of length q.
 * 
 * To minimize the sum of absolute differences, we want to keep the values as close 
 * as possible. If we set all A_i to be either q or q+1, the sum of absolute 
 * differences will be minimized.
 * 
 * Specifically, if we arrange the parts such that we transition between q and q+1 
 * as few times as possible, we minimize the sum.
 * 
 * If r == 0, all parts are equal to L/K, so the sum is 0.
 * If r > 0, we have r parts of (q+1) and (K-r) parts of q.
 * The minimum sum of absolute differences for this configuration is 1 if r > 0,
 * because we can arrange them as [q+1, q+1, ..., q+1 (r times), q, q, ..., q (K-r times)].
 * The only non-zero difference occurs at the boundary between the last (q+1) and the first q.
 * |q - (q+1)| = 1.
 */

void solve() {
    long long L, K;
    cin >> L >> K;

    if (L % K == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
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