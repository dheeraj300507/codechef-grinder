# [Snape and Ladder (SNAPE)](https://www.codechef.com/problems/SNAPE)

- **Difficulty Rating**: 828
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two values: $B$ (the base separation between the two points where the ladder touches the ground) and $LS$ (the length of the left side of the ladder). The ladder forms an inverted 'V' shape with height $H$. We need to find the minimum and maximum possible values for the length of the right side ($RS$) of the ladder.

## Intuition & Mathematical Observation
The ladder forms two right-angled triangles sharing a common vertical height $H$. Let $x$ and $y$ be the segments of the base $B$ such that $x + y = B$.
- For the left side: $LS^2 = H^2 + x^2$
- For the right side: $RS^2 = H^2 + y^2$

**1. Finding the Minimum $RS$:**
The minimum $RS$ occurs when the height $H$ is as small as possible. This happens when the left side $LS$ is tilted as much as possible, effectively making $x$ as large as possible. In the limiting case, $x = LS$ (where $H=0$), but the problem implies a triangle exists. The smallest $RS$ occurs when the left side is the hypotenuse of a triangle with base $B$ and height $H$. By rearranging the Pythagorean theorem:
$H^2 = LS^2 - B^2$
$RS = \sqrt{H^2 + 0^2} = \sqrt{LS^2 - B^2}$ (assuming the right side is vertical).

**2. Finding the Maximum $RS$:**
The maximum $RS$ occurs when the height $H$ is as large as possible. This happens when the left side $LS$ is perfectly vertical ($H = LS$). In this configuration, the right side $RS$ forms a right triangle with the height $H$ and the entire base $B$:
$RS^2 = H^2 + B^2$
$RS = \sqrt{LS^2 + B^2}$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant number of arithmetic operations and square root calculations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The ladder forms two right-angled triangles with a shared height H.
 * Min RS occurs when the right side is vertical: RS = sqrt(LS^2 - B^2)
 * Max RS occurs when the left side is vertical: RS = sqrt(LS^2 + B^2)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        double b, ls;
        cin >> b >> ls;
        
        // Calculate minimum RS: sqrt(LS^2 - B^2)
        // Calculate maximum RS: sqrt(LS^2 + B^2)
        double min_rs = sqrt(max(0.0, ls * ls - b * b));
        double max_rs = sqrt(ls * ls + b * b);
        
        // Output results with required precision
        cout << fixed << setprecision(5) << min_rs << " " << max_rs << "\n";
    }
    
    return 0;
}
```