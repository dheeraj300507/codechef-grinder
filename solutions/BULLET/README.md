# [Mario and Bullet (BULLET)](https://www.codechef.com/problems/BULLET)

- **Difficulty Rating**: 650
- **Solved in**: 1 attempt(s)

## Problem Summary
Mario wants to hit a Goomba located at a distance $Y$ using a bullet that travels at a speed of $X$ pixels per second. Mario needs the bullet to hit the Goomba at exactly $Z$ seconds or later. We need to determine the minimum amount of time Mario must wait before firing the bullet to satisfy this condition.

## Intuition & Mathematical Observation
1. **Calculate Travel Time**: The time taken for the bullet to reach the Goomba is given by $T_{travel} = \frac{Y}{X}$.
2. **Determine Wait Time**: Let $S$ be the time Mario waits before firing. The bullet hits the target at time $T_{hit} = S + T_{travel}$.
3. **Constraint**: We are given that $T_{hit} \geq Z$. Substituting the expression for $T_{hit}$:
   $$S + \frac{Y}{X} \geq Z$$
   $$S \geq Z - \frac{Y}{X}$$
4. **Non-negativity**: Since Mario cannot wait for a negative amount of time, if $Z - \frac{Y}{X}$ is less than 0, the answer is simply 0. Otherwise, the answer is $Z - \frac{Y}{X}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Bullet speed: X pixels/second
 * - Distance to goomba: Y pixels
 * - Time taken for bullet to travel: T_travel = Y / X
 * - Target time to hit: T_total >= Z
 * - Let S be the time Mario waits before shooting.
 * - The bullet hits at time: S + T_travel
 * - We need: S + (Y / X) >= Z
 * - Therefore: S >= Z - (Y / X)
 * - Since S must be non-negative, S = max(0, Z - (Y / X))
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate travel time
        long long travel_time = y / x;

        // Calculate required wait time
        long long wait_time = z - travel_time;

        // If wait_time is negative, Mario can shoot immediately (0 seconds)
        if (wait_time < 0) {
            cout << 0 << "\n";
        } else {
            cout << wait_time << "\n";
        }
    }

    return 0;
}
```