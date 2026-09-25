#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has M minutes until the exam.
 * Season-1 has N episodes, each of duration K minutes.
 * Total time required = N * K.
 * The condition is to finish "strictly before" the exam starts.
 * This means: Total time < M.
 * 
 * Constraints:
 * M <= 10^9
 * N, K <= 10^4
 * N * K can be up to 10^8, which fits in a standard 32-bit integer,
 * but using long long is safer and good practice for competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long m, n, k;
        cin >> m >> n >> k;
        
        // Calculate total duration required
        long long total_duration = n * k;
        
        // Check if total duration is strictly less than M
        if (total_duration < m) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}