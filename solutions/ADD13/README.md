# [Add 1 or 3 (ADD13)](https://www.codechef.com/problems/ADD13)

- **Difficulty Rating**: 1003
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $M$, determine if it is possible to reach the sum $M$ by performing exactly $N$ operations, where each operation consists of adding either $1$ or $3$ to the current total.

## Intuition & Mathematical Observation
Let $a$ be the number of times we add $1$, and $b$ be the number of times we add $3$. We are given two constraints based on the problem statement:

1. **Total operations**: $a + b = N$
2. **Total sum**: $1 \cdot a + 3 \cdot b = M$

We can solve this system of linear equations:
* From the first equation, $a = N - b$.
* Substitute this into the second equation: $(N - b) + 3b = M$.
* Simplifying gives: $N + 2b = M$, which implies $2b = M - N$.

For a valid solution to exist, $a$ and $b$ must be non-negative integers. This leads to three necessary conditions:
1. **$b \ge 0$**: Since $2b = M - N$, we must have $M - N \ge 0$, or **$M \ge N$**.
2. **$b$ is an integer**: $M - N$ must be divisible by 2, or **$(M - N) \pmod 2 == 0$**.
3. **$a \ge 0$**: Since $a = N - b$, we need $N \ge b$. Substituting $b = \frac{M - N}{2}$:
   $N \ge \frac{M - N}{2} \implies 2N \ge M - N \implies 3N \ge M$, or **$M \le 3N$**.

If all three conditions are met, it is possible to reach the sum $M$ in $N$ steps.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic comparisons. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We derived that for a valid solution:
 * 1) M >= N
 * 2) (M - N) % 2 == 0
 * 3) M <= 3 * N
 */

void solve() {
    long long N, M;
    cin >> N >> M;

    // Check the three derived conditions
    if (M >= N && (M - N) % 2 == 0 && M <= 3 * N) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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