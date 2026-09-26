#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial amount of ice cream = X
 * Melting rate = Y grams per minute
 * Time elapsed = N minutes
 * Total melted = Y * N
 * Remaining ice cream = X - (Y * N)
 * 
 * Constraint: If the calculated remaining amount is less than 0, 
 * it means the ice cream has completely melted, so the result should be 0.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, n;
        cin >> x >> y >> n;
        
        // Calculate total melted amount
        long long melted = y * n;
        
        // Remaining amount is X - melted, but cannot be less than 0
        long long remaining = x - melted;
        
        if (remaining < 0) {
            cout << 0 << "\n";
        } else {
            cout << remaining << "\n";
        }
    }
    
    return 0;
}