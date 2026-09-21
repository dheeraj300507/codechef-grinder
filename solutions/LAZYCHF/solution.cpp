#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's work takes x units of time.
 * Due to laziness, he takes m * x units of time.
 * However, there is a limit to the delay: he can delay at most d units.
 * This means the total time taken is capped at x + d.
 * Therefore, the time taken is min(m * x, x + d).
 * 
 * Constraints:
 * 1 <= T <= 10^4
 * 1 <= x, m <= 10
 * 0 <= d < 100
 * Since the values are small, standard 'int' is sufficient, but 'long long' 
 * is used for robustness.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, m, d;
        cin >> x >> m >> d;
        
        // Calculate the time taken by laziness: m * x
        // Calculate the maximum allowed time: x + d
        // The result is the minimum of these two values
        long long lazy_time = m * x;
        long long max_allowed_time = x + d;
        
        cout << min(lazy_time, max_allowed_time) << "\n";
    }
    
    return 0;
}