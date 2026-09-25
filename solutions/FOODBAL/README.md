# [Food Balance (FOODBAL)](https://www.codechef.com/problems/FOODBAL)

- **Difficulty Rating**: 215
- **Solved in**: 3 attempt(s)

## Problem Summary
The task is to compare the nutritional balance of two different dishes. For each dish, we are given the amount of fat ($F$) and protein ($P$). We define the "imbalance" of a dish as the absolute difference between its fat and protein content: $|F - P|$. We must determine which dish has a smaller imbalance, or if they are equal.

## Intuition & Mathematical Observation
The problem asks us to compare two values:
1. $D_1 = |F_1 - P_1|$
2. $D_2 = |F_2 - P_2|$

By calculating these two absolute differences using the `std::abs()` function in C++, we can directly compare the results:
- If $D_1 < D_2$, the first dish is more balanced ("First").
- If $D_2 < D_1$, the second dish is more balanced ("Second").
- If $D_1 = D_2$, both dishes have the same level of imbalance ("Both").

The constraints are small enough that standard integer types are sufficient to store the values and their differences.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a few integer variables to store the input and the calculated differences.

## Solution Code

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

/**
 * Problem: FOODBAL
 * The goal is to compare the absolute difference between fat and protein for two dishes.
 * D1 = |F1 - P1|
 * D2 = |F2 - P2|
 * 
 * Complexity: O(1) time, O(1) space.
 */

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f1, p1, f2, p2;
    
    // Read the four integers. The problem guarantees one line of input.
    if (cin >> f1 >> p1 >> f2 >> p2) {
        // Calculate absolute differences using std::abs
        int diff1 = std::abs(f1 - p1);
        int diff2 = std::abs(f2 - p2);

        // Compare and output the result
        if (diff1 < diff2) {
            cout << "First" << endl;
        } else if (diff2 < diff1) {
            cout << "Second" << endl;
        } else {
            cout << "Both" << endl;
        }
    }

    return 0;
}
```