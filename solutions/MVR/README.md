# [Messi vs Ronaldo (MVR)](https://www.codechef.com/problems/MVR)

- **Difficulty Rating**: 316
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to determine who has a higher score based on their performance in goals and assists. 
- Messi's score is calculated as: `(goals * 2) + assists`.
- Ronaldo's score is calculated as: `(goals * 2) + assists`.
Given the inputs $A, B$ (Messi's goals and assists) and $X, Y$ (Ronaldo's goals and assists), we must output "Messi" if his score is higher, "Ronaldo" if his score is higher, or "Equal" if the scores are the same.

## Intuition & Mathematical Observation
The problem provides a direct formula for calculating the total points for both players. Since the constraints are small ($0 \le A, B, X, Y \le 100$), the maximum possible score is $100 \times 2 + 100 = 300$. This fits comfortably within a standard 32-bit integer.

1. Calculate `messi_points = (A * 2) + B`.
2. Calculate `ronaldo_points = (X * 2) + Y`.
3. Use a simple conditional (`if-else`) structure to compare the two values and print the corresponding string.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the four input variables and the two calculated scores.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Messi's points = A * 2 + B
 * Ronaldo's points = X * 2 + Y
 * We need to compare these two values and output "Messi", "Ronaldo", or "Equal".
 * 
 * Constraints: 0 <= A, B, X, Y <= 100.
 * Max points = 100 * 2 + 100 = 300.
 * Standard 'int' is sufficient as 300 fits well within the range.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, X, Y;
    // Reading the four space-separated integers
    if (!(cin >> A >> B >> X >> Y)) return 0;

    // Calculate total points
    int messi_points = (A * 2) + B;
    int ronaldo_points = (X * 2) + Y;

    // Compare and output the result
    if (messi_points > ronaldo_points) {
        cout << "Messi" << "\n";
    } else if (ronaldo_points > messi_points) {
        cout << "Ronaldo" << "\n";
    } else {
        cout << "Equal" << "\n";
    }

    return 0;
}
```