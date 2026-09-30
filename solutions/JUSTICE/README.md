# [International Justice Day (JUSTICE)](https://www.codechef.com/problems/JUSTICE)

- **Difficulty Rating**: 264
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if an accused person is convicted based on two integers, $X$ and $Y$. Specifically, the accused is convicted if the number of witnesses $X$ is greater than or equal to the number of witnesses $Y$ required for a conviction. We need to output "YES" if $X \ge Y$, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. We are given two values:
1. $X$: The number of witnesses present.
2. $Y$: The threshold number of witnesses required for a conviction.

The condition for conviction is explicitly defined as $X \ge Y$. Therefore, we simply need to use a conditional `if-else` statement to compare these two integers and print the corresponding result.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a single comparison operation.
- **Space Complexity**: $O(1)$, as we only use a constant amount of memory to store the two input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: International Justice Day
 * Logic: The accused is convicted if X >= Y.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading X and Y from standard input
    long long X, Y;
    if (cin >> X >> Y) {
        // Check the condition for conviction
        if (X >= Y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```