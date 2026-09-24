# [Varied Digits (VARDIGS)](https://www.codechef.com/problems/VARDIGS)

- **Difficulty Rating**: 215
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a two-digit integer $X$ (where $10 \le X \le 99$), determine whether the tens digit and the units digit are distinct. If the digits are different, output "Yes"; otherwise, output "No".

## Intuition & Mathematical Observation
To solve this problem, we need to isolate the two digits of the number $X$:
1. **Tens Digit**: Since $X$ is between 10 and 99, the tens digit can be obtained using integer division: `tens = X / 10`.
2. **Units Digit**: The units digit can be obtained using the modulo operator: `units = X % 10`.

Once we have both digits, we simply compare them using the inequality operator (`!=`). If `tens != units`, the condition is satisfied, and we print "Yes". Otherwise, we print "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the integer $X$ and its two digits.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We are given a 2-digit integer X (10 <= X <= 99).
 * We need to determine if the tens digit and the units digit are different.
 * 
 * Logic:
 * Tens digit = X / 10
 * Units digit = X % 10
 * If (tens != units), output "Yes", else "No".
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    int tens = X / 10;
    int units = X % 10;

    if (tens != units) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
```