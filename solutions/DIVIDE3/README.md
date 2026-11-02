# [Divide into 3 (DIVIDE3)](https://www.codechef.com/problems/DIVIDE3)

- **Difficulty Rating**: 350
- **Solved in**: 3 attempt(s)

## Problem Summary
Given $N$ toffees, we need to distribute them among 3 friends such that the difference between the maximum and minimum number of toffees received by any friend is minimized. We need to output this minimum possible difference.

## Intuition & Mathematical Observation
To minimize the difference between the maximum and minimum values, we should distribute the toffees as evenly as possible. According to the division algorithm, any integer $N$ can be expressed as $N = 3q + r$, where $r \in \{0, 1, 2\}$.

1.  **Case $r = 0$**: We can distribute $q$ toffees to each friend.
    *   Distribution: $(q, q, q)$
    *   Difference: $q - q = 0$.
2.  **Case $r = 1$**: We can distribute $q, q,$ and $q+1$ toffees.
    *   Distribution: $(q, q, q+1)$
    *   Difference: $(q+1) - q = 1$.
3.  **Case $r = 2$**: We can distribute $q, q+1,$ and $q+1$ toffees.
    *   Distribution: $(q, q+1, q+1)$
    *   Difference: $(q+1) - q = 1$.

**Conclusion**: If $N$ is perfectly divisible by 3, the minimum difference is **0**. Otherwise, the minimum difference is **1**.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a single constant-time modulo operation.
- **Space Complexity**: $O(1)$, as we only use a single variable to store the input.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * We have N toffees to be divided among 3 friends.
 * Let the number of toffees given to the three friends be a, b, and c.
 * We have a + b + c = N.
 * We want to minimize (max(a, b, c) - min(a, b, c)).
 * 
 * By the division algorithm, N = 3 * q + r, where r is 0, 1, or 2.
 * - If r = 0: We can give each friend q toffees. Imbalance = q - q = 0.
 * - If r = 1: We can give friends q, q, and q+1 toffees. Imbalance = (q+1) - q = 1.
 * - If r = 2: We can give friends q, q+1, and q+1 toffees. Imbalance = (q+1) - q = 1.
 * 
 * Thus, if N is divisible by 3, the answer is 0. Otherwise, the answer is 1.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (std::cin >> n) {
        if (n % 3 == 0) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }
    
    return 0;
}
```