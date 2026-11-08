# [Two Rooks (TWOROOKS)](https://www.codechef.com/problems/TWOROOKS)

- **Difficulty Rating**: 957
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the coordinates of two rooks on an $8 \times 8$ chessboard, $(X_1, Y_1)$ and $(X_2, Y_2)$, determine if the two rooks attack each other. In chess, a rook attacks any piece that shares the same row or the same column.

## Intuition & Mathematical Observation
A rook's movement is restricted to horizontal and vertical lines. Therefore, two rooks will attack each other if and only if:
1. **Same Row**: Their $Y$-coordinates are equal ($Y_1 = Y_2$).
2. **Same Column**: Their $X$-coordinates are equal ($X_1 = X_2$).

If either of these conditions is met, the rooks are in an attacking position. Otherwise, they are safe from each other. We can evaluate this using a simple logical `OR` condition: `(x1 == x2 || y1 == y2)`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the coordinates.

## Solution Code

```cpp
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
```