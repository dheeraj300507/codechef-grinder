# [Lucky Clover (LUCLO)](https://www.codechef.com/problems/LUCLO)

- **Difficulty Rating**: 236
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ clovers in total. Among these, exactly one clover is a four-leaf clover, and the remaining $(N - 1)$ clovers are three-leaf clovers. The goal is to calculate the total number of leaves present across all $N$ clovers.

## Intuition & Mathematical Observation
To find the total number of leaves, we can break the problem down into two parts:
1. **The four-leaf clover**: This contributes exactly $4$ leaves.
2. **The three-leaf clovers**: Since there are $N$ total clovers and one is a four-leaf clover, there are $(N - 1)$ clovers with $3$ leaves each.

The total number of leaves $L$ can be expressed as:
$$L = (1 \times 4) + ((N - 1) \times 3)$$

Simplifying the expression:
$$L = 4 + 3N - 3$$
$$L = 3N + 1$$

This linear formula holds true for all given constraints ($1 \le N \le 10$).

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a simple arithmetic calculation that executes in constant time regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N clovers.
 * Exactly one is a four-leaf clover.
 * The remaining (N - 1) are three-leaf clovers.
 * Total leaves = (1 * 4) + ((N - 1) * 3)
 * Total leaves = 4 + 3N - 3
 * Total leaves = 3N + 1
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read the single integer N from input
    if (cin >> N) {
        // Calculate total leaves using the derived formula 3N + 1
        long long total_leaves = 3LL * N + 1;
        cout << total_leaves << "\n";
    }

    return 0;
}
```