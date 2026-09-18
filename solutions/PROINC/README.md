# [Profit Increment (PROINC)](https://www.codechef.com/problems/PROINC)

- **Difficulty Rating**: 414
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the initial selling price $X$ and the initial profit $Y$ of an item, we need to calculate the new profit after the selling price is increased by 10%. We are guaranteed that $X$ is a multiple of 100.

## Intuition & Mathematical Observation
To find the new profit, we first identify the cost price (buying price) of the item:
1. **Cost Price ($CP$):** Since $Profit = Selling Price - Cost Price$, we have $CP = X - Y$.
2. **New Selling Price ($SP_{new}$):** The price increases by 10%, so $SP_{new} = X + 0.1X = 1.1X$.
3. **New Profit ($P_{new}$):** The new profit is the difference between the new selling price and the constant cost price:
   $$P_{new} = SP_{new} - CP$$
   $$P_{new} = (1.1X) - (X - Y)$$
   $$P_{new} = 1.1X - X + Y$$
   $$P_{new} = 0.1X + Y$$

Since $X$ is a multiple of 100, $0.1X$ (or $X/10$) will always result in an integer, allowing us to compute the result using simple integer arithmetic.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial Selling Price = X
 * Initial Profit = Y
 * Buying Price (Cost Price) = X - Y
 * 
 * New Selling Price = X + (10% of X) = X + 0.1 * X = 1.1 * X
 * Since X is a multiple of 100, 0.1 * X will always be an integer.
 * 
 * New Profit = New Selling Price - Buying Price
 * New Profit = (1.1 * X) - (X - Y)
 * New Profit = 1.1 * X - X + Y
 * New Profit = 0.1 * X + Y
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Calculate new profit using the derived formula: 0.1 * X + Y
        // Since X is a multiple of 100, X/10 is always an integer.
        long long new_profit = (x / 10) + y;

        cout << new_profit << "\n";
    }

    return 0;
}
```