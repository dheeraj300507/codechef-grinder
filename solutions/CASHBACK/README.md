# [Cashback (CASHBACK)](https://www.codechef.com/problems/CASHBACK)

- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to calculate the final price of a cake after applying a cashback policy. If the price of the cake $X$ is 200 or more, the customer receives a cashback of 50 rupees. If the price is less than 200, no cashback is provided. We need to output the effective price paid by the customer.

## Intuition & Mathematical Observation
The problem follows a simple conditional logic based on the input value $X$:
1. **Condition 1**: If $X \ge 200$, the effective price is $X - 50$.
2. **Condition 2**: If $X < 200$, the effective price remains $X$.

The initial attempt failed because it incorrectly anticipated multiple test cases ($T$). Since the problem statement specifies a single integer input, the solution was adjusted to read only one integer and apply the conditional logic directly.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of arithmetic and comparison operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * The problem asks for the effective price of a cake.
 * Input: A single integer X (100 <= X <= 500).
 * Logic:
 * - If X >= 200, the customer gets 50 rupees back. Effective price = X - 50.
 * - If X < 200, no cashback. Effective price = X.
 */

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    // Read the single integer X as specified in the problem format
    if (std::cin >> x) {
        if (x >= 200) {
            std::cout << (x - 50) << std::endl;
        } else {
            std::cout << x << std::endl;
        }
    }

    return 0;
}
```