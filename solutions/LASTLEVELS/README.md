# [The Last Levels (LASTLEVELS)](https://www.codechef.com/problems/LASTLEVELS)

- **Difficulty Rating**: 679
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to complete $X$ levels, where each level takes $Y$ minutes to complete. After every 3 levels, Chef takes a break of $Z$ minutes. However, no break is taken after the final level if the game is completed exactly at a multiple of 3. We need to calculate the total time spent to complete all $X$ levels.

## Intuition & Mathematical Observation
1. **Playing Time**: Since every level takes $Y$ minutes, the total time spent actively playing is simply $X \times Y$.
2. **Break Time**: 
   - Breaks occur after every 3 levels.
   - If $X$ is a multiple of 3 (e.g., 3, 6, 9), the number of breaks is $(X/3) - 1$.
   - If $X$ is not a multiple of 3 (e.g., 4, 5), the number of breaks is $\lfloor X/3 \rfloor$.
   - Both cases can be unified using the formula: **Number of breaks = $(X - 1) / 3$** (using integer division).
   - For example:
     - $X=3 \implies (3-1)/3 = 0$ breaks.
     - $X=4 \implies (4-1)/3 = 1$ break.
     - $X=6 \implies (6-1)/3 = 1$ break.
3. **Total Time**: The final answer is $(X \times Y) + (\text{number of breaks} \times Z)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X levels to complete.
 * Each level takes Y minutes.
 * A break of Z minutes is taken after every 3 levels, 
 * but not after the final level if the game is completed.
 * 
 * Total time = (Total time spent playing) + (Total time spent on breaks)
 * Total time spent playing = X * Y
 * Number of breaks = (X - 1) / 3 (integer division)
 * Total time spent on breaks = ((X - 1) / 3) * Z
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

        // Total time playing is simply X * Y
        long long total_playing_time = x * y;

        // Breaks are taken after every 3 levels, but not after the last level.
        // The formula (x - 1) / 3 correctly handles the "no break after last level" condition.
        long long num_breaks = (x - 1) / 3;
        long long total_break_time = num_breaks * z;

        long long total_time = total_playing_time + total_break_time;

        cout << total_time << "\n";
    }

    return 0;
}
```