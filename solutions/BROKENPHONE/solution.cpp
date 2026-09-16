#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: BROKENPHONE
 * Logic:
 * Compare the cost of repair (X) and the cost of a new phone (Y).
 * If X < Y, output REPAIR.
 * If X > Y, output NEW PHONE.
 * If X == Y, output ANY.
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
        long long x, y;
        cin >> x >> y;
        
        if (x < y) {
            cout << "REPAIR" << "\n";
        } else if (x > y) {
            cout << "NEW PHONE" << "\n";
        } else {
            cout << "ANY" << "\n";
        }
    }
    
    return 0;
}