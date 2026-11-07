# [Pizza Comparision (PIZZACOMP)](https://www.codechef.com/problems/PIZZACOMP)

- **Difficulty Rating**: 599
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two types of square pizzas:
1. A small pizza with a side length of 10 units, costing $A$ rupees.
2. A large pizza with a side length of 15 units, costing $B$ rupees.

We need to determine which pizza offers more "area per rupee." If the value is the same, we output "Equal."

## Intuition & Mathematical Observation
To find the best value, we calculate the area of each pizza:
- **Small Pizza Area**: $10 \times 10 = 100$
- **Large Pizza Area**: $15 \times 15 = 225$

The value (area per rupee) for each is:
- **Small Value**: $\frac{100}{A}$
- **Large Value**: $\frac{225}{B}$

To compare these fractions without using floating-point arithmetic (which can lead to precision errors), we use the cross-multiplication method:
- Compare $\frac{100}{A}$ and $\frac{225}{B}$ by comparing $100 \times B$ and $225 \times A$.

If $100 \times B > 225 \times A$, the small pizza is better. If $225 \times A > 100 \times B$, the large pizza is better. Otherwise, they are equal.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Small pizza: side = 10, area = 10 * 10 = 100. Cost = A.
 * Amount per rupee for Small = 100 / A.
 * Large pizza: side = 15, area = 15 * 15 = 225. Cost = B.
 * Amount per rupee for Large = 225 / B.
 * 
 * We compare 100/A and 225/B using cross-multiplication:
 * 100 * B vs 225 * A
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long A, B;
        cin >> A >> B;

        // Calculate cross products
        long long small_val = 100 * B;
        long long large_val = 225 * A;

        if (small_val > large_val) {
            cout << "Small" << "\n";
        } else if (large_val > small_val) {
            cout << "Large" << "\n";
        } else {
            cout << "Equal" << "\n";
        }
    }

    return 0;
}
```