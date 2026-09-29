# [Payment Scheme (PAYSC)](https://www.codechef.com/problems/PAYSC)

- **Difficulty Rating**: 213
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine the minimum payment amount between two different schemes for a given value $X$:
1. **Scheme 1**: $100 + 4 \times X$
2. **Scheme 2**: $300$

We are given $X$ and must output the smaller of the two calculated values.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. Since we are given a fixed formula for Scheme 1 and a constant value for Scheme 2, we simply need to:
1. Calculate the result of $100 + 4X$.
2. Compare it with $300$.
3. Print the minimum of the two using a conditional statement or the built-in `min()` function.

Given the constraint $1 \le X \le 100$, the maximum value for Scheme 1 is $100 + 4(100) = 500$, which fits comfortably within a standard integer type.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Scheme 1: 100 + 4 * X
 * Scheme 2: 300
 * We need to find the minimum of these two values.
 * 
 * Input Format:
 * The input contains a single integer X.
 * 
 * Constraints: 1 <= X <= 100.
 */

int main() {
    // Fast I/O setup for efficiency
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (cin >> X) {
        int scheme1 = 100 + (4 * X);
        int scheme2 = 300;

        // Output the minimum of the two schemes
        cout << min(scheme1, scheme2) << endl;
    }

    return 0;
}
```