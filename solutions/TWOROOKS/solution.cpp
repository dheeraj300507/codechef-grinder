#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Two rooks on a chessboard attack each other if they share the same row or the same column.
 * Given coordinates (X1, Y1) and (X2, Y2):
 * - They share the same row if Y1 == Y2.
 * - They share the same column if X1 == X2.
 * If either condition is true, they attack each other.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Rooks attack if they are in the same row (y1 == y2) 
        // or the same column (x1 == x2).
        if (x1 == x2 || y1 == y2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}