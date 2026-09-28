#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To move from string S_i to S_{i+1}, the number of strings skipped is:
 * |S_{i+1} - S_i| - 1.
 * 
 * We need to sum this value for all i from 1 to N-1.
 * Total = sum_{i=1}^{N-1} (|S_{i+1} - S_i| - 1)
 * 
 * Constraints:
 * T <= 10
 * N <= 10^5
 * S_i <= 10^6
 * The total sum can exceed the range of a 32-bit integer, so we use long long.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    
    long long total_skipped = 0;
    for (int i = 0; i < N - 1; ++i) {
        long long diff = abs(S[i+1] - S[i]);
        if (diff > 0) {
            total_skipped += (diff - 1);
        }
    }
    
    cout << total_skipped << "\n";
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