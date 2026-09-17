# [Good Investment or Not (INVESTMENT)](https://www.codechef.com/problems/INVESTMENT)

- **Difficulty Rating**: 357
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if an investment is "good." An investment is considered good if the interest rate ($X$) is at least twice the inflation rate ($Y$). Given $T$ test cases, we need to output "YES" if $X \ge 2Y$, and "NO" otherwise.

## Intuition & Mathematical Observation
The condition provided is a direct comparison:
*   **Condition**: $X \ge 2 \times Y$

Since the constraints for $X$ and $Y$ are very small ($1 \le X, Y \le 20$), we can perform this calculation using standard integer arithmetic. For each test case, we simply read the two integers and evaluate the boolean expression. If the expression evaluates to true, we print "YES"; otherwise, we print "NO".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Since we perform a constant number of operations per test case, the solution runs well within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition for a "good" investment is:
 * Interest rate (X) >= 2 * Inflation rate (Y)
 * 
 * Constraints:
 * 1 <= T <= 400
 * 1 <= X, Y <= 20
 * 
 * Since X and Y are small integers, standard integer types (int) are sufficient.
 * Time Complexity: O(T) per test case, which is well within the 1s limit.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int x, y;
        cin >> x >> y;

        // Check if interest rate is at least twice the inflation rate
        if (x >= 2 * y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```