# [Far from origin (FARFROMO)](https://www.codechef.com/problems/FARFROMO)

- **Difficulty Rating**: 750
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the coordinates of two points, Alex's position $(x_1, y_1)$ and Bob's position $(x_2, y_2)$, determine who is farther from the origin $(0, 0)$. If Alex is farther, output "ALEX"; if Bob is farther, output "BOB"; if they are at the same distance, output "EQUAL".

## Intuition & Mathematical Observation
The distance of a point $(x, y)$ from the origin $(0, 0)$ is calculated using the Euclidean distance formula:
$$d = \sqrt{x^2 + y^2}$$

To compare the distances of two points, we compare $\sqrt{x_1^2 + y_1^2}$ and $\sqrt{x_2^2 + y_2^2}$. Since the square root function is monotonically increasing for non-negative values, we can compare the squared distances instead:
$$d^2 = x^2 + y^2$$

**Why use squared distance?**
1. **Precision**: Calculating square roots often involves floating-point numbers, which can lead to precision errors. Comparing squared values keeps the calculations strictly within the integer domain.
2. **Efficiency**: The `sqrt()` function is computationally more expensive than simple multiplication and addition.

Given the constraints $-1000 \le x, y \le 1000$, the maximum squared distance is $1000^2 + 1000^2 = 2,000,000$, which easily fits within a standard 32-bit integer (though `long long` is used here for best practice).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the coordinates and squared distances.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance of a point (x, y) from the origin (0, 0) is given by the formula:
 * Distance = sqrt(x^2 + y^2)
 * To compare distances, we can compare the squared distances (x^2 + y^2) 
 * to avoid floating point precision issues and the expensive sqrt function.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Calculate squared distances to avoid sqrt() and floating point issues
        long long distSqAlex = (x1 * x1) + (y1 * y1);
        long long distSqBob = (x2 * x2) + (y2 * y2);

        if (distSqAlex > distSqBob) {
            cout << "ALEX" << "\n";
        } else if (distSqBob > distSqAlex) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}
```