#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N players to choose from.
 * He needs to select 1 captain and 1 vice-captain from these N players.
 * The order matters (choosing player A as captain and B as vice-captain is 
 * different from choosing B as captain and A as vice-captain).
 * 
 * Number of ways to choose the captain = N
 * Number of ways to choose the vice-captain from the remaining = N - 1
 * Total ways = N * (N - 1)
 * 
 * Constraints: 2 <= N <= 11.
 * The maximum value is 11 * 10 = 110, which fits easily in an integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate permutations of 2 items from N: P(N, 2) = N * (N - 1)
        long long result = n * (n - 1);
        
        cout << result << "\n";
    }

    return 0;
}