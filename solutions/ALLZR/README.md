# [All Zero (ALLZR)](https://www.codechef.com/problems/ALLZR)

- **Difficulty Rating**: 626
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given three integers $A, B,$ and $C$. We have two types of operations available:
1. **Type 1**: Decrease $A$ by 1 and $B$ by 2.
2. **Type 2**: Decrease $B$ by 1 and $C$ by 3.

The goal is to determine if it is possible to make $A, B,$ and $C$ all equal to zero using these operations.

## Intuition & Mathematical Observation
Let $x$ be the number of times we perform the Type 1 operation and $y$ be the number of times we perform the Type 2 operation. To reach the state $(0, 0, 0)$, the following equations must hold:

1. **For A**: $A - x = 0 \implies x = A$
2. **For C**: $C - 3y = 0 \implies y = C / 3$
3. **For B**: $B - 2x - y = 0$

By substituting the values of $x$ and $y$ from the first two equations into the third, we get:
$$B - 2(A) - (C/3) = 0$$
$$B = 2A + \frac{C}{3}$$

**Conditions for a valid solution:**
* $C$ must be perfectly divisible by 3 ($C \pmod 3 == 0$).
* The equation $B = 2A + \frac{C}{3}$ must hold true.
* Since the problem implies non-negative operations, $A, B, C$ must be non-negative (which is guaranteed by the constraints).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let x be the number of times we perform Type 1 operation.
 * Let y be the number of times we perform Type 2 operation.
 * 
 * The operations are:
 * Type 1: A -> A-1, B -> B-2
 * Type 2: B -> B-1, C -> C-3
 * 
 * To make A, B, C all zero:
 * 1. A - x = 0  => x = A
 * 2. C - 3y = 0 => y = C / 3 (must be an integer, so C must be divisible by 3)
 * 3. B - 2x - y = 0
 * 
 * Substituting x and y into the third equation:
 * B - 2(A) - (C/3) = 0
 * B = 2A + C/3
 */

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    // Check if C is divisible by 3 and if the balance equation holds
    if (C % 3 == 0) {
        int y = C / 3;
        if (B == 2 * A + y) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    } else {
        cout << "No" << "\n";
    }
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