# [Police and Thief (POLTHIEF)](https://www.codechef.com/problems/POLTHIEF)

- **Difficulty Rating**: 639
- **Solved in**: 1 attempt(s)

## Problem Summary
A policeman is at position $X$ and a thief is at position $Y$ on a number line. The policeman moves at a speed of 2 units per second, while the thief moves at a speed of 1 unit per second. We need to determine the time required for the policeman to catch the thief.

## Intuition & Mathematical Observation
To catch the thief, the policeman must close the initial distance between them. 
- Let the initial distance be $D = |X - Y|$.
- The policeman moves at 2 units/sec and the thief moves at 1 unit/sec.
- Since they are moving in the same direction (to close the gap), the **relative speed** of the policeman with respect to the thief is $2 - 1 = 1$ unit per second.
- The time required to cover the distance $D$ at a relative speed of 1 unit/sec is:
  $$\text{Time} = \frac{\text{Distance}}{\text{Relative Speed}} = \frac{|X - Y|}{1} = |X - Y|$$
Because the policeman is strictly faster than the thief, he will always be able to catch the thief, and the time taken will always be the absolute difference between their starting positions.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Policeman is at X with speed 2.
 * Thief is at Y with speed 1.
 * The relative speed of the policeman with respect to the thief is |2 - 1| = 1 unit per second.
 * The distance between them is |X - Y|.
 * Time taken = Distance / Relative Speed = |X - Y| / 1 = |X - Y|.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The time taken is simply the absolute difference between their positions
        // because the policeman's relative speed to the thief is 1 unit/sec.
        long long time_taken = abs(x - y);
        
        cout << time_taken << "\n";
    }

    return 0;
}
```