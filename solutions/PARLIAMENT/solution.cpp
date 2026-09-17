#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The resolution passes if X >= N / 2.0.
 * To avoid floating point arithmetic, we can multiply both sides by 2:
 * 2 * X >= N
 * This condition correctly handles both even and odd N.
 * 
 * Constraints:
 * T <= 5000, N <= 100.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 * Space complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // The condition is X >= N / 2.0
        // Equivalent to 2 * X >= N
        if (2 * x >= n) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}