# [Stick Break (STICKBREAK)](https://www.codechef.com/problems/STICKBREAK)

- **Difficulty Rating**: 1123
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a stick of length $L$, we need to break it into $K$ pieces of integer lengths $A_1, A_2, \dots, A_K$ such that $\sum_{i=1}^{K} A_i = L$ and $A_i \ge 1$. The goal is to minimize the sum of absolute differences between adjacent pieces: $\sum_{i=1}^{K-1} |A_{i+1} - A_i|$.

## Intuition & Mathematical Observation
To minimize the sum of absolute differences, we want the values of $A_i$ to be as close to each other as possible. 

1.  **Even Distribution**: If we divide $L$ by $K$, we get a quotient $q = \lfloor L/K \rfloor$ and a remainder $r = L \pmod K$. 
2.  **Optimal Values**: The most uniform distribution possible is to have $r$ pieces of length $(q+1)$ and $(K-r)$ pieces of length $q$.
3.  **Minimizing Differences**:
    *   If $r = 0$, all pieces are exactly $q$. The difference between any two adjacent pieces is $|q - q| = 0$. Thus, the total sum is **0**.
    *   If $r > 0$, we have two types of values: $q$ and $q+1$. To minimize the sum of absolute differences, we should group all pieces of the same length together. For example, we can arrange them as:
        $$\underbrace{q+1, q+1, \dots, q+1}_{r \text{ times}}, \underbrace{q, q, \dots, q}_{K-r \text{ times}}$$
    *   In this arrangement, the only non-zero difference occurs at the single boundary where a $(q+1)$ piece is adjacent to a $q$ piece. The difference is $|q - (q+1)| = 1$. All other adjacent pairs have a difference of 0. Thus, the total sum is **1**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single modulo operation and a conditional check.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to minimize sum_{i=1}^{K-1} |A_{i+1} - A_i| subject to sum(A_i) = L, A_i >= 1.
 * 
 * If L is perfectly divisible by K, we can make all pieces equal to L/K, 
 * resulting in a sum of differences equal to 0.
 * 
 * If there is a remainder r = L % K, we have r pieces of size (L/K + 1) 
 * and (K-r) pieces of size (L/K). By grouping all (L/K + 1) pieces together 
 * and all (L/K) pieces together, we only incur a difference of 1 at the 
 * single transition point between the two groups.
 */

void solve() {
    long long L, K;
    cin >> L >> K;

    // If L is divisible by K, we can make all pieces equal.
    if (L % K == 0) {
        cout << 0 << "\n";
    } else {
        // Otherwise, the minimum difference is 1.
        cout << 1 << "\n";
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