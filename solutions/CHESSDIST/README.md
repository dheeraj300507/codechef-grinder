# [Chessboard Distance (CHESSDIST)](https://www.codechef.com/problems/CHESSDIST)

- **Difficulty Rating**: 690
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two points on a 2D Cartesian plane, $(X_1, Y_1)$ and $(X_2, Y_2)$, calculate the "chessboard distance" between them. The distance is defined as the maximum of the absolute difference between their x-coordinates and the absolute difference between their y-coordinates:
$$\text{Distance} = \max(|X_1 - X_2|, |Y_1 - Y_2|)$$

## Intuition & Mathematical Observation
In chess, a King can move one square in any direction (horizontally, vertically, or diagonally). This movement pattern is known as the **Chebyshev distance**. 

1. To move from $(X_1, Y_1)$ to $(X_2, Y_2)$, the King must cover the horizontal gap $|X_1 - X_2|$ and the vertical gap $|Y_1 - Y_2|$.
2. Since a diagonal move covers one unit of both horizontal and vertical distance simultaneously, the King can "cancel out" the smaller of the two differences by moving diagonally.
3. After moving diagonally as much as possible, the King will be left with a straight-line path (either purely horizontal or purely vertical) equal to the difference between the two values.
4. Therefore, the minimum number of moves required is simply the maximum of the two absolute differences.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations and comparisons, the solution runs in constant time. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a few variables to store the coordinates and the result, requiring no extra data structures that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chessboard Distance
 * The distance is defined as max(|X1 - X2|, |Y1 - Y2|).
 * Constraints: 1 <= X, Y <= 10^5.
 * The differences will fit in standard integer types, but using long long 
 * is safe practice for competitive programming to prevent overflow in 
 * arithmetic operations.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Calculate absolute differences
        long long diff_x = abs(x1 - x2);
        long long diff_y = abs(y1 - y2);
        
        // The chessboard distance is the maximum of the two absolute differences
        long long distance = max(diff_x, diff_y);
        
        cout << distance << "\n";
    }
    
    return 0;
}
```