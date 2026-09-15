#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Interior Design
 * The task is to compare the sum of two pairs of integers (X1 + Y1) and (X2 + Y2)
 * and output the minimum of the two sums.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        long long cost1 = x1 + y1;
        long long cost2 = x2 + y2;
        
        // Output the minimum of the two costs
        if (cost1 < cost2) {
            cout << cost1 << "\n";
        } else {
            cout << cost2 << "\n";
        }
    }
    
    return 0;
}