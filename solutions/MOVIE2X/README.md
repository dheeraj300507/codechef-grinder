# [Watching Movies at 2x (MOVIE2X)](https://www.codechef.com/problems/MOVIE2X)

- **Difficulty Rating**: 628
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to watch a movie of total duration $X$ minutes. He decides to watch the first $Y$ minutes at double speed (2x) and the remaining $(X - Y)$ minutes at normal speed (1x). We need to calculate the total time Chef spends watching the movie.

## Intuition & Mathematical Observation
The total time spent is the sum of the time taken for the two parts:
1. **First part**: The first $Y$ minutes are watched at 2x speed. Since speed is doubled, the time taken is halved:
   $$\text{Time}_1 = \frac{Y}{2}$$
2. **Second part**: The remaining $(X - Y)$ minutes are watched at normal speed (1x), so the time taken remains the same:
   $$\text{Time}_2 = X - Y$$

**Total Time Formula**:
$$\text{Total Time} = \frac{Y}{2} + (X - Y)$$

Since the problem guarantees that $Y$ is even, the division $\frac{Y}{2}$ will always result in an integer, allowing for simple arithmetic calculation.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef watches the first Y minutes at 2x speed.
 * Time taken for the first Y minutes = Y / 2.
 * The remaining (X - Y) minutes are watched at normal speed (1x).
 * Time taken for the remaining (X - Y) minutes = X - Y.
 * Total time = (Y / 2) + (X - Y).
 * 
 * Constraints:
 * 1 <= X, Y <= 1000
 * Y is even.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    if (cin >> X >> Y) {
        // Calculate total time spent
        // The first Y minutes take Y/2 time, the rest take (X-Y) time.
        int total_time = (Y / 2) + (X - Y);
        cout << total_time << "\n";
    }

    return 0;
}
```