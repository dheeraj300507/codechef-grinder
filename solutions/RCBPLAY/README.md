# [RCB and Playoffs (RCBPLAY)](https://www.codechef.com/problems/RCBPLAY)

- **Difficulty Rating**: 788
- **Solved in**: 1 attempt(s)

## Problem Summary
RCB currently has $X$ points and needs to reach at least $Y$ points to qualify for the playoffs. They have $Z$ games remaining. In each game, a win grants 2 points. We need to determine if it is possible for RCB to reach or exceed $Y$ points by the end of their remaining games.

## Intuition & Mathematical Observation
To determine if RCB can qualify, we need to calculate the maximum possible score they can achieve. 
1. RCB starts with $X$ points.
2. They have $Z$ games left, and each win provides 2 points.
3. Therefore, the maximum additional points they can earn is $2 \times Z$.
4. The maximum total points they can reach is $X + (2 \times Z)$.

If this maximum total is greater than or equal to the target $Y$, then qualification is possible ("YES"). Otherwise, it is impossible ("NO").

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves simple arithmetic operations performed in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB currently has X points.
 * They need at least Y points to qualify.
 * They have Z games left.
 * In each game, they can earn a maximum of 2 points (a win).
 * Therefore, the maximum number of points they can earn in Z games is 2 * Z.
 * The total points they can reach is X + (2 * Z).
 * RCB qualifies if X + 2 * Z >= Y.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Calculate the maximum possible points RCB can achieve
        long long max_points = x + (2 * z);
        
        // Check if the maximum possible points meet or exceed the requirement Y
        if (max_points >= y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```