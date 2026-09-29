#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N elephants and C candies.
 * Each elephant K needs at least A_K candies.
 * To make all elephants happy, we need a total of at least sum(A_1, A_2, ..., A_N) candies.
 * If C >= sum(A_i), then it is possible to make them all happy.
 * Otherwise, it is impossible.
 * 
 * Constraints:
 * T <= 1000
 * N <= 100
 * C <= 10^9
 * A_K <= 10000
 * 
 * The sum of A_K can be at most 100 * 10000 = 1,000,000.
 * This fits comfortably within a standard 32-bit integer, but using long long 
 * is safer and good practice for competitive programming to avoid overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        
        long long total_needed = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            total_needed += a;
        }
        
        if (c >= total_needed) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}