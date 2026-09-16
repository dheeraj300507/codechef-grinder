#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Chef has N candies and M friends.
 * 2. Each friend must get an equal number of candies: N must be divisible by M (N % M == 0).
 * 3. Each friend must get an even number of candies: (N / M) % 2 == 0.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= N, M <= 1000
 * 
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
        long long n, m;
        cin >> n >> m;
        
        // Condition 1: N must be perfectly divisible by M
        // Condition 2: The quotient (N/M) must be even
        if ((n % m == 0) && ((n / m) % 2 == 0)) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}