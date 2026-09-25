# [Reach fast (REACHFAST)](https://www.codechef.com/problems/REACHFAST)

- **Difficulty Rating**: 777
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is located at position $A$ and Chefina is at position $B$ on a number line. Chef can move at most $K$ units in a single step in either direction. The goal is to find the minimum number of steps required for Chef to reach Chefina's position.

## Intuition & Mathematical Observation
To minimize the number of steps, Chef should always move the maximum possible distance ($K$ units) towards Chefina until the remaining distance is less than or equal to $K$.

1.  **Calculate Distance**: The total distance to cover is $D = |A - B|$.
2.  **Calculate Steps**: Since each step covers $K$ units, the number of steps required is $\lceil D / K \rceil$.
3.  **Integer Arithmetic**: In C++, integer division truncates towards zero. To perform a ceiling division using integers, we can use the formula:
    $$\text{steps} = \frac{D + K - 1}{K}$$
    This formula effectively adds the remainder to ensure that any fractional step is rounded up to the next whole step.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at A, Chefina is at B.
 * In one step, Chef can move at most K units.
 * The distance between them is |A - B|.
 * To minimize the number of steps, Chef should always move K units 
 * towards Chefina until the remaining distance is <= K.
 * 
 * If distance D = |A - B|, the number of steps is ceil(D / K).
 * Using integer arithmetic, ceil(D / K) can be calculated as (D + K - 1) / K.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, k;
        cin >> a >> b >> k;

        // Calculate absolute distance
        long long dist = abs(a - b);

        // If distance is 0, 0 steps are needed
        if (dist == 0) {
            cout << 0 << "\n";
        } else {
            // Calculate ceil(dist / k)
            // Using integer division: (dist + k - 1) / k
            long long steps = (dist + k - 1) / k;
            cout << steps << "\n";
        }
    }

    return 0;
}
```