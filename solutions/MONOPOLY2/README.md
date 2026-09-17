# [Monopoly (MONOPOLY2)](https://www.codechef.com/problems/MONOPOLY2)

- **Difficulty Rating**: 578
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the annual profits of four companies: $P, Q, R,$ and $S$. A "monopoly" is defined as a situation where one company's profit is strictly greater than the sum of the profits of the other three companies. We need to determine if a monopoly exists among the four companies.

## Intuition & Mathematical Observation
Let the profits be $P, Q, R,$ and $S$. Let the total profit be $T = P + Q + R + S$.

A company (e.g., company $P$) has a monopoly if:
$$P > (Q + R + S)$$

Since $Q + R + S = T - P$, we can rewrite the condition as:
$$P > T - P$$
$$2P > T$$

By checking this condition ($2 \times \text{profit} > \text{total}$) for each of the four companies, we can determine if any of them holds a monopoly. If the condition holds for at least one company, the answer is "YES"; otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values and the total sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A monopoly exists if any company's profit is strictly greater than the sum of the other three.
 * Let the profits be P, Q, R, S.
 * Total sum = P + Q + R + S.
 * For company A: P > (Q + R + S)
 * This is equivalent to: P > (Total - P)
 * Or: 2 * P > Total
 * We check this condition for all four companies.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p, q, r, s;
        cin >> p >> q >> r >> s;

        long long total = p + q + r + s;

        // Check if any company has a profit strictly greater than the sum of others
        // Condition: profit > (total - profit) => 2 * profit > total
        if ((2 * p > total) || (2 * q > total) || (2 * r > total) || (2 * s > total)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```