# [Expiring Bread (EXPIRY)](https://www.codechef.com/problems/EXPIRY)

- **Difficulty Rating**: 440
- **Solved in**: 1 attempt(s)

## Problem Summary
Eikooc has $N$ loaves of bread. The bread expires in $M$ days. She can consume at most $K$ loaves of bread per day. We need to determine if it is possible for her to finish all $N$ loaves of bread before or on the day they expire.

## Intuition & Mathematical Observation
The problem asks whether the total capacity to eat bread over the given timeframe is sufficient to cover the total number of loaves.

1.  **Total Capacity**: Since Eikooc can eat $K$ loaves every day for $M$ days, the maximum number of loaves she can consume is $M \times K$.
2.  **Condition**: 
    *   If $M \times K \geq N$, she has enough capacity to eat all the bread before it expires. Therefore, the answer is **"Yes"**.
    *   If $M \times K < N$, she will not be able to finish all the loaves before they expire. Therefore, the answer is **"No"**.

The constraints ($N, M, K \leq 100$) are small enough that a simple multiplication and comparison are sufficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Eikooc has N loaves of bread.
 * They expire in M days.
 * She can eat K loaves per day.
 * Total capacity to eat bread before expiration is M * K.
 * If M * K >= N, she can eat all the bread.
 * Otherwise, she cannot.
 * 
 * Constraints: N, M, K <= 100.
 * M * K can be at most 10,000, which fits in a standard integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        // Calculate total loaves she can eat within M days
        // Using long long to prevent any potential overflow, 
        // though int is sufficient for these constraints.
        if (m * k >= n) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```