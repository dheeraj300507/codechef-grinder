# [Time Complexity (COMPLEXITY)](https://www.codechef.com/problems/COMPLEXITY)

- **Difficulty Rating**: 364
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if Algorithm A has a higher time complexity than Algorithm B. We are given two integers, $X$ and $Y$, representing the number of operations performed by Algorithm A and Algorithm B, respectively. We need to output "YES" if $X > Y$, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. The condition for Algorithm A having more time complexity than Algorithm B is strictly defined as $X > Y$. 
- If the input $X$ is strictly greater than $Y$, the condition is satisfied.
- If $X$ is less than or equal to $Y$, the condition is not satisfied.

Since the constraints are small ($1 \le X, Y \le 100$), a simple `if-else` conditional statement is sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time comparison operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks us to compare two integers X and Y.
 * Algorithm A has more time complexity than B if X > Y.
 * If X > Y, we output "YES", otherwise "NO".
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X, Y <= 100
 * Time Complexity: O(T)
 * Space Complexity: O(1)
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
        
        // Check if algorithm A has more comparisons than algorithm B
        if (x > y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```