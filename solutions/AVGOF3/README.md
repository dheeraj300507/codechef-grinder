# [Average of Three (AVGOF3)](https://www.codechef.com/problems/AVGOF3)

- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, we need to find three **distinct** positive integers $A_1, A_2, A_3$ such that their average is exactly $X$. That is:
$$\frac{A_1 + A_2 + A_3}{3} = X \implies A_1 + A_2 + A_3 = 3X$$

## Intuition & Mathematical Observation
To satisfy the equation $A_1 + A_2 + A_3 = 3X$, we can choose values symmetrically around $X$. 

Consider the sequence:
- $A_1 = X - 1$
- $A_2 = X$
- $A_3 = X + 1$

**Verification:**
1. **Sum:** $(X - 1) + X + (X + 1) = 3X$.
2. **Average:** $3X / 3 = X$.
3. **Distinctness:** Since $X-1 < X < X+1$, the three numbers are always distinct.
4. **Constraints:** Given $2 \le X \le 100$:
   - The smallest value is $X-1$. Since $X \ge 2$, $X-1 \ge 1$, satisfying the positive integer constraint.
   - The largest value is $X+1$. Since $X \le 100$, $X+1 \le 101$, which is well within the problem's bounds.

This simple construction works for all valid inputs provided in the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations and output the result. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * A simple construction is to pick numbers around X.
 * Let A1 = X - 1, A2 = X, A3 = X + 1.
 * Sum = (X - 1) + X + (X + 1) = 3X.
 * Mean = 3X / 3 = X.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Using the construction A1 = x-1, A2 = x, A3 = x+1
        // Since x >= 2, x-1 >= 1, which satisfies the lower bound.
        // Since x <= 100, x+1 <= 101, which satisfies the upper bound.
        // The numbers are distinct because (x-1) < x < (x+1).
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}
```