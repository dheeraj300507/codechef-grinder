# [Can_Reach (CAN_REACH)](https://www.codechef.com/problems/CAN_REACH)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
A student starts at the origin $(0, 0)$ on a 2D plane. In each move, the student can move exactly $K$ units in any of the four cardinal directions (up, down, left, or right). Given a target coordinate $(x, y)$, determine if it is possible for the student to reach this point in any number of moves.

## Intuition & Mathematical Observation
The student moves in increments of $K$. This implies that after any number of moves, the total displacement in the $x$-direction must be a multiple of $K$, and the total displacement in the $y$-direction must also be a multiple of $K$.

1.  **Divisibility**: For the student to reach $(x, y)$, both $x$ and $y$ must be perfectly divisible by $K$.
2.  **Mathematical Condition**: The condition is satisfied if $x \pmod K = 0$ and $y \pmod K = 0$.
3.  **Handling Negatives**: In C++, the modulo operator `%` preserves the sign of the dividend. However, if a number is a multiple of $K$, the remainder will be $0$ regardless of whether the number is positive or negative (e.g., $-10 \pmod 5 = 0$). Thus, the standard modulo check is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input coordinates and the step size $K$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The student starts at (0, 0) and moves by exactly K in either the x or y direction.
 * This means after n moves, the x-coordinate will be a multiple of K (x = a * K)
 * and the y-coordinate will be a multiple of K (y = b * K), where a and b are integers.
 * 
 * Therefore, for the student to reach (x, y), both x and y must be divisible by K.
 * Mathematically, x % K == 0 and y % K == 0.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        // Check if both coordinates are divisible by K
        if (x % k == 0 && y % k == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```