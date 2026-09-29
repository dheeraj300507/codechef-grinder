#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each over consists of 6 balls.
 * The maximum runs that can be scored in a single ball is 6.
 * Therefore, the maximum runs that can be scored in 1 over is 6 * 6 = 36.
 * In M overs, the maximum runs that can be scored is M * 36.
 * 
 * Chef's team can win if the required runs N is less than or equal to 
 * the maximum possible runs they can score in M overs.
 * Condition: N <= M * 36
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // Calculate maximum possible runs
        long long max_runs = m * 6 * 6;
        
        // Check if required runs are achievable
        if (n <= max_runs) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}