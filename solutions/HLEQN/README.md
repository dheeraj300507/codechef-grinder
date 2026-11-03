# [Hello Equation (HLEQN)](https://www.codechef.com/problems/HLEQN)

- **Difficulty Rating**: 1315
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, determine if there exist positive integers $a$ and $b$ ($a, b \ge 1$) such that the equation $2a + 2b + ab = X$ holds true.

## Intuition & Mathematical Observation
The given equation is $2a + 2b + ab = X$. This is a classic form that can be solved using **Simon's Favorite Factoring Trick**.

1.  **Rearrange the equation**:
    $ab + 2a + 2b = X$
2.  **Add 4 to both sides** to make the expression factorable:
    $ab + 2a + 2b + 4 = X + 4$
    $(a + 2)(b + 2) = X + 4$
3.  **Substitution**:
    Let $A = a + 2$ and $B = b + 2$. Since $a, b \ge 1$, it follows that $A, B \ge 3$.
    The problem reduces to finding if there exist two factors $A$ and $B$ of $(X + 4)$ such that both $A > 2$ and $B > 2$.
4.  **Algorithm**:
    - Calculate `target = X + 4`.
    - Iterate through all divisors $i$ of `target` starting from $3$ up to $\sqrt{target}$.
    - If $i$ is a divisor, calculate $j = target / i$.
    - If both $i > 2$ and $j > 2$, then a valid pair $(a, b)$ exists.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{X})$ per test case, as we iterate up to the square root of $X+4$ to find divisors. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The equation is 2a + 2b + ab = X.
 * Using Simon's Favorite Factoring Trick:
 * (a + 2)(b + 2) = X + 4
 * 
 * We need to check if there exist factors A and B of (X + 4) such that
 * A > 2 and B > 2.
 */

void solve() {
    long long X;
    cin >> X;
    long long target = X + 4;
    bool found = false;
    
    // We look for a divisor 'i' of 'target'
    // such that i > 2 and (target / i) > 2.
    // We only need to check up to sqrt(target).
    for (long long i = 3; i * i <= target; ++i) {
        if (target % i == 0) {
            long long j = target / i;
            if (i > 2 && j > 2) {
                found = true;
                break;
            }
        }
    }
    
    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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