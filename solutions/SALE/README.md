# [Get Lowest Free (SALE)](https://www.codechef.com/problems/SALE)

- **Difficulty Rating**: 778
- **Solved in**: 3 attempt(s)

## Problem Summary
Chef is buying three items with prices $A$, $B$, and $C$. The store has a "Buy 3, get the cheapest free" offer. We need to calculate the total amount Chef has to pay, which is the sum of the prices of the two most expensive items.

## Intuition & Mathematical Observation
The problem states that the cheapest item among the three is free. Mathematically, if we have three prices $A, B,$ and $C$, the total cost is the sum of all three items minus the minimum price among them:

$$\text{Total Cost} = (A + B + C) - \min(A, B, C)$$

By calculating the sum of all three inputs and subtracting the smallest value, we effectively ignore the price of the cheapest item, satisfying the condition of the offer.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the prices and the result, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef buys 3 items with prices A, B, and C.
 * The offer states that the cheapest item among the three is free.
 * Total cost = (A + B + C) - min(A, B, C).
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= A, B, C <= 10
 */

void solve() {
    int a, b, c;
    if (!(cin >> a >> b >> c)) return;

    // Calculate the sum of all three items
    int total_sum = a + b + c;
    
    // Find the minimum of the three items using initializer list
    int min_price = min({a, b, c});
    
    // The amount to pay is the total sum minus the cheapest item
    cout << (total_sum - min_price) << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}
```