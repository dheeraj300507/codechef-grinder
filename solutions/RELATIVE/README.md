# [Relativity (RELATIVE)](https://www.codechef.com/problems/RELATIVE)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are given the physical formula $v^2 = 2 \cdot g \cdot H$, where $v$ is the velocity, $g$ is the acceleration due to gravity, and $H$ is the height. We are provided with the values of $g$ and the speed of light $c$. Our task is to calculate the minimum height $H$ required such that the velocity $v$ reaches the speed of light $c$. It is guaranteed that $2 \cdot g$ always divides $c^2$ perfectly.

## Intuition & Mathematical Observation
To find the height $H$, we rearrange the given formula:
1. Start with: $v^2 = 2 \cdot g \cdot H$
2. Substitute $v = c$: $c^2 = 2 \cdot g \cdot H$
3. Solve for $H$: $H = \frac{c^2}{2 \cdot g}$

Since the problem guarantees that $c^2$ is divisible by $2 \cdot g$, we can perform simple integer division to obtain the result. Given the constraints ($c \le 3000$), $c^2$ will be at most $9,000,000$, which fits well within a standard 32-bit integer. However, using `long long` is a best practice to ensure no overflow occurs during intermediate calculations.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given the formula v^2 = 2 * g * H.
 * We want to find the height H such that the velocity v equals the speed of light c.
 * Substituting v = c into the equation:
 * c^2 = 2 * g * H
 * H = c^2 / (2 * g)
 * 
 * Constraints:
 * 1 <= T <= 5000
 * 1 <= g <= 10
 * 1000 <= c <= 3000
 * 2 * g divides c^2.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long g, c;
        cin >> g >> c;
        
        // Calculate H = (c * c) / (2 * g)
        // Given that 2 * g always divides c^2, integer division is exact.
        long long h = (c * c) / (2 * g);
        
        cout << h << "\n";
    }
    
    return 0;
}
```