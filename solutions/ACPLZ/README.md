# [AC Please (ACPLZ)](https://www.codechef.com/problems/ACPLZ)

- **Difficulty Rating**: 245
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given room temperature $T$ is strictly greater than 30 degrees Celsius. If the temperature is greater than 30, we need to output "YES" (indicating the air conditioner should be turned on); otherwise, we output "NO".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given an integer $T$ representing the temperature. The condition provided is:
- If $T > 30$, the output is `YES`.
- If $T \le 30$, the output is `NO`.

Since the constraints are small ($1 \le T \le 50$), a simple `if-else` statement is sufficient to handle the logic.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and output operation, which takes constant time regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks us to determine if the temperature T is strictly greater than 30.
 * If T > 30, output "YES".
 * Otherwise, output "NO".
 * 
 * Constraints:
 * 1 <= T <= 50
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Reading the input temperature
    if (!(cin >> t)) return 0;

    // Logic: Check if temperature is strictly greater than 30
    if (t > 30) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```