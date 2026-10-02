# [Giant Wheel (GIANT)](https://www.codechef.com/problems/GIANT)

- **Difficulty Rating**: 293
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a person can ride a giant wheel based on their height $X$. The condition for riding the giant wheel is that the person's height must be at least 60 units. We need to output "Yes" if the condition is met and "No" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given an integer $X$ representing the height.
- If $X \ge 60$, the condition is satisfied, and the output should be `Yes`.
- If $X < 60$, the condition is not satisfied, and the output should be `No`.

This can be implemented using a simple `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single comparison operation.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Giant Wheel
 * Logic: Alice can ride if her height X >= 60.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (cin >> X) {
        // Check if height is at least 60
        if (X >= 60) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```