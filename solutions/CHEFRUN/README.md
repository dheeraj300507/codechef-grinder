# [Secret Recipe (CHEFRUN)](https://www.codechef.com/problems/CHEFRUN)

- **Difficulty Rating**: 888
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Kefa are racing to reach a secret recipe located at position $X_3$. Chef starts at $X_1$ with velocity $V_1$, and Kefa starts at $X_2$ with velocity $V_2$. Given that $X_1 < X_3 < X_2$, we need to determine who reaches the recipe first. If they reach at the same time, it is a draw.

## Intuition & Mathematical Observation
The time taken to reach the recipe is calculated by the formula:
$$\text{Time} = \frac{\text{Distance}}{\text{Velocity}}$$

1. **Calculate Distances**:
   - Chef's distance: $dist_1 = X_3 - X_1$
   - Kefa's distance: $dist_2 = X_2 - X_3$

2. **Avoid Floating Point Issues**:
   Comparing $\frac{dist_1}{V_1}$ and $\frac{dist_2}{V_2}$ directly can lead to precision errors with floating-point numbers. Instead, we use **cross-multiplication**:
   - Compare $dist_1 \times V_2$ with $dist_2 \times V_1$.
   - If $dist_1 \times V_2 < dist_2 \times V_1$, Chef is faster.
   - If $dist_1 \times V_2 > dist_2 \times V_1$, Kefa is faster.
   - Otherwise, it is a draw.

3. **Data Types**:
   Since the coordinates and velocities can be up to $10^5$, the product can reach $10^{10}$. We use `long long` in C++ to prevent integer overflow, as `int` typically only holds up to $\approx 2 \times 10^9$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's distance to the bottle: dist1 = |X3 - X1|
 * Kefa's distance to the bottle: dist2 = |X2 - X3|
 * Time taken by Chef: time1 = dist1 / V1
 * Time taken by Kefa: time2 = dist2 / V2
 * 
 * To compare time1 and time2 without floating point precision issues:
 * time1 < time2  <=> dist1 / V1 < dist2 / V2
 *                <=> dist1 * V2 < dist2 * V1
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, x2, x3, v1, v2;
        cin >> x1 >> x2 >> x3 >> v1 >> v2;

        long long dist1 = x3 - x1;
        long long dist2 = x2 - x3;

        // Compare dist1/v1 and dist2/v2 using cross-multiplication
        // time1_scaled = dist1 * v2
        // time2_scaled = dist2 * v1
        long long time1_scaled = dist1 * v2;
        long long time2_scaled = dist2 * v1;

        if (time1_scaled < time2_scaled) {
            cout << "Chef" << "\n";
        } else if (time1_scaled > time2_scaled) {
            cout << "Kefa" << "\n";
        } else {
            cout << "Draw" << "\n";
        }
    }

    return 0;
}
```