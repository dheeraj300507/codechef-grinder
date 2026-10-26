#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Arya starts at (X0, Y0) and can jump exactly L units in 4 directions.
 * This means Arya can reach any cell (x, y) such that:
 * x = X0 + k1 * L, where 1 <= x <= N
 * y = Y0 + k2 * L, where 1 <= y <= M
 * 
 * Since the jump is always L in any direction, the set of reachable x-coordinates
 * is independent of the set of reachable y-coordinates.
 * Specifically, Arya can reach any row x such that x = X0 + k * L (for some integer k)
 * and 1 <= x <= N. Similarly for columns y = Y0 + k * L and 1 <= y <= M.
 * 
 * The total number of reachable cells is (number of reachable rows) * (number of reachable columns).
 * 
 * Number of reachable rows:
 * The rows are X0, X0-L, X0-2L, ..., X0+L, X0+2L, ...
 * These are all rows x such that x % L == X0 % L and 1 <= x <= N.
 * The smallest such row is X0 - floor((X0 - 1) / L) * L.
 * The largest such row is X0 + floor((N - X0) / L) * L.
 * The number of such rows is:
 * (Largest - Smallest) / L + 1
 * Alternatively:
 * Count = (X0 - 1) / L + (N - X0) / L + 1
 * 
 * Same logic applies to columns with M and Y0.
 */

void solve() {
    long long N, M, X0, Y0, L;
    if (!(cin >> N >> M >> X0 >> Y0 >> L)) return;

    // Number of reachable rows:
    // Rows are X0 + k*L.
    // k can be negative: X0 - k*L >= 1  => k*L <= X0 - 1 => k <= (X0 - 1) / L
    // k can be positive: X0 + k*L <= N  => k*L <= N - X0 => k <= (N - X0) / L
    long long rows_below = (X0 - 1) / L;
    long long rows_above = (N - X0) / L;
    long long total_rows = rows_below + rows_above + 1;

    // Number of reachable columns:
    long long cols_left = (Y0 - 1) / L;
    long long cols_right = (M - Y0) / L;
    long long total_cols = cols_left + cols_right + 1;

    long long ans = total_rows * total_cols;
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}