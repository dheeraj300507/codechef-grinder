# [Glass Prices (GLPR)](https://www.codechef.com/problems/GLPR)

- **Difficulty Rating**: 219
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to choose between two types of frames for a glass:
1. **Metal Frame**: Costs $Y$.
2. **Plastic Frame**: Costs $2 \times X$.

Chef will choose the **Metal Frame** if its cost is less than or equal to the cost of the Plastic Frame ($Y \le 2 \times X$). Otherwise, Chef chooses the **Plastic Frame**. Given $X$ and $Y$, determine which frame Chef chooses.

## Intuition & Mathematical Observation
The problem provides a direct conditional statement:
- If $Y \le 2 \times X$, output `METAL`.
- Otherwise, output `PLASTIC`.

Since the constraints for $X$ and $Y$ are small ($1 \le X, Y \le 2000$), the value $2 \times X$ will not exceed $4000$. This fits comfortably within a standard 32-bit integer, though `long long` is used in the solution for safety. The logic is a simple comparison, making it an $O(1)$ operation.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and arithmetic operation regardless of the input size.
- **Space Complexity**: $O(1)$ — Only a constant amount of extra space is used to store the variables $X$ and $Y$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys the metal frame if Y <= 2 * X.
 * Otherwise, Chef buys the plastic frame.
 * 
 * Constraints:
 * 1 <= X, Y <= 2000
 * Since the maximum value is 2000, 2 * X will be at most 4000.
 * Standard 'int' is sufficient as it handles up to 2*10^9.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading input X (cost of glass) and Y (cost of metal frame)
    long long X, Y;
    if (cin >> X >> Y) {
        // Compare the cost of the metal frame (Y) 
        // with the cost of the plastic frame (2 * X)
        if (Y <= 2 * X) {
            cout << "METAL" << "\n";
        } else {
            cout << "PLASTIC" << "\n";
        }
    }

    return 0;
}
```