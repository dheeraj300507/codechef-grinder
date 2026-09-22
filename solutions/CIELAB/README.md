# [Ciel and A-B Problem (CIELAB)](https://www.codechef.com/problems/CIELAB)

- **Difficulty Rating**: 1136
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, calculate $A - B$. However, the output must be an integer that differs from the correct result by exactly one digit. The problem guarantees that the result of $A - B$ will be positive.

## Intuition & Mathematical Observation
The core challenge is to modify the result of $A - B$ such that exactly one digit is changed. 

Let $X = A - B$. We want to produce a value $Y$ such that $Y \neq X$, but $Y$ and $X$ differ by only one digit. The simplest way to achieve this is to modify the last digit (the units place) of $X$:

1. **Strategy**: Look at the last digit of $X$ (i.e., $X \pmod{10}$).
2. **Case 1**: If the last digit is $9$, adding $1$ would cause a carry (e.g., $19 \to 20$), which changes two digits. To avoid this, we subtract $1$ instead (e.g., $19 \to 18$).
3. **Case 2**: If the last digit is not $9$, adding $1$ is safe because it will not cause a carry (e.g., $12 \to 13$). This changes exactly one digit.

This approach ensures that the result remains positive and the number of digits remains the same, satisfying all problem constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as we perform a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to calculate A - B and output a result that differs by exactly one digit.
 * 
 * Strategy:
 * Calculate X = A - B.
 * If X % 10 == 9, change the last digit to 8 (X - 1).
 * Otherwise, change the last digit to X + 1.
 * This ensures the number of digits remains the same and the result is different.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (!(cin >> a >> b)) return 0;

    int diff = a - b;

    // We need to change exactly one digit.
    // If the last digit is 9, adding 1 would cause a carry (e.g., 19 -> 20),
    // changing two digits. Subtracting 1 is safer (19 -> 18).
    // Otherwise, adding 1 is safe and changes only the last digit.
    if (diff % 10 == 9) {
        diff -= 1;
    } else {
        diff += 1;
    }

    cout << diff << "\n";

    return 0;
}
```