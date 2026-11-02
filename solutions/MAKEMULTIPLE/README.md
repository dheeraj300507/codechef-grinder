# [Make Multiple (MAKEMULTIPLE)](https://www.codechef.com/problems/MAKEMULTIPLE)

- **Difficulty Rating**: 1163
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$ ($A \le B$), determine if there exists a non-negative integer $X$ such that $(A + X)$ is a divisor of $(B + X)$. In other words, we need to check if $(B + X) \pmod{A + X} = 0$ for some $X \ge 0$.

## Intuition & Mathematical Observation
Let $k = A + X$. Since $k$ must divide $B + X$, we can express $B + X$ as a multiple of $k$:
$B + X = m \cdot k$ for some integer $m \ge 1$.

Substituting $k = A + X$:
$B + X = m(A + X)$
$B + X = m \cdot A + m \cdot X$
$B - m \cdot A = X(m - 1)$

If $m = 1$, then $B - A = 0$, which implies $A = B$. In this case, $X = 0$ works.

If $m > 1$, we can rearrange the equation to:
$X = \frac{B - m \cdot A}{m - 1}$

For $X$ to be a non-negative integer, we need $B - m \cdot A \ge 0$, which means $B \ge m \cdot A$. 
Alternatively, consider the difference $D = B - A$. Since $(B + X) = (A + X) + (B - A)$, for $(A + X)$ to divide $(B + X)$, it must also divide the difference $(B - A)$. 

Thus, we need to find if there exists a divisor $d$ of $(B - A)$ such that $d \ge A$. The largest divisor of $(B - A)$ is $(B - A)$ itself. If $(B - A) \ge A$, we can simply choose $d = (B - A)$, which satisfies the condition. If $(B - A) < A$ and $(B - A) \neq 0$, no such divisor $d \ge A$ can exist because all divisors of $(B - A)$ are $\le (B - A) < A$.

**Conclusion:** The condition is satisfied if $A = B$ or $(B - A) \ge A$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exists X >= 0 such that (A + X) divides (B + X).
 * This is equivalent to checking if (A + X) divides (B - A).
 * We need a divisor 'd' of (B - A) such that d >= A.
 * The largest divisor of (B - A) is (B - A) itself.
 * If (B - A) >= A, we can set d = (B - A), which satisfies the condition.
 */

void solve() {
    long long A, B;
    cin >> A >> B;
    
    // If A == B, X = 0 works.
    // If B - A >= A, then (B - A) is a multiple of A, 
    // and we can find an X such that A + X = (B - A) or similar.
    if (A == B || (B - A) >= A) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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