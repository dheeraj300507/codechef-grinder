# [Bob at the Bank (BOBBANK)](https://www.codechef.com/problems/BOBBANK)

- **Difficulty Rating**: 481
- **Solved in**: 1 attempt(s)

## Problem Summary
Bob starts with an initial bank balance of $W$. Every month, he deposits $X$ amount and withdraws $Y$ amount. We need to calculate his total bank balance after $Z$ months.

## Intuition & Mathematical Observation
The problem can be modeled as a simple linear equation. 
1. Each month, the net change in Bob's balance is the difference between his deposit and his withdrawal: $(X - Y)$.
2. Over a period of $Z$ months, the total change in his balance will be $(X - Y) \times Z$.
3. To find the final balance, we add this total change to his initial balance $W$.

The formula is:
$$\text{Final Balance} = W + (X - Y) \times Z$$

Since the constraints for $W, X, Y, Z$ are up to $10^4$, the maximum possible value is approximately $10^8$, which fits within a standard 32-bit integer. However, using `long long` is a safe practice to avoid any potential overflow issues in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial balance = W
 * Monthly deposit = X
 * Monthly deduction = Y
 * Net change per month = (X - Y)
 * Total change after Z months = (X - Y) * Z
 * Final balance = W + (X - Y) * Z
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long w, x, y, z;
        cin >> w >> x >> y >> z;
        
        // Calculate final balance using the derived formula
        long long final_balance = w + (x - y) * z;
        
        cout << final_balance << "\n";
    }
    
    return 0;
}
```