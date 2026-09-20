# [Cup Finals (CRICUP)](https://www.codechef.com/problems/CRICUP)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a cricket match between two teams with skill levels $X$ and $Y$ is "interesting." A match is considered interesting if the absolute difference between the skill levels of the two teams is at most $D$. Given $T$ test cases, we need to output "YES" if the condition $|X - Y| \le D$ is met, and "NO" otherwise.

## Intuition & Mathematical Observation
The core of the problem is to calculate the absolute difference between two integers $X$ and $Y$. In C++, this is efficiently handled by the `abs()` function from the `<cmath>` or `<cstdlib>` library. 

1. For each test case, we read the three integers $X, Y,$ and $D$.
2. We compute the absolute difference: `diff = abs(X - Y)`.
3. We compare `diff` with $D$. If `diff <= D`, the condition is satisfied.
4. Since the constraints are small ($X, Y, D \le 100$), this approach is highly efficient and avoids any potential overflow issues.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant time arithmetic operation and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two skill levels X and Y, and a maximum allowed difference D.
 * The condition for the game to be interesting is |X - Y| <= D.
 * 
 * Constraints:
 * T <= 2000
 * 1 <= X, Y <= 100
 * 0 <= D <= 100
 * 
 * Since the values are small, standard integer types are sufficient.
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
        int x, y, d;
        cin >> x >> y >> d;
        
        // Calculate absolute difference
        int diff = abs(x - y);
        
        // Check if difference is within the allowed limit
        if (diff <= d) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```