#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N items with prices P_i.
 * A price ceiling K is introduced.
 * If P_i > K, the price becomes K.
 * The lost revenue for a single item i is:
 * - If P_i > K: P_i - K
 * - If P_i <= K: 0
 * Total lost revenue = Sum of max(0, P_i - K) for all i from 1 to N.
 * 
 * Constraints:
 * T <= 100, N <= 10,000, P_i <= 1,000, K <= 1,000.
 * The maximum possible lost revenue is N * max(P_i) = 10,000 * 1,000 = 10,000,000.
 * This fits comfortably within a standard 32-bit integer, but using long long 
 * is good practice to prevent overflow in similar problems.
 */

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;
    
    long long lost_revenue = 0;
    for (int i = 0; i < N; ++i) {
        long long P;
        cin >> P;
        if (P > K) {
            lost_revenue += (P - K);
        }
    }
    cout << lost_revenue << "\n";
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