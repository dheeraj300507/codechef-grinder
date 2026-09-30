# [Magical World (P2149)](https://www.codechef.com/problems/P2149)

- **Difficulty Rating**: 1005
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a rectangle with dimensions $A \times B$ and a square with side length $X$. You want to fit the rectangle inside the square's area, meaning the area of the rectangle ($A \times B$) must be less than or equal to the area of the square ($X \times X$). You can change the dimensions of the rectangle by 1 unit per move. Calculate the minimum number of moves required to satisfy the condition $A \times B \le X \times X$.

## Intuition & Mathematical Observation
The problem asks for the minimum number of operations to make the rectangle's area smaller than or equal to the square's area. Since we want to minimize the number of moves, we evaluate the possibilities in increasing order of cost:

1.  **0 Moves**: If the current area $A \times B$ is already $\le X^2$, no changes are needed.
2.  **1 Move**: We can reduce one dimension of the rectangle to 1. If we change $A$ to 1, the new area is $1 \times B = B$. If we change $B$ to 1, the new area is $A \times 1 = A$. If either $A \le X^2$ or $B \le X^2$, we can achieve the goal in 1 move.
3.  **2 Moves**: If neither of the above works, we can change both dimensions to 1. The area becomes $1 \times 1 = 1$. Since $X \ge 1$, $1 \le X^2$ is always true. Thus, 2 moves are always sufficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the dimensions.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a red rectangle (A x B) and a blue square (X x X).
 * We want Area(Rectangle) <= Area(Square), i.e., A * B <= X * X.
 * Each change of a dimension (A or B) costs 1 unit.
 */

void solve() {
    int A, B, X;
    cin >> A >> B >> X;

    long long rectArea = (long long)A * B;
    long long squareArea = (long long)X * X;

    // Case 0: Already satisfied
    if (rectArea <= squareArea) {
        cout << 0 << "\n";
        return;
    }

    // Case 1: Can we satisfy by changing one dimension to 1?
    // New area would be 1 * B or A * 1.
    if (B <= squareArea || A <= squareArea) {
        cout << 1 << "\n";
        return;
    }

    // Case 2: Change both dimensions to 1.
    // 1 * 1 = 1, and since X >= 1, 1 <= X*X is always true.
    cout << 2 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```