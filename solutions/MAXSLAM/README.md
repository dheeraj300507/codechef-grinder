# [Maximum Slams (MAXSLAM)](https://www.codechef.com/problems/MAXSLAM)

- **Difficulty Rating**: 224
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef currently has $X$ Grand Slam titles. Each year, Chef wins exactly 4 additional Grand Slam titles. The goal is to determine the minimum number of years required for Chef to reach a total of at least 25 Grand Slam titles.

## Intuition & Mathematical Observation
To find the number of years $Y$, we set up the following inequality:
$$X + 4Y \ge 25$$

Rearranging to solve for $Y$:
$$4Y \ge 25 - X$$
$$Y \ge \frac{25 - X}{4}$$

Since $Y$ must be a non-negative integer, we need the ceiling of the division:
$$Y = \lceil \frac{25 - X}{4} \rceil$$

**Implementation Detail:**
In integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated using the formula `(a + b - 1) / b`. If $25 - X$ is less than or equal to 0, Chef has already reached the goal, so the answer is 0. Otherwise, we apply the ceiling formula to the remaining required wins.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — No additional data structures are used; only a few variables are stored.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Chef needs to reach a total of at least 25 Grand Slams.
 * Chef currently has X wins.
 * Each year, Chef wins 4 Grand Slams.
 * Let Y be the number of years.
 * We need: X + 4 * Y >= 25
 * 4 * Y >= 25 - X
 * Y >= (25 - X) / 4
 * Since Y must be an integer, Y = ceil((25 - X) / 4).
 * 
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b.
 * For (25 - X) / 4, this is (25 - X + 3) / 4.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long X;
    // The problem states the input is a single integer X.
    if (std::cin >> X) {
        long long needed = 25 - X;
        
        if (needed <= 0) {
            // Chef already has 25 or more wins
            std::cout << 0 << std::endl;
        } else {
            // Calculate ceiling of needed / 4
            // Formula: (numerator + denominator - 1) / denominator
            long long years = (needed + 3) / 4;
            std::cout << years << std::endl;
        }
    }

    return 0;
}
```