# [Count the ACs (ACS)](https://www.codechef.com/problems/ACS)

- **Difficulty Rating**: 739
- **Solved in**: 1 attempt(s)

## Problem Summary
In a contest, there are 10 problems in total. Each problem is worth either 1 point or 100 points. Given a total score $P$, we need to determine the minimum number of problems required to achieve exactly $P$ points. If it is impossible to achieve exactly $P$ points using at most 10 problems, output -1.

## Intuition & Mathematical Observation
Let $x$ be the number of problems worth 100 points and $y$ be the number of problems worth 1 point.
The total score is given by:
$$100x + 1y = P$$

Since each problem is worth either 1 or 100, we can use integer division and the modulo operator to find the values of $x$ and $y$:
1. **$x = P / 100$**: This represents the maximum number of 100-point problems that can fit into the score $P$.
2. **$y = P \% 100$**: This represents the remainder, which must be covered by 1-point problems.

The total number of problems used is $x + y$. The problem constraints state there are only 10 problems available. Therefore, the condition to satisfy is:
$$x + y \le 10$$

If this condition holds, the answer is $x + y$. Otherwise, it is impossible to achieve the score $P$ with the given constraints, and we output -1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 10 problems total.
 * Each problem is worth either 1 or 100 points.
 * Let x be the number of problems worth 100 points.
 * Let y be the number of problems worth 1 point.
 * Total problems: x + y <= 10
 * Total score: 100*x + 1*y = P
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int P;
        cin >> P;

        // x is the number of 100-point problems
        // y is the number of 1-point problems
        int x = P / 100;
        int y = P % 100;

        // Check if the total number of problems solved is within the limit of 10
        if (x + y <= 10) {
            cout << (x + y) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```