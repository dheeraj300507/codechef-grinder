#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each polybag holds at most 10 items.
 * To find the minimum number of polybags for N items, we need to calculate ceil(N / 10).
 * Using integer arithmetic, ceil(N / 10) can be calculated as (N + 9) / 10.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= N <= 1000
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate minimum polybags using integer division ceiling formula
        // (n + 10 - 1) / 10
        long long result = (n + 9) / 10;
        
        cout << result << "\n";
    }
    
    return 0;
}