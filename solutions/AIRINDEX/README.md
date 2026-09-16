# [Air Quality Index (AIRINDEX)](https://www.codechef.com/problems/AIRINDEX)

- **Difficulty Rating**: 347
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if the air quality is considered "good" based on a given Air Quality Index (AQI) value $X$. According to the problem statement, the air is considered good if the AQI is strictly less than 100. We need to output "YES" if $X < 100$, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given an integer $X$ representing the AQI. 
- If $X < 100$, the condition is satisfied, and we print `YES`.
- If $X \ge 100$, the condition is not satisfied, and we print `NO`.

No complex algorithms or data structures are required; a simple `if-else` statement is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single comparison operation.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Air Quality Index (AIRINDEX)
 * The condition is that the AQI (X) must be strictly below 100.
 * If X < 100, output YES.
 * Otherwise, output NO.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the integer X representing the AQI
    int X;
    if (!(cin >> X)) return 0;

    // Check if AQI is strictly below 100
    if (X < 100) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```