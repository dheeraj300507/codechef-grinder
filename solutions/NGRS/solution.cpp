#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grading logic is defined as follows:
 * 1. If attendance (X) < 50, grade is 'Z'.
 * 2. Else if marks (Y) < 50, grade is 'F'.
 * 3. Otherwise, grade is 'A'.
 * 
 * Constraints: 1 <= X, Y <= 100.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        if (x < 50) {
            cout << "Z" << "\n";
        } else if (y < 50) {
            cout << "F" << "\n";
        } else {
            cout << "A" << "\n";
        }
    }
    
    return 0;
}