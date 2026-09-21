# [Football Cup (FOOTCUP)](https://www.codechef.com/problems/FOOTCUP)

- **Difficulty Rating**: 412
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef considers a football match "good" if and only if the match ends in a draw (both teams score the same number of goals) and at least one goal has been scored by each team (meaning the score is not 0-0). Given the scores of two teams, $X$ and $Y$, determine if the match is "good."

## Intuition & Mathematical Observation
To satisfy Chef's criteria, two conditions must be met simultaneously:
1. **The match is a draw**: This implies $X = Y$.
2. **At least one goal is scored**: This implies $X > 0$ and $Y > 0$.

Since the first condition ($X = Y$) ensures that if $X > 0$, then $Y$ is automatically $> 0$, we can simplify the logic to:
*   **Condition**: `(X == Y) && (X > 0)`

If both conditions are true, output `YES`; otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and do not use any auxiliary data structures that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef likes a match if:
 * 1. The match ends in a draw (X == Y).
 * 2. At least one goal has been scored (X > 0 or Y > 0).
 * 
 * Combining these, the condition is: (X == Y) AND (X > 0).
 * Since X == Y, if X > 0, then Y must also be > 0.
 * Thus, the condition simplifies to: (X == Y) && (X > 0).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // Check if it's a draw and at least one goal was scored
        if (x == y && x > 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```