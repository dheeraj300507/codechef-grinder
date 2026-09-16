#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each bike has 2 tyres.
 * Each car has 4 tyres.
 * Total tyres = (N * 2) + (M * 4).
 * Constraints: N, M <= 100. The result will be at most (100*2 + 100*4) = 600.
 * This fits comfortably within a standard 'int'.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        if (cin >> n >> m) {
            // Calculate total tyres
            long long total_tyres = (n * 2) + (m * 4);
            cout << total_tyres << "\n";
        }
    }

    return 0;
}