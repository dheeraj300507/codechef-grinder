# [Best Coupon (CHEAPFOOD)](https://www.codechef.com/problems/CHEAPFOOD)

- **Difficulty Rating**: 496
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a bill amount $X$. He has two coupons available:
1. A 10% discount on the bill amount.
2. A flat discount of 100 rupees.

The goal is to determine the maximum discount Chef can get from these two options for each given bill amount $X$.

## Intuition & Mathematical Observation
To maximize the discount, we simply need to compare the two options provided:
* **Option 1 (Percentage Discount):** The discount amount is $10\%$ of $X$, which is calculated as $X \times 0.10$ or simply $X / 10$.
* **Option 2 (Flat Discount):** The discount amount is fixed at $100$.

For every test case, we calculate both values and output the larger one using the `max()` function. Since the constraints state $100 \le X \le 10000$, both calculations will always result in valid integer values.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated discounts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a bill amount X.
 * Coupon 1: 10% discount = X * 0.10 = X / 10
 * Coupon 2: Flat discount = 100
 * We need to find the maximum of (X / 10) and 100.
 * 
 * Constraints:
 * 100 <= X <= 10000
 * X is a multiple of 100.
 * Time complexity per test case: O(1)
 * Space complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        // Calculate the two possible discounts
        long long discount1 = x / 10;
        long long discount2 = 100;
        
        // Output the maximum of the two
        cout << max(discount1, discount2) << "\n";
    }
    
    return 0;
}
```