# [Chef On Island (CCISLAND)](https://www.codechef.com/problems/CCISLAND)

- **Difficulty Rating**: 878
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is stranded on an island with $x$ units of food and $y$ units of water. To survive, he requires $x_r$ units of food and $y_r$ units of water every day. We need to determine if Chef can survive for at least $D$ days.

## Intuition & Mathematical Observation
To survive for $D$ days, Chef must have enough resources to cover the daily requirements for the entire duration. 

1. **Food constraint**: The total number of days the food will last is given by $\lfloor x / x_r \rfloor$.
2. **Water constraint**: The total number of days the water will last is given by $\lfloor y / y_r \rfloor$.
3. **Limiting factor**: Chef can only survive as long as both resources are available. Therefore, the maximum number of days he can survive is the minimum of the two values: $\min(\lfloor x / x_r \rfloor, \lfloor y / y_r \rfloor)$.
4. **Decision**: If this minimum value is greater than or equal to $D$, output "YES"; otherwise, output "NO".

Since the constraints are small, standard integer division handles the floor operation automatically.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has x units of food and y units of water.
 * He needs x_r units of food and y_r units of water per day.
 * He needs to survive for D days.
 * 
 * The number of days the food will last is floor(x / x_r).
 * The number of days the water will last is floor(y / y_r).
 * The total number of days he can survive is min(floor(x / x_r), floor(y / y_r)).
 * If this value is >= D, he can reach the shore.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, xr, yr, d;
        cin >> x >> y >> xr >> yr >> d;

        // Calculate how many days food and water will last
        long long food_days = x / xr;
        long long water_days = y / yr;

        // The limiting factor is the minimum of the two
        long long survival_days = min(food_days, water_days);

        // Check if he can survive for at least D days
        if (survival_days >= d) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```