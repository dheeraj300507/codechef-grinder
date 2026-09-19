# [Apples and Oranges (APPLORNG)](https://www.codechef.com/problems/APPLORNG)

- **Difficulty Rating**: 355
- **Solved in**: 1 attempt(s)

## Problem Summary
Bob has $X$ amount of money. He wants to purchase 1 kg of apples (costing $A$) and 1 kg of oranges (costing $B$). Determine if Bob has enough money to buy both items. If the total cost ($A + B$) is less than or equal to $X$, output "Yes"; otherwise, output "No".

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. 
1. We are given the total budget $X$.
2. We are given the individual costs $A$ and $B$.
3. The total cost required is the sum of the two items: $Total = A + B$.
4. We simply need to evaluate the boolean expression: $X \ge (A + B)$.

Since the constraints are $X, A, B \le 10^5$, the sum $A+B$ will not exceed $2 \times 10^5$, which fits comfortably within a standard 32-bit integer. Using `long long` is a good practice to avoid potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic and comparison operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input values, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Apples and Oranges
 * Logic: Bob needs to buy at least 1kg of apples (cost A) and 1kg of oranges (cost B).
 * Total cost = A + B.
 * Bob can afford this if X >= A + B.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X;
    if (!(cin >> X)) return 0;
    
    long long A, B;
    cin >> A >> B;

    // Check if the total cost is less than or equal to the money Bob has
    if (X >= (A + B)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```