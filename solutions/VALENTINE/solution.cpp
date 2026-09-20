#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X rupees and each chocolate costs Y rupees.
 * The maximum number of chocolates Chef can buy is the integer part of X / Y.
 * This is equivalent to floor division in integer arithmetic.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= X, Y <= 100
 * Since X and Y are small, standard integer types are sufficient.
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
        long long x, y;
        cin >> x >> y;
        
        // The maximum number of chocolates is X divided by Y (integer division).
        // If X < Y, the result of integer division is 0, which is correct.
        long long max_chocolates = x / y;
        
        cout << max_chocolates << "\n";
    }
    
    return 0;
}