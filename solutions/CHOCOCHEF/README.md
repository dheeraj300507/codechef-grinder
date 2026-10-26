# [Chocolate Distribution (CHOCOCHEF)](https://www.codechef.com/problems/CHOCOCHEF)

- **Difficulty Rating**: 1104
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to distribute $N$ chocolates into three jars ($a, b, c$) such that:
1. $a + b + c = N$
2. $a, b, c \ge 1$
3. Exactly two jars contain the same number of chocolates.
4. At least one jar contains an odd number of chocolates.

## Intuition & Mathematical Observation
To satisfy the condition that exactly two jars are equal, we can represent the jars as $(x, x, N - 2x)$. For this to be valid, we must ensure $N - 2x \ge 1$, which implies $x \le \frac{N-1}{2}$.

We can split the logic based on the parity of $N$:

*   **Case 1: $N$ is even**
    We can set $x = 1$. The distribution becomes $(1, 1, N-2)$.
    *   Since $N \ge 4$, $N-2 \ge 2$.
    *   The jars are $(1, 1, N-2)$. Two jars are equal (1 and 1).
    *   Since 1 is odd, the condition "at least one jar has an odd number of chocolates" is always satisfied.

*   **Case 2: $N$ is odd**
    We can set $x = \frac{N-1}{2}$. The distribution becomes $(\frac{N-1}{2}, \frac{N-1}{2}, 1)$.
    *   Since $N \ge 5$ (the smallest odd $N$ for which we can have 3 jars $\ge 1$ is 5), $x \ge 2$.
    *   The jars are $(\frac{N-1}{2}, \frac{N-1}{2}, 1)$. Two jars are equal.
    *   Since 1 is odd, the condition "at least one jar has an odd number of chocolates" is always satisfied.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N chocolates into three jars (a, b, c) such that:
 * 1. a + b + c = N
 * 2. At least one jar has an odd number of chocolates.
 * 3. Exactly two jars have the same number of chocolates.
 * 4. a, b, c >= 1
 */

void solve() {
    long long N;
    cin >> N;

    if (N % 2 == 0) {
        // Even N: (1, 1, N-2)
        // Two jars are 1, 1 (equal).
        // 1 is odd, satisfying the "at least one odd" condition.
        cout << 1 << " " << 1 << " " << (N - 2) << "\n";
    } else {
        // Odd N: ((N-1)/2, (N-1)/2, 1)
        // Two jars are (N-1)/2, (N-1)/2 (equal).
        // 1 is odd, satisfying the "at least one odd" condition.
        long long x = (N - 1) / 2;
        cout << x << " " << x << " " << 1 << "\n";
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