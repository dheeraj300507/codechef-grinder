# [All New CodeChef (NEWCC)](https://www.codechef.com/problems/NEWCC)

- **Difficulty Rating**: 354
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare the performance of two systems based on their runtime. Given two integers $X$ (runtime on the old system) and $Y$ (runtime on the new system), we need to determine which system is faster:
- If $X < Y$, the old system is faster.
- If $X > Y$, the new system is faster.
- If $X = Y$, both systems have the same performance.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. Since a smaller runtime indicates a faster system, we simply need to use conditional `if-else` statements to compare the two input integers:
1. Compare $X$ and $Y$.
2. If $X < Y$, print "Old".
3. If $X > Y$, print "New".
4. If $X = Y$, print "Same".

The constraints ($1 \le X, Y \le 3000$) are small enough that any standard integer type will suffice, and the logic remains constant regardless of the input values.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of comparisons.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the two integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers X and Y representing the runtime on the old and new systems respectively.
 * A smaller runtime indicates a faster system.
 * - If X < Y, the old system is faster (Old).
 * - If X > Y, the new system is faster (New).
 * - If X == Y, they are equally fast (Same).
 * 
 * Constraints: 1 <= X, Y <= 3000.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // Read the input values X and Y
    if (cin >> X >> Y) {
        if (X < Y) {
            cout << "Old" << "\n";
        } else if (Y < X) {
            cout << "New" << "\n";
        } else {
            cout << "Same" << "\n";
        }
    }

    return 0;
}
```