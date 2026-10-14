# [Make N Zero (MAKENZERO)](https://www.codechef.com/problems/MAKENZERO)

- **Difficulty Rating**: 846
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to determine if a given integer $N$ can be represented as a sum of the form $3a + 4b$, where $a$ and $b$ are non-negative integers ($a, b \ge 0$).

## Intuition & Mathematical Observation
This problem is a specific instance of the **Frobenius Coin Problem** (also known as the Chicken McNugget Theorem). We are looking for values of $N$ that can be expressed as a linear combination of 3 and 4 with non-negative coefficients.

Let's test small values of $N$:
- $N=0$: $3(0) + 4(0) = 0$ (YES)
- $N=1$: Impossible (NO)
- $N=2$: Impossible (NO)
- $N=3$: $3(1) + 4(0) = 3$ (YES)
- $N=4$: $3(0) + 4(1) = 4$ (YES)
- $N=5$: Impossible (NO)
- $N=6$: $3(2) + 4(0) = 6$ (YES)
- $N=7$: $3(1) + 4(1) = 7$ (YES)
- $N=8$: $3(0) + 4(2) = 8$ (YES)

By observing the pattern, we see that for any $N \ge 6$, we can always represent $N$ as $3a + 4b$. Specifically, if we can represent $N$, we can represent $N+3$ by simply incrementing $a$. Since we can represent 3, 4, and 5+1=6, all subsequent integers are reachable.

The only integers that cannot be represented are **1, 2, and 5**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only a constant number of comparisons.
- **Space Complexity**: $O(1)$, as no extra data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 3*a + 4*b = N, where a, b >= 0.
 * Based on the Frobenius Coin Problem logic for 3 and 4:
 * - 1, 2, and 5 are impossible to form.
 * - 0, 3, 4, and all integers >= 6 are possible.
 */

void solve() {
    int n;
    cin >> n;
    
    // Check the impossible cases identified in the analysis
    if (n == 1 || n == 2 || n == 5) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
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