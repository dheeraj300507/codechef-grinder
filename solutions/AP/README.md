# [Make Arithmetic Progression (AP)](https://www.codechef.com/problems/AP)

- **Difficulty Rating**: 682
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $X, Y,$ and $Z$, determine the minimum number of operations required to make them form an Arithmetic Progression (AP). In one operation, you can change any of the three integers to any other integer. An AP is defined by the property $Y - X = Z - Y$, which simplifies to $2Y = X + Z$.

## Intuition & Mathematical Observation
To determine the minimum operations, we evaluate the condition $2Y = X + Z$:

1.  **0 Operations**: If the given integers already satisfy $2Y = X + Z$, they form an AP, so no changes are needed.
2.  **1 Operation**: If the condition is not met, we can always transform the sequence into an AP by changing exactly one number:
    *   Change $X$ to $2Y - Z$.
    *   Change $Y$ to $(X + Z) / 2$ (if $X+Z$ is even).
    *   Change $Z$ to $2Y - X$.
    
Since we are allowed to change any number to *any* integer, we can always satisfy the AP condition by modifying just one of the three numbers if the initial state is not already an AP. Therefore, the answer is always either 0 or 1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X, Y, Z. We want to check if they form an AP: Y - X = Z - Y,
 * which is equivalent to 2*Y = X + Z.
 * 
 * If 2*Y == X + Z, the sequence is already an AP (0 moves).
 * Otherwise, we can change any one of the numbers (e.g., change X to 2*Y - Z)
 * to satisfy the equation, requiring only 1 move.
 */

void solve() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;

    // Check if the sequence is already an AP
    if (2 * Y == X + Z) {
        cout << 0 << "\n";
    } else {
        // If not an AP, we can always make it one by changing one number
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```