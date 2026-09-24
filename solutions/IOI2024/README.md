# [IOI 2024 (IOI2024)](https://www.codechef.com/problems/IOI2024)

- **Difficulty Rating**: 219
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $X$ (representing a day in September) falls within the duration of the International Olympiad in Informatics (IOI) 2024. The event is held from September 1st to September 8th, inclusive. We must output "YES" if $1 \le X \le 8$, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem defines a closed interval $[1, 8]$. Since the input $X$ is guaranteed to be an integer between 1 and 30, we simply need to check if $X$ satisfies the condition $1 \le X \le 8$. 
- If the condition is true, the date falls within the event period.
- If the condition is false, the date falls outside the event period.

This is a straightforward conditional check that requires no complex algorithms or data structures.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of comparisons regardless of the input value.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The IOI 2024 is held from September 1st to September 8th.
 * We are given an integer X representing a date in September.
 * We need to output "YES" if 1 <= X <= 8, otherwise "NO".
 * 
 * Constraints: 1 <= X <= 30.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the input integer X
    if (!(cin >> X)) return 0;

    // Check if X is within the range [1, 8]
    if (X >= 1 && X <= 8) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```