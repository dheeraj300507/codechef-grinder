# [Broken Phone (BROKENPHONE)](https://www.codechef.com/problems/BROKENPHONE)

- **Difficulty Rating**: 451
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the most cost-effective way to deal with a broken phone. We are given two values:
*   **X**: The cost to repair the broken phone.
*   **Y**: The cost to buy a new phone.

We need to output:
*   `REPAIR` if repairing is cheaper than buying a new one ($X < Y$).
*   `NEW PHONE` if buying a new one is cheaper than repairing ($X > Y$).
*   `ANY` if both options cost the same ($X = Y$).

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. Since we are given two integers $X$ and $Y$, we simply need to apply conditional logic to compare their values:
1.  **Case 1 ($X < Y$):** The repair cost is strictly less than the new phone cost. Therefore, repairing is the optimal choice.
2.  **Case 2 ($X > Y$):** The new phone cost is strictly less than the repair cost. Therefore, buying a new phone is the optimal choice.
3.  **Case 3 ($X = Y$):** Both options result in the same expenditure, so either choice is acceptable.

Using `long long` for the variables is a safe practice to prevent potential overflow, although standard `int` would suffice given the typical constraints for this problem.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of extra space to store the input variables $X$ and $Y$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: BROKENPHONE
 * Logic:
 * Compare the cost of repair (X) and the cost of a new phone (Y).
 * If X < Y, output REPAIR.
 * If X > Y, output NEW PHONE.
 * If X == Y, output ANY.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
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
        
        if (x < y) {
            cout << "REPAIR" << "\n";
        } else if (x > y) {
            cout << "NEW PHONE" << "\n";
        } else {
            cout << "ANY" << "\n";
        }
    }
    
    return 0;
}
```