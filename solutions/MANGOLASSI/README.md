# [Summer Time (MANGOLASSI)](https://www.codechef.com/problems/MANGOLASSI)

- **Difficulty Rating**: 242
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine whether Mamalesh will drink mango lassi based on the current temperature $X$. According to the rules, Mamalesh drinks mango lassi if and only if the temperature is strictly greater than 35 degrees Celsius. We need to output "YES" if the condition is met, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given an integer $X$ representing the temperature. 
- If $X > 35$, the condition is satisfied, and we print `YES`.
- If $X \le 35$, the condition is not satisfied, and we print `NO`.

Since the constraints are small ($1 \le X \le 50$), a simple `if-else` statement is sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single comparison operation.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Summer Time
 * Logic: Mamalesh drinks mango lassi if temperature X > 35.
 * Constraints: 1 <= X <= 50.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // Check if temperature is strictly greater than 35
    if (X > 35) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```