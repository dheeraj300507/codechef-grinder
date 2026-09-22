# [Gold Coins 101 (GOLDCOINS)](https://www.codechef.com/problems/GOLDCOINS)

- **Difficulty Rating**: 253
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef participates in a game where he receives $A$ gold coins if he wins and $B$ gold coins if he loses. Given the score of Chef ($X$) and his opponent ($Y$), we need to determine how many coins Chef receives. It is guaranteed that $X \neq Y$.

## Intuition & Mathematical Observation
The problem is a straightforward conditional logic task. Since the problem guarantees that $X \neq Y$, there are only two possible scenarios:
1. **Chef wins**: This occurs if $X > Y$. In this case, the output should be $A$.
2. **Chef loses**: This occurs if $X < Y$. In this case, the output should be $B$.

We can implement this using a simple `if-else` statement to compare $X$ and $Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons and arithmetic operations, regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the four integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef receives A coins if he wins (X > Y).
 * Chef receives B coins if he loses (X < Y).
 * Given X != Y, we simply compare X and Y to determine the outcome.
 * Constraints are small (A, B <= 10), so standard integer types are sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, X, Y;
    // Read the input values A, B, X, and Y
    if (cin >> A >> B >> X >> Y) {
        // Compare Chef's score X with opponent's score Y
        if (X > Y) {
            // Chef wins, output A
            cout << A << "\n";
        } else {
            // Chef loses, output B
            cout << B << "\n";
        }
    }

    return 0;
}
```