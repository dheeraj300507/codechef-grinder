#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let 'a' be the number of leaves decorated with (1 large, 3 small).
 * Let 'b' be the number of leaves decorated with (2 large).
 * 
 * We have the following constraints:
 * 1) a + b = N
 * 2) a + 2b <= X (Total large ornaments used must be <= X)
 * 3) 3a <= Y (Total small ornaments used must be <= Y)
 * 
 * From (1), b = N - a.
 * Substitute b into (2):
 * a + 2(N - a) <= X
 * a + 2N - 2a <= X
 * 2N - a <= X
 * a >= 2N - X
 * 
 * Also, since b >= 0, we have N - a >= 0 => a <= N.
 * Since a >= 0, we have a >= 0.
 * Combining: max(0, 2N - X) <= a <= min(N, Y / 3).
 * 
 * A solution exists if there exists an integer 'a' such that:
 * max(0, 2N - X) <= a <= min(N, Y / 3)
 * This is possible if and only if:
 * max(0, 2N - X) <= min(N, Y / 3)
 */

void solve() {
    long long N, X, Y;
    cin >> N >> X >> Y;

    // We need to find if there exists an 'a' such that:
    // 1) 0 <= a <= N
    // 2) a <= Y / 3
    // 3) a >= 2 * N - X
    
    // Let lower_bound = max(0LL, 2 * N - X)
    // Let upper_bound = min(N, Y / 3)
    
    long long lower_bound = max(0LL, 2 * N - X);
    long long upper_bound = min(N, Y / 3);
    
    if (lower_bound <= upper_bound) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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