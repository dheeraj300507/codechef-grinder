#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N GB of space.
 * He has X files of 1 GB each and Y files of 2 GB each.
 * Total space required = (X * 1) + (Y * 2).
 * Chef can save the files if Total space required <= N.
 * 
 * Constraints:
 * T <= 100
 * N, X, Y <= 100
 * The maximum possible space required is 100 + 2*100 = 300, 
 * which fits well within a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        
        // Calculate total size required
        long long total_required = x + (2 * y);
        
        // Check if total required space is less than or equal to available space
        if (total_required <= n) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}