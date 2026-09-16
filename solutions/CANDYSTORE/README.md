# [Candy Store (CANDYSTORE)](https://www.codechef.com/problems/CANDYSTORE)

- **Difficulty Rating**: 429
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a daily target of selling $X$ chocolates. 
- For every chocolate sold up to the target $X$, Chef earns 1 rupee.
- For every chocolate sold beyond the target $X$, Chef earns 2 rupees.
Given the target $X$ and the actual number of chocolates sold $Y$, calculate the total earnings.

## Intuition & Mathematical Observation
The problem can be broken down into two simple cases based on the relationship between $X$ and $Y$:

1. **Case 1: $Y \le X$**
   Chef has not exceeded the target. Every chocolate sold earns 1 rupee.
   - **Formula**: $\text{Earnings} = Y \times 1 = Y$

2. **Case 2: $Y > X$**
   Chef earns 1 rupee for the first $X$ chocolates and 2 rupees for the remaining $(Y - X)$ chocolates.
   - **Formula**: $\text{Earnings} = (X \times 1) + ((Y - X) \times 2)$
   - This simplifies to: $X + 2Y - 2X = 2Y - X$

By implementing these two conditions using an `if-else` statement, we can determine the total earnings efficiently.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a goal X.
 * If Y <= X, he earns 1 rupee per chocolate sold. Total = Y * 1.
 * If Y > X, he earns 1 rupee for the first X chocolates, and 2 rupees for each extra chocolate (Y - X).
 * Total = X + (Y - X) * 2.
 * 
 * Constraints are small (X, Y <= 10), so standard integer types are sufficient.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        if (y <= x) {
            // Goal not exceeded
            cout << y << "\n";
        } else {
            // Goal exceeded: X chocolates at 1 rupee, (Y-X) chocolates at 2 rupees
            long long total = x + (y - x) * 2;
            cout << total << "\n";
        }
    }
    
    return 0;
}
```