# [Exun Leaderboard (BETWEEN)](https://www.codechef.com/problems/BETWEEN)

- **Difficulty Rating**: 213
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$ representing the ranks of two teams on a leaderboard, determine the number of teams that are ranked strictly between them.

## Intuition & Mathematical Observation
To find the number of integers strictly between two numbers $X$ and $Y$ on a number line, we calculate the distance between them and subtract 1 (to exclude the endpoints themselves).

Mathematically, the number of integers between $X$ and $Y$ is given by:
$$\text{Result} = |X - Y| - 1$$

**Examples:**
*   If $X = 1$ and $Y = 5$: The numbers between them are $\{2, 3, 4\}$. $|1 - 5| - 1 = 4 - 1 = 3$.
*   If $X = 2$ and $Y = 1$: There are no numbers between them. $|2 - 1| - 1 = 1 - 1 = 0$.

Since the problem does not specify that $X < Y$, using the absolute difference `std::abs(x - y)` ensures the formula works regardless of the input order.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a single arithmetic operation regardless of the size of the input.
- **Space Complexity**: $O(1)$ as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

/**
 * Problem Analysis:
 * We are given two ranks X and Y. We need to find the number of teams 
 * strictly between them.
 * 
 * The number of integers strictly between X and Y is |X - Y| - 1.
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long x, y;
    if (std::cin >> x >> y) {
        // Calculate the absolute difference and subtract 1
        // Example: 1 and 5 -> |1 - 5| - 1 = 4 - 1 = 3
        // Example: 2 and 1 -> |2 - 1| - 1 = 1 - 1 = 0
        long long diff = std::abs(x - y) - 1;
        
        std::cout << diff << std::endl;
    }

    return 0;
}
```