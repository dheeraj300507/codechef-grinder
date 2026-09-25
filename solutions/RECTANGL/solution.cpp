#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * A rectangle requires two pairs of equal sides. 
 * By sorting the four input integers, we ensure that if a rectangle 
 * can be formed, the sides must satisfy:
 * sides[0] == sides[1] AND sides[2] == sides[3].
 * 
 * Complexity:
 * Time: O(T) - Sorting 4 elements is O(1).
 * Space: O(1) - Only storing 4 integers.
 */

void solve() {
    int sides[4];
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> sides[i])) return;
    }
    
    // Sort the sides to easily compare pairs
    sort(sides, sides + 4);
    
    // Check if the two smallest are equal and the two largest are equal
    if (sides[0] == sides[1] && sides[2] == sides[3]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}