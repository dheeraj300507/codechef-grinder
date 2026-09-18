#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs C chocolates in total.
 * Chef already has X chocolates.
 * Therefore, Chef needs to buy (C - X) chocolates.
 * Each chocolate costs Y rupees.
 * Total cost = (C - X) * Y.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= C <= 100
 * 0 <= X <= C
 * 1 <= Y <= 100
 * 
 * The logic is straightforward:
 * 1. Read T.
 * 2. For each test case, read C, X, Y.
 * 3. Calculate (C - X) * Y.
 * 4. Print the result.
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int c, x, y;
        if (!(cin >> c >> x >> y)) break;
        
        // Calculate the number of chocolates needed
        int needed = c - x;
        
        // Calculate total cost
        // Since C, X, Y <= 100, the result fits in a standard int
        int cost = needed * y;
        
        // Output the result
        cout << cost << "\n";
    }
    
    return 0;
}