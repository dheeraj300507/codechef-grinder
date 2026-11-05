#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N, M, and K. We need to find integers l (1 <= l <= N) and w (1 <= w <= M)
 * such that |2 * (l + w) - K| is minimized.
 * 
 * Constraints:
 * N, M, K <= 100.
 * Since the constraints are very small (up to 100), we can iterate through all possible
 * values of l and w using nested loops.
 * 
 * Complexity:
 * Time: O(T * N * M), which is at most 100 * 100 * 100 = 1,000,000 operations.
 * This is well within the 1s time limit.
 * Space: O(1) as we only store a few variables.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int min_diff = INT_MAX;

        // Iterate through all possible lengths and widths
        for (int l = 1; l <= n; ++l) {
            for (int w = 1; w <= m; ++w) {
                int perimeter = 2 * (l + w);
                int current_diff = abs(perimeter - k);
                
                if (current_diff < min_diff) {
                    min_diff = current_diff;
                }
            }
        }

        cout << min_diff << "\n";
    }

    return 0;
}