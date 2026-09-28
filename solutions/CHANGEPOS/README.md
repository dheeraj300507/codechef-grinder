# [Change Row and Column Both (CHANGEPOS)](https://www.codechef.com/problems/CHANGEPOS)

- **Difficulty Rating**: 660
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a $10 \times 10$ grid. You start at position $(s_x, s_y)$ and want to reach $(e_x, e_y)$. A move is valid if and only if both the row index and the column index change (i.e., you move from $(a, b)$ to $(c, d)$ where $a \neq c$ and $b \neq d$). You are guaranteed that the starting position is not the same as the ending position. Determine the minimum number of moves required to reach the destination.

## Intuition & Mathematical Observation
The problem defines a move as a change in both coordinates. 

1.  **Case 1: 1 Move**
    If the starting coordinates $(s_x, s_y)$ and ending coordinates $(e_x, e_y)$ satisfy $s_x \neq e_x$ AND $s_y \neq e_y$, we can reach the destination in exactly **1 move** because the move satisfies the problem's condition directly.

2.  **Case 2: 2 Moves**
    If either $s_x = e_x$ OR $s_y = e_y$, we cannot reach the destination in a single move because one of the conditions ($a \neq c$ or $b \neq d$) will be violated. However, since the grid is $10 \times 10$ and we are guaranteed $(s_x, s_y) \neq (e_x, e_y)$, we can always pick an intermediate cell $(r, c)$ such that $r \neq s_x, r \neq e_x$ and $c \neq s_y, c \neq e_y$. Thus, it will always take **2 moves** to reach the destination if the direct move is impossible.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform simple conditional checks. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are on a 10x10 grid.
 * A move from (a, b) to (c, d) is valid if a != c AND b != d.
 * 
 * Case 1: If s_x != e_x AND s_y != e_y:
 * We can reach the destination in exactly 1 move.
 * 
 * Case 2: If s_x == e_x OR s_y == e_y:
 * We cannot reach the destination in 1 move because one of the conditions 
 * will be violated. We can always reach it in 2 moves by picking an 
 * intermediate cell.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        // If both row and column are different, 1 move is sufficient.
        if (sx != ex && sy != ey) {
            cout << 1 << "\n";
        } 
        // If either row or column is the same, we need 2 moves.
        else {
            cout << 2 << "\n";
        }
    }

    return 0;
}
```