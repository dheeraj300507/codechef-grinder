# [Number Reduction (RED23)](https://www.codechef.com/problems/RED23)

- **Difficulty Rating**: 727
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, we are allowed to perform two operations repeatedly:
1. If $X > 3$, replace $X$ with $X - 3$.
2. If $X$ is even, replace $X$ with $X / 2$.

The goal is to find the minimum possible value of $X$ that can be reached by applying these operations any number of times.

## Intuition & Mathematical Observation
By tracing the operations for small values of $X$, we can observe a clear pattern:

*   **$X=1$**: Cannot perform any operations. Result = **1**.
*   **$X=2$**: $2 \to 1$. Result = **1**.
*   **$X=3$**: Cannot perform any operations. Result = **3**.
*   **$X=4$**: $4 \to 2 \to 1$ or $4 \to 1$. Result = **1**.
*   **$X=5$**: $5 \to 2 \to 1$. Result = **1**.
*   **$X=6$**: $6 \to 3$ or $6 \to 3$. Result = **3**.
*   **$X=7$**: $7 \to 4 \to 1$. Result = **1**.
*   **$X=8$**: $8 \to 4 \to 1$. Result = **1**.
*   **$X=9$**: $9 \to 6 \to 3$. Result = **3**.

**Pattern:**
- If $X$ is a multiple of 3, the operations will eventually reduce the number to **3**.
- If $X$ is not a multiple of 3, the operations will eventually reduce the number to **1**.

This holds because subtracting 3 preserves the remainder modulo 3, and dividing by 2 (when $X$ is even) effectively allows us to reach values that eventually collapse into the remainder classes of 1 or 0 (mod 3).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single modulo operation and a conditional check.
- **Space Complexity**: $O(1)$, as we use a constant amount of extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two operations:
 * 1. If X > 3, X = X - 3
 * 2. If X is even, X = X / 2
 * 
 * Pattern Observation:
 * If X is a multiple of 3, the minimum value reachable is 3.
 * If X is not a multiple of 3, the minimum value reachable is 1.
 */

void solve() {
    int X;
    cin >> X;
    // If X is divisible by 3, the result is 3. Otherwise, it is 1.
    if (X % 3 == 0) {
        cout << 3 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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