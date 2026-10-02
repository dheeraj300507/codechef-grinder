# [Christmas Cake (CRCK)](https://www.codechef.com/problems/CRCK)

- **Difficulty Rating**: 217
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef wants to bake a cake every day starting from day $X$ up to and including December 24th. Given the integer $X$ (where $1 \le X \le 24$), we need to calculate the total number of cakes Chef will bake.

## Intuition & Mathematical Observation
The problem asks for the count of integers in the inclusive range $[X, 24]$. 

To find the number of integers in an inclusive range $[A, B]$, the formula is:
$$\text{Count} = (B - A) + 1$$

Substituting our values:
$$\text{Count} = (24 - X) + 1$$
$$\text{Count} = 25 - X$$

For example, if $X = 24$, Chef bakes $25 - 24 = 1$ cake. If $X = 23$, Chef bakes $25 - 23 = 2$ cakes (on the 23rd and 24th). The logic holds for all $1 \le X \le 24$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single subtraction operation regardless of the input size.
- **Space Complexity**: $O(1)$ — We only store a single integer variable, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Chef bakes a cake every day from today (X) until the 24th of December.
 * The number of days from X to 24 inclusive is calculated as:
 * (24 - X) + 1 = 25 - X
 * 
 * Constraints: 1 <= X <= 24.
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    // Read the single integer X
    if (std::cin >> X) {
        // Calculate the number of cakes: 25 - X
        int result = 25 - X;
        
        std::cout << result << std::endl;
    }

    return 0;
}
```