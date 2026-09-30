# [Construct N (CONN)](https://www.codechef.com/problems/CONN)

- **Difficulty Rating**: 860
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, determine if it is possible to represent $N$ as $2X + 7Y$, where $X$ and $Y$ are non-negative integers. In other words, can we form the value $N$ using only coins of denominations 2 and 7?

## Intuition & Mathematical Observation
This problem is a variation of the **Frobenius Coin Problem**. We need to check if $N$ can be expressed as a linear combination of 2 and 7 with non-negative coefficients.

1.  **Even Numbers**: Any even number $N \ge 0$ can be represented as $2 \times (N/2)$. Thus, all non-negative even numbers are possible.
2.  **Odd Numbers**: Since $2X$ is always even, to get an odd sum $N$, we must use an odd number of 7s. The simplest case is using exactly one 7 ($Y=1$).
    *   If we use one 7, the remaining value is $N - 7$.
    *   For this to be valid, $N - 7$ must be non-negative ($N \ge 7$) and even (which is guaranteed if $N$ is odd).
    *   Therefore, any odd number $N \ge 7$ is possible.
3.  **Impossible Cases**:
    *   $N=1$: Cannot be formed (too small).
    *   $N=3$: Cannot be formed (too small).
    *   $N=5$: Cannot be formed (too small).
    *   All other positive integers are representable.

**Conclusion**: The only impossible values for $N$ are 1, 3, and 5.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we use no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find non-negative integers X and Y such that 2X + 7Y = N.
 * 
 * Logic:
 * - If N is even, it is always possible (N = 2 * (N/2)).
 * - If N is odd, we need at least one 7. If N >= 7, then (N - 7) is even 
 *   and non-negative, which can be filled by 2s.
 * - The only values that fail this are 1, 3, and 5.
 */

void solve() {
    long long N;
    cin >> N;

    // Check for the impossible cases identified
    if (N == 1 || N == 3 || N == 5) {
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