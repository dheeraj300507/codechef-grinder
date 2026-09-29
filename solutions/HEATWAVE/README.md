# [Heat Wave (HEATWAVE)](https://www.codechef.com/problems/HEATWAVE)

- **Difficulty Rating**: 284
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a new record high temperature has been set. We are given two integers: $X$, representing the previous record high temperature, and $Y$, representing the temperature on the current day. We need to output "YES" if the current temperature $Y$ is strictly greater than the previous record $X$, and "NO" otherwise.

## Intuition & Mathematical Observation
The logic is straightforward:
- A "heat wave" or a new record is defined by the condition $Y > X$.
- If $Y$ is greater than $X$, the condition is satisfied, and we print `YES`.
- If $Y$ is less than or equal to $X$, no new record is set, so we print `NO`.
- This is a simple conditional comparison that requires no complex data structures or algorithms.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only a single comparison operation.
- **Space Complexity**: $O(1)$, as we only use two integer variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Heat Wave
 * Logic: A new record high is created if the temperature on the next day (Y)
 * is strictly greater than the previous record high (X).
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // Read the previous record (X) and the current temperature (Y)
    if (cin >> X >> Y) {
        // Check if the current temperature is strictly greater than the record
        if (Y > X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```