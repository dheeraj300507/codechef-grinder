# [The Cooler Dilemma 1 (WATERCOOLER1)](https://www.codechef.com/problems/WATERCOOLER1)

- **Difficulty Rating**: 506
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to keep his water cool for $M$ months. He has two options:
1. **Rent** a cooler for $X$ amount per month.
2. **Purchase** a cooler for a one-time cost of $Y$.

We need to determine if the total cost of renting the cooler for $M$ months is **strictly less** than the cost of purchasing it. If it is, output `YES`; otherwise, output `NO`.

## Intuition & Mathematical Observation
The problem asks us to compare two values:
*   **Total Renting Cost**: $X \times M$
*   **Purchase Cost**: $Y$

The condition for renting to be the better (cheaper) option is:
$$X \times M < Y$$

If this inequality holds true, Chef should rent the cooler (`YES`). If the renting cost is equal to or greater than the purchase cost, Chef should purchase the cooler (`NO`).

**Note on Constraints:** 
Given $X, M \le 10^4$ and $Y \le 10^8$, the product $X \times M$ can reach $10^8$. While this fits within a standard 32-bit integer, using `long long` is a best practice in competitive programming to avoid any potential overflow issues during intermediate calculations.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations and comparisons, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef rents if (X * M) < Y.
 * Otherwise, he purchases (NO).
 * 
 * Constraints:
 * X, M <= 10^4, Y <= 10^8.
 * X * M can be up to 10^8, which fits in a standard 32-bit signed integer.
 * However, using long long is safer practice in competitive programming to prevent
 * potential overflow if constraints were slightly larger.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, m;
        cin >> x >> y >> m;
        
        // Calculate total cost of renting
        long long rent_cost = x * m;
        
        // Check if renting is strictly less than purchasing
        if (rent_cost < y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```