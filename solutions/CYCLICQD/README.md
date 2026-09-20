# [Cyclic Quadrilateral (CYCLICQD)](https://www.codechef.com/problems/CYCLICQD)

- **Difficulty Rating**: 735
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the four interior angles of a quadrilateral ($A, B, C, D$) in order, determine whether the quadrilateral is **cyclic**. A quadrilateral is cyclic if and only if the sum of its opposite angles is exactly $180^\circ$.

## Intuition & Mathematical Observation
A fundamental property of a cyclic quadrilateral is that its opposite angles sum to $180^\circ$. For a quadrilateral with angles $A, B, C, D$ in order, the opposite pairs are $(A, C)$ and $(B, D)$.

1.  **Condition**: The quadrilateral is cyclic if $A + C = 180^\circ$ and $B + D = 180^\circ$.
2.  **Simplification**: Since the sum of all interior angles in any quadrilateral is always $360^\circ$ ($A + B + C + D = 360^\circ$), if we verify that $A + C = 180^\circ$, then it mathematically follows that $B + D$ must also be $180^\circ$ (because $360^\circ - 180^\circ = 180^\circ$).
3.  **Conclusion**: We only need to check if $A + C = 180$ to determine if the quadrilateral is cyclic.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input angles.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A quadrilateral is cyclic if and only if the sum of its opposite angles is 180 degrees.
 * Given angles A, B, C, D in order along the perimeter, the opposite pairs are (A, C) and (B, D).
 * Therefore, the quadrilateral is cyclic if A + C = 180 and B + D = 180.
 * Since the sum of all angles in a quadrilateral is 360 (A + B + C + D = 360),
 * if A + C = 180, then B + D must also be 180 (360 - 180 = 180).
 * Thus, we only need to check if A + C == 180.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        // Check if the sum of opposite angles equals 180
        if (a + c == 180) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```