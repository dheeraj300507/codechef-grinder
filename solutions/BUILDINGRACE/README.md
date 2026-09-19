# [Building Race (BUILDINGRACE)](https://www.codechef.com/problems/BUILDINGRACE)

- **Difficulty Rating**: 739
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at floor $A$ and moves at a speed of $X$ floors per minute. Chefina is at floor $B$ and moves at a speed of $Y$ floors per minute. We need to determine who reaches the ground floor (floor 0) first. If they reach at the same time, we output "Both".

## Intuition & Mathematical Observation
The time taken for Chef to reach the ground is $T_{Chef} = \frac{A}{X}$, and the time taken for Chefina is $T_{Chefina} = \frac{B}{Y}$.

To determine who is faster, we compare $\frac{A}{X}$ and $\frac{B}{Y}$. Comparing fractions directly using floating-point division can lead to precision errors. To avoid this, we use **cross-multiplication**:
- If $\frac{A}{X} < \frac{B}{Y}$, then $A \times Y < B \times X$ (Chef is faster).
- If $\frac{A}{X} > \frac{B}{Y}$, then $A \times Y > B \times X$ (Chefina is faster).
- If $\frac{A}{X} = \frac{B}{Y}$, then $A \times Y = B \times X$ (Both reach at the same time).

Since the input values fit within standard integer types, we use `long long` to prevent potential overflow during multiplication.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Given $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at floor A with speed X. Time taken = A / X.
 * Chefina is at floor B with speed Y. Time taken = B / Y.
 * We need to compare A/X and B/Y.
 * To avoid floating point precision issues, we can compare A/X and B/Y 
 * by cross-multiplying: compare A * Y and B * X.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;

        // Using cross-multiplication to compare fractions A/X and B/Y
        // Time_Chef = a / x
        // Time_Chefina = b / y
        // Compare (a * y) and (b * x)
        long long time_chef_scaled = a * y;
        long long time_chefina_scaled = b * x;

        if (time_chef_scaled < time_chefina_scaled) {
            cout << "Chef" << "\n";
        } else if (time_chef_scaled > time_chefina_scaled) {
            cout << "Chefina" << "\n";
        } else {
            cout << "Both" << "\n";
        }
    }

    return 0;
}
```