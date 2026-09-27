# [International Education Day! (IED)](https://www.codechef.com/problems/IED)

- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Chefina are selling courses. Chef sells $A$ courses at a price of $C$ each, while Chefina sells $B$ courses at the same price of $C$ each. We need to determine the maximum total revenue generated between the two of them.

## Intuition & Mathematical Observation
The problem asks us to compare the total revenue of Chef and Chefina.
- Chef's total revenue is calculated as: $\text{Revenue}_{\text{Chef}} = A \times C$
- Chefina's total revenue is calculated as: $\text{Revenue}_{\text{Chefina}} = B \times C$

Since we need to find the maximum of these two values, we simply compute both products and output the larger one using the `max()` function. Given the constraints, using `long long` is a safe practice to prevent potential integer overflow, although standard `int` would suffice for the given problem limits.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: International Education Day!
 * The problem asks us to calculate the total sales for Chef (A * C) and Chefina (B * C)
 * and output the maximum of the two.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading inputs A, B, and C
    long long A, B, C;
    if (cin >> A >> B >> C) {
        long long chef_sales = A * C;
        long long chefina_sales = B * C;
        
        // Output the maximum of the two sales
        cout << max(chef_sales, chefina_sales) << "\n";
    }

    return 0;
}
```