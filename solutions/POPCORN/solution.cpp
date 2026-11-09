#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three combos A, B, and C.
 * Each combo consists of two parts (Popcorn and Coke) with given durations.
 * Satisfaction = Sum of durations of the two parts in a combo.
 * We need to find the maximum satisfaction among the three combos.
 * 
 * Constraints:
 * Durations are up to 10^9. The sum can be up to 2 * 10^9, which fits in a 
 * standard 32-bit signed integer, but using 'long long' is safer and 
 * standard practice in competitive programming to prevent overflow.
 * 
 * Complexity:
 * Time: O(1) per test case, O(T) total.
 * Space: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a1, a2, b1, b2, c1, c2;
        
        // Read input for the three combos
        cin >> a1 >> a2;
        cin >> b1 >> b2;
        cin >> c1 >> c2;
        
        // Calculate satisfaction for each combo
        long long satA = a1 + a2;
        long long satB = b1 + b2;
        long long satC = c1 + c2;
        
        // Find the maximum of the three
        long long maxSat = max({satA, satB, satC});
        
        // Output the result
        cout << maxSat << "\n";
    }
    
    return 0;
}