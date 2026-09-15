# [Insurance (INSURANCE)](https://www.codechef.com/problems/INSURANCE)

- **Difficulty Rating**: 475
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the insurance rebate for a repair cost $Y$, given a maximum rebate limit $X$. If the repair cost $Y$ is less than or equal to the limit $X$, the insurance company covers the entire cost ($Y$). If the repair cost $Y$ exceeds the limit $X$, the insurance company only covers the maximum rebate amount ($X$).

## Intuition & Mathematical Observation
The logic follows a simple conditional rule:
- If $Y \le X$, the rebate is $Y$.
- If $Y > X$, the rebate is $X$.

Mathematically, this is equivalent to finding the minimum of the two values:
$$\text{Rebate} = \min(X, Y)$$

By comparing the two inputs, we can directly output the smaller value to satisfy the insurance policy requirements.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single comparison and output.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The insurance policy states:
 * - Maximum rebate is X.
 * - If damage Y <= X, rebate is Y.
 * - If damage Y > X, rebate is X.
 * This is equivalent to finding the minimum of X and Y: min(X, Y).
 * 
 * Constraints: 1 <= X, Y <= 30.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
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
        
        // The rebate is the smaller of the repair cost (y) and the cap (x)
        if (y <= x) {
            cout << y << "\n";
        } else {
            cout << x << "\n";
        }
    }
    
    return 0;
}
```