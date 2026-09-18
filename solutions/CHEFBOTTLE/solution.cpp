#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N bottles, each with capacity X.
 * Total water available is K.
 * We want to find the maximum number of bottles that can be filled completely.
 * 
 * 1. The number of bottles that can be filled by the water available is floor(K / X).
 * 2. However, Chef only has N bottles available.
 * 3. Therefore, the number of bottles filled is min(N, floor(K / X)).
 * 
 * Constraints:
 * N, X, K up to 10^5.
 * The result will fit in a standard integer, but using long long is safe practice.
 * Time complexity: O(1) per test case.
 * Space complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        // If capacity is 0, we cannot fill any bottles (though constraints say X >= 1)
        if (x == 0) {
            cout << 0 << "\n";
            continue;
        }

        // Calculate how many bottles can be filled with K water
        long long bottles_by_water = k / x;

        // The answer is the smaller of the available bottles and the bottles filled by water
        long long ans = min(n, bottles_by_water);

        cout << ans << "\n";
    }

    return 0;
}