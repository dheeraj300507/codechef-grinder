# [IPL and RCB (CLIPLX)](https://www.codechef.com/problems/CLIPLX)

- **Difficulty Rating**: 1167
- **Solved in**: 2 attempt(s)

## Problem Summary
In the IPL, a team earns 2 points for a win and 1 point for a tie. Given the total points $X$ a team has earned and the total number of matches $Y$ they have played, we need to find the **minimum** number of matches the team must have won. If it is impossible to achieve $X$ points in $Y$ matches, the problem implies we should find the minimum wins required to satisfy the conditions.

## Intuition & Mathematical Observation
Let $w$ be the number of wins and $t$ be the number of ties. The total number of matches played is $Y$, and the total points earned is $X$.
1. $2w + t = X$ (Points equation)
2. $w + t \le Y$ (Matches constraint: the number of wins and ties cannot exceed total matches played)

From the first equation, we can express ties as:
$t = X - 2w$

Substitute this into the second inequality:
$w + (X - 2w) \le Y$
$X - w \le Y$
$w \ge X - Y$

Since the number of wins cannot be negative, $w$ must be at least $0$. Therefore, the minimum number of wins required is:
$w_{min} = \max(0, X - Y)$

- If $X \le Y$, we can achieve the points using only ties (or a mix), so 0 wins are required.
- If $X > Y$, we are forced to win at least $X - Y$ matches to make up the point deficit.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic comparison.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the minimum number of wins (w) such that:
 * 2*w + t = X
 * w + t <= Y
 * 
 * Substituting t = X - 2*w into the inequality w + t <= Y:
 * w + (X - 2*w) <= Y
 * X - w <= Y
 * w >= X - Y
 * 
 * Since w must also be non-negative, w >= max(0, X - Y).
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;
    
    // If X <= Y, we can achieve X points using only ties (w=0).
    // If X > Y, we must win at least (X - Y) matches to reach the target.
    if (X <= Y) {
        cout << 0 << "\n";
    } else {
        cout << (X - Y) << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}
```