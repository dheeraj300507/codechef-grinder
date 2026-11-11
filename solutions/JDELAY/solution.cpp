#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Judging Delay
 * Approach:
 * For each submission, the delay is calculated as (J_i - S_i).
 * We need to count how many submissions have (J_i - S_i) > 5.
 * Constraints are small (N <= 100, T <= 100), so an O(N) approach per test case is optimal.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int S, J;
        cin >> S >> J;
        // Check if the delay is strictly greater than 5 minutes
        if ((J - S) > 5) {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}