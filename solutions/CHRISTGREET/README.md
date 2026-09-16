# [Christmas Greetings (CHRISTGREET)](https://www.codechef.com/problems/CHRISTGREET)

- **Difficulty Rating**: 205
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given integer $X$ represents Christmas Day. Specifically, we need to check if the input $X$ is equal to 25. If $X = 25$, output "CHRISTMAS"; otherwise, output "ORDINARY".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Since Christmas is celebrated on the 25th of December, the condition is binary:
- If $X == 25$, the condition is satisfied.
- For any other integer value of $X$, the condition is not satisfied.

This can be implemented using a simple `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution performs a single comparison and output operation.
- **Space Complexity**: $O(1)$, as we only use a single variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Christmas Greetings
 * Logic: Check if the input integer X is equal to 25.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the input integer X
    long long X;
    if (!(cin >> X)) return 0;

    // Check if X is 25
    if (X == 25) {
        cout << "CHRISTMAS" << "\n";
    } else {
        cout << "ORDINARY" << "\n";
    }

    return 0;
}
```