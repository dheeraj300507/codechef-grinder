# [Equalize AB (EQUALIZEAB)](https://www.codechef.com/problems/EQUALIZEAB)

- **Difficulty Rating**: 1069
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, and a fixed integer $X$, we can perform an operation any number of times: either add $X$ to $A$ and subtract $X$ from $B$, or subtract $X$ from $A$ and add $X$ to $B$. We need to determine if it is possible to make $A$ equal to $B$ using these operations.

## Intuition & Mathematical Observation
Let the initial values be $A$ and $B$. After performing the operation $k$ times (where $k$ can be positive or negative), the new values $A'$ and $B'$ become:
- $A' = A + k \cdot X$
- $B' = B - k \cdot X$

We want to reach a state where $A' = B'$. Setting these equal:
$$A + k \cdot X = B - k \cdot X$$
$$2 \cdot k \cdot X = B - A$$
$$k = \frac{B - A}{2 \cdot X}$$

For $A$ and $B$ to be equal, there must exist an integer $k$ that satisfies this equation. This implies that the difference $(B - A)$ must be perfectly divisible by $2 \cdot X$. 

**Key takeaways:**
1. If $A = B$, the condition is satisfied immediately (0 operations).
2. If $A \neq B$, we calculate the absolute difference $|A - B|$. If this difference is divisible by $2X$, then it is possible to equalize them; otherwise, it is impossible.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and a modulo check. Given $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with A and B. In one operation, we change (A, B) to (A+X, B-X) or (A-X, B+X).
 * Let the number of times we add X to A be 'k' (where k can be positive or negative).
 * The new values will be A' = A + k*X and B' = B - k*X.
 * We want A' = B'.
 * A + k*X = B - k*X
 * 2 * k * X = B - A
 * k = (B - A) / (2 * X)
 * 
 * For A and B to be equal, (B - A) must be divisible by (2 * X).
 * Since k must be an integer, (B - A) % (2 * X) must be 0.
 */

void solve() {
    long long A, B, X;
    cin >> A >> B >> X;

    // If A == B, they are already equal.
    if (A == B) {
        cout << "YES" << "\n";
        return;
    }

    // The difference between A and B changes by 2*X in each operation.
    // Let diff = |A - B|. We need diff to be divisible by 2*X.
    long long diff = abs(A - B);
    if (diff % (2 * X) == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
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