# [Which Mixture (MIXTURE)](https://www.codechef.com/problems/MIXTURE)

- **Difficulty Rating**: 841
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ (representing the amount of solid) and $B$ (representing the amount of liquid), we need to classify the mixture based on the following rules:
1. If both $A > 0$ and $B > 0$, it is a **Solution**.
2. If $B = 0$, it is a **Solid**.
3. If $A = 0$, it is a **Liquid**.

It is guaranteed that $A + B > 0$.

## Intuition & Mathematical Observation
The problem provides a straightforward conditional logic task. Since the constraints guarantee that $A$ and $B$ are non-negative and their sum is greater than zero, we can use simple `if-else` statements to check the conditions:

1. **Check for Solution**: If both $A$ and $B$ are strictly greater than 0, the mixture contains both components.
2. **Check for Solid**: If $B$ is 0, the mixture contains only solid.
3. **Check for Liquid**: If $A$ is 0, the mixture contains only liquid.

Because the problem guarantees $A+B > 0$, we do not need to handle the case where both are zero.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform the logic.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given A (solid) and B (liquid):
 * 1. If A > 0 and B > 0, it is a "Solution".
 * 2. If B == 0, it is a "Solid".
 * 3. If A == 0, it is a "Liquid".
 * 
 * Constraints:
 * 0 <= A, B <= 100
 * A + B > 0
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        if (a > 0 && b > 0) {
            cout << "Solution" << "\n";
        } else if (b == 0) {
            cout << "Solid" << "\n";
        } else if (a == 0) {
            cout << "Liquid" << "\n";
        }
    }
    
    return 0;
}
```