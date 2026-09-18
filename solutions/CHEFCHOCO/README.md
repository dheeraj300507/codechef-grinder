# [Chef and Chocolates (CHEFCHOCO)](https://www.codechef.com/problems/CHEFCHOCO)

- **Difficulty Rating**: 492
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef wants to have a total of $C$ chocolates. He currently possesses $X$ chocolates. Each additional chocolate costs $Y$ rupees. The goal is to calculate the total amount of money Chef needs to spend to acquire the remaining chocolates required to reach his target of $C$.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation:
1. **Determine the deficit**: Chef needs $C$ chocolates and already has $X$. The number of chocolates he needs to buy is $C - X$.
2. **Calculate the cost**: Since each of the $(C - X)$ chocolates costs $Y$ rupees, the total cost is simply $(C - X) \times Y$.

Given the constraints ($C, X, Y \le 100$), the result will always fit within a standard 32-bit integer, so no special handling for large numbers is required.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and the result, regardless of the input size.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs C chocolates in total.
 * Chef already has X chocolates.
 * Therefore, Chef needs to buy (C - X) chocolates.
 * Each chocolate costs Y rupees.
 * Total cost = (C - X) * Y.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= C <= 100
 * 0 <= X <= C
 * 1 <= Y <= 100
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int c, x, y;
        if (!(cin >> c >> x >> y)) break;
        
        // Calculate the number of chocolates needed
        int needed = c - x;
        
        // Calculate total cost
        // Since C, X, Y <= 100, the result fits in a standard int
        int cost = needed * y;
        
        // Output the result
        cout << cost << "\n";
    }
    
    return 0;
}
```