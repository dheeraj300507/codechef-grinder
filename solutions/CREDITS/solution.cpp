#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Overload: X > 65
 * - Underload: X < 35
 * - Normal: 35 <= X <= 65
 * 
 * Constraints:
 * - 1 <= T <= 100
 * - 1 <= X <= 100
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
        int x;
        cin >> x;
        
        if (x > 65) {
            cout << "Overload" << "\n";
        } else if (x < 35) {
            cout << "Underload" << "\n";
        } else {
            cout << "Normal" << "\n";
        }
    }
    
    return 0;
}