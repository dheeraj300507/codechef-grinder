# [Add to make Positive (ADDPOS)](https://www.codechef.com/problems/ADDPOS)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the smallest non-negative integer $X$ such that the sum of all elements in the modified array (where each element $A_i$ becomes $A_i + X$) is greater than or equal to $0$.

## Intuition & Mathematical Observation
Let the modified array be $A'$, where $A'_i = A_i + X$. We require:
$$\sum_{i=1}^{N} (A_i + X) \ge 0$$

Expanding the summation:
$$\sum_{i=1}^{N} A_i + \sum_{i=1}^{N} X \ge 0$$
$$\sum_{i=1}^{N} A_i + N \cdot X \ge 0$$

Let $S = \sum_{i=1}^{N} A_i$. The inequality becomes:
$$S + N \cdot X \ge 0$$
$$N \cdot X \ge -S$$

1. **If $S \ge 0$**: The condition is already satisfied with $X = 0$, which is the smallest non-negative integer.
2. **If $S < 0$**: We need $X \ge \frac{-S}{N}$. Since $X$ must be an integer, we take the ceiling of the division: $X = \lceil \frac{-S}{N} \rceil$.

In integer arithmetic, the ceiling of $\frac{a}{b}$ (where $a, b > 0$) can be calculated as `(a + b - 1) / b`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to find the minimum non-negative integer X such that:
 * Sum(A_i + X) >= 0 for all i from 1 to N.
 * 
 * Expanding the sum:
 * Sum(A_i) + N * X >= 0
 * N * X >= -Sum(A_i)
 * X >= -Sum(A_i) / N
 */

void solve() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum += a;
    }

    if (sum >= 0) {
        cout << 0 << "\n";
    } else {
        // We need N * X >= -sum
        // X = ceil(-sum / N)
        // Using integer arithmetic: (numerator + denominator - 1) / denominator
        long long target = -sum;
        long long x = (target + N - 1) / N;
        cout << x << "\n";
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