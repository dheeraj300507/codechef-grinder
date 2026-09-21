#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given:
 * x_a: water per type A coconut
 * x_b: pulp per type B coconut
 * X_a: total water required
 * X_b: total pulp required
 * 
 * Since x_a divides X_a and x_b divides X_b, the number of coconuts 
 * of type A is X_a / x_a and type B is X_b / x_b.
 * The total number of coconuts is (X_a / x_a) + (X_b / x_b).
 * 
 * Constraints:
 * T <= 15000
 * Values are within standard integer range (up to 1500), so 'int' is sufficient.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int xa, xb, Xa, Xb;
        cin >> xa >> xb >> Xa >> Xb;
        
        // Calculate number of coconuts for each type
        int countA = Xa / xa;
        int countB = Xb / xb;
        
        // Output the total
        cout << (countA + countB) << "\n";
    }
    
    return 0;
}