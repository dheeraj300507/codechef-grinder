# [Christmas Trees (XMASTREE)](https://www.codechef.com/problems/XMASTREE)

- **Difficulty Rating**: 300
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef buys $N$ Christmas trees at a cost of $A$ rupees each and sells $M$ Christmas trees at a price of $B$ rupees each. The goal is to calculate the total profit made by Chef, which is defined as the difference between the total revenue and the total cost.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. 
1. **Total Cost**: Chef spends $N \times A$ rupees to purchase the trees.
2. **Total Revenue**: Chef earns $M \times B$ rupees from selling the trees.
3. **Profit**: The profit is calculated by subtracting the total cost from the total revenue:
   $$\text{Profit} = (M \times B) - (N \times A)$$

Given the constraints ($N, M \le 100$ and $A, B \le 1000$), the maximum possible value is $100,000$, which comfortably fits within a standard 32-bit integer. However, using `long long` is a good practice to prevent potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — Only a few variables are used to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef bought N trees for A rupees each.
 * Chef sold M trees for B rupees each.
 * Total Cost = N * A
 * Total Revenue = M * B
 * Profit = (M * B) - (N * A)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, A, M, B;
    
    // Read the single line of input containing N, A, M, and B
    if (cin >> N >> A >> M >> B) {
        // Calculate total cost and total revenue
        long long total_cost = N * A;
        long long total_revenue = M * B;
        
        // Calculate profit
        long long profit = total_revenue - total_cost;
        
        // Output the result
        cout << profit << endl;
    }

    return 0;
}
```