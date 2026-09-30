# [Equalizing Numbers (EQLZING)](https://www.codechef.com/problems/EQLZING)

- **Difficulty Rating**: 823
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we are allowed to perform the following operation: choose an integer $d$ and update $A \to A + d$ and $B \to B - d$. The goal is to determine if it is possible to make $A$ and $B$ equal after exactly one such operation.

## Intuition & Mathematical Observation
Let the final equal value be $X$. After the operation, we must have:
1. $A + d = X$
2. $B - d = X$

Adding these two equations together:
$(A + d) + (B - d) = X + X$
$A + B = 2X$

This implies that for $A$ and $B$ to become equal, their sum $(A + B)$ must be an **even number**. 

Alternatively, consider the difference between the two numbers:
$(A + d) - (B - d) = 0$
$A - B + 2d = 0$
$2d = B - A$
$d = \frac{B - A}{2}$

For $d$ to be an integer, $(B - A)$ must be divisible by 2. This is equivalent to saying that $A$ and $B$ must have the same parity (both even or both odd). If the difference $|A - B|$ is even, we can always find an integer $d$ to equalize them. If the difference is odd, it is impossible.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple parity check using the modulo operator. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can change A and B by adding/subtracting d.
 * The sum (A + B) remains invariant.
 * For A and B to be equal, A must equal B, so A + B must be 2*A (even).
 * If (A + B) is odd, it is impossible to make them equal.
 * If (A + B) is even, the difference (A - B) is even, and we can 
 * reach equality by choosing d = (B - A) / 2.
 */

void solve() {
    int A, B;
    cin >> A >> B;
    
    // Check if the difference is even (or if both have the same parity)
    if (abs(A - B) % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```