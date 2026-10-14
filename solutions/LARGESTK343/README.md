# [Largest K (LARGESTK343)](https://www.codechef.com/problems/LARGESTK343)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ zeros and $Y$ ones, we need to arrange them such that there are at least $K$ ones between any two adjacent zeros. The goal is to find the maximum possible integer value of $K$.

## Intuition & Mathematical Observation
To place $X$ zeros such that there is a gap between every adjacent pair, we create exactly $X - 1$ gaps. 

1. Let the number of ones placed in each gap be $g_1, g_2, \dots, g_{X-1}$.
2. The problem requires that each gap contains at least $K$ ones, meaning $g_i \ge K$ for all $i \in \{1, \dots, X-1\}$.
3. The total number of ones used in these gaps is $\sum_{i=1}^{X-1} g_i$.
4. Since we have a total of $Y$ ones available, the sum of ones in the gaps must not exceed $Y$:
   $$\sum_{i=1}^{X-1} g_i \le Y$$
5. To maximize $K$, we set each $g_i$ to the minimum required value, $K$. Thus, the total ones required is $K \times (X - 1)$.
6. The inequality becomes:
   $$K \times (X - 1) \le Y$$
7. Solving for $K$:
   $$K \le \frac{Y}{X - 1}$$
   Since $K$ must be an integer, the largest possible value is $\lfloor \frac{Y}{X - 1} \rfloor$.

*Note: If $X=1$, there are no gaps between zeros, so $K$ can technically be as large as $Y$ (or infinite depending on interpretation, but given the constraints, the formula holds for $X > 1$).*

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single division operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to place these zeros such that there are at least K ones between any two zeros.
 * If we have X zeros, there are (X - 1) gaps between them.
 * The minimum number of ones required to satisfy the condition is K * (X - 1).
 * Therefore, we need K * (X - 1) <= Y.
 * Solving for K: K <= Y / (X - 1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // If X is 1, there are no gaps, so K is effectively Y.
        // However, based on the problem constraints, we calculate:
        if (X <= 1) {
            cout << Y << "\n";
        } else {
            long long K = Y / (X - 1);
            cout << K << "\n";
        }
    }

    return 0;
}
```