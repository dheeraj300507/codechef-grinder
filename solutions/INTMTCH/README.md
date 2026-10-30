# [Interesting Match (INTMTCH)](https://www.codechef.com/problems/INTMTCH)

- **Difficulty Rating**: 240
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a match is "Interesting" or "Boring" based on the scores of two teams, $X$ and $Y$. A match is considered "Interesting" if the absolute difference between the scores of the two teams is at most 2 (i.e., $|X - Y| \le 2$). Otherwise, the match is "Boring".

## Intuition & Mathematical Observation
The core of the problem is a simple conditional check. Given two integers $X$ and $Y$:
1. Calculate the absolute difference: `abs(X - Y)`.
2. Compare this value against the threshold of 2.
3. If the difference is $\le 2$, output "Interesting".
4. Otherwise, output "Boring".

**Note on Input:** Unlike many CodeChef problems that provide a number of test cases ($T$), this specific problem provides the two integers $X$ and $Y$ directly. The solution must handle this input format correctly.

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: INTMTCH
 * Logic:
 * The problem asks to check if the absolute difference between X and Y is <= 2.
 * The input format specifies two integers X and Y directly, without a test case count.
 */

int main() {
    // Fast I/O for efficiency
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    
    // Read X and Y directly as per the problem format
    if (cin >> x >> y) {
        // Calculate absolute difference using abs() from <cmath>
        int diff = abs(x - y);

        // Check condition: if difference is 0, 1, or 2, it is Interesting
        if (diff <= 2) {
            cout << "Interesting" << endl;
        } else {
            cout << "Boring" << endl;
        }
    }

    return 0;
}
```