#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Spice Level
 * Logic:
 * - MILD: X < 4
 * - MEDIUM: 4 <= X < 7
 * - HOT: X >= 7
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        if (x < 4) {
            cout << "MILD" << "\n";
        } else if (x >= 4 && x < 7) {
            cout << "MEDIUM" << "\n";
        } else {
            cout << "HOT" << "\n";
        }
    }
    
    return 0;
}