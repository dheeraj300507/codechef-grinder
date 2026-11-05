# [Candy Love (CNDLOVE)](https://www.codechef.com/problems/CNDLOVE)

- **Difficulty Rating**: 1054
- **Solved in**: 1 attempt(s)

## Problem Summary
Sammy and Simmy are given $N$ bags of candies, where the $i$-th bag contains $A_i$ candies. They want to distribute all the candies such that:
1. Sammy gets $X$ candies and Simmy gets $Y$ candies, where $X + Y = \sum A_i$.
2. Sammy is happy if $X > Y$.
3. Simmy is happy if $|X - Y| \le 1$.

We need to determine if it is possible to distribute the candies such that both Sammy and Simmy are happy.

## Intuition & Mathematical Observation
Let $S$ be the total number of candies, $S = \sum A_i$.
We are given the conditions:
1. $X + Y = S$
2. $X > Y$
3. $|X - Y| \le 1$

From condition (3), the difference $X - Y$ can be $-1, 0,$ or $1$. Since condition (2) requires $X > Y$, the only possible value for $X - Y$ is $1$.
Substituting $X = Y + 1$ into the first equation:
$(Y + 1) + Y = S \implies 2Y + 1 = S \implies 2Y = S - 1$

For $Y$ to be an integer, $S - 1$ must be even, which implies that **$S$ must be odd**.
- If $S$ is odd, we can set $Y = (S - 1) / 2$ and $X = (S + 1) / 2$. This satisfies $X > Y$ and $X - Y = 1$.
- If $S$ is even, $2Y = S - 1$ results in a non-integer $Y$, making it impossible to satisfy the conditions.

Thus, the problem reduces to checking if the total sum of candies is odd.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of bags. We iterate through the array once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum and the current bag count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the total number of candies: S = sum(A_i).
 * We need X + Y = S, X > Y, and |X - Y| <= 1.
 * This implies X - Y = 1.
 * Substituting: (Y + 1) + Y = S => 2Y = S - 1.
 * For Y to be an integer, S must be odd.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            total_sum += a;
        }

        // If total sum is odd, it's possible to satisfy both conditions.
        if (total_sum % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
```