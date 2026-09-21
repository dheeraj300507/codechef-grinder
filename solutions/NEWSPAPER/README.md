# [Sports Section (NEWSPAPER)](https://www.codechef.com/problems/NEWSPAPER)

- **Difficulty Rating**: 272
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a given page number $X$ (where $1 \le X \le 10$) belongs to the "sports section" of a newspaper. The sports section is defined as the last 3 pages of the 10-page newspaper, which are pages 8, 9, and 10. We need to output "YES" if the page is in the sports section and "NO" otherwise.

## Intuition & Mathematical Observation
The newspaper consists of pages $\{1, 2, 3, 4, 5, 6, 7, 8, 9, 10\}$. 
The sports section consists of the set $\{8, 9, 10\}$.

By observing the range, we can see that any page $X$ is in the sports section if and only if:
$$X \ge 8$$

Since the input constraints guarantee $1 \le X \le 10$, a simple conditional check `if (X >= 8)` is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison regardless of the input value.
- **Space Complexity**: $O(1)$ — No additional data structures are used; we only store a single integer.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * The newspaper has 10 pages (1 to 10).
 * The last 3 pages are 8, 9, and 10.
 * Given 1 <= X <= 10, the condition "last 3 pages" is satisfied if X >= 8.
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize standard I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    if (std::cin >> X) {
        // Check if the page is 8, 9, or 10
        if (X >= 8) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
```