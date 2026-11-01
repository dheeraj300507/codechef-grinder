# [A - Save Water Save Life (SAVWATER)](https://www.codechef.com/problems/SAVWATER)

- **Difficulty Rating**: 918
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to determine if a given capacity of water $C$ is sufficient to support $H$ households. Each household requires $x$ liters of freshwater (which is mandatory) and $y$ liters of greywater. However, the greywater consumption is reduced by half (using floor division), meaning each household effectively consumes $x + \lfloor y/2 \rfloor$ liters. We must output "YES" if the total consumption for all $H$ households is less than or equal to $C$, and "NO" otherwise.

## Intuition & Mathematical Observation
1. **Consumption Calculation**: For a single household, the total water usage is the sum of the mandatory freshwater ($x$) and the treated greywater ($\lfloor y/2 \rfloor$).
2. **Total Requirement**: Since there are $H$ households, the total water required is $H \times (x + \lfloor y/2 \rfloor)$.
3. **Comparison**: We simply compare this total requirement against the available capacity $C$. If $H \times (x + \lfloor y/2 \rfloor) \le C$, the condition is satisfied.
4. **Data Types**: Given the constraints ($H, x, y \le 10^4$ and $C \le 10^8$ in typical variations of this problem), the result fits comfortably within a standard 32-bit integer, though `long long` is used here for safety against potential overflow in larger constraint scenarios.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each household consumes 'x' liters of mandatory freshwater.
 * Each household consumes 'y' liters of greywater, which is reduced to floor(y/2).
 * Total consumption per household = x + floor(y/2).
 * Total consumption for H households = H * (x + floor(y/2)).
 * We need to check if this total consumption <= C.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long H, x, y, C;
        cin >> H >> x >> y >> C;
        
        // Calculate consumption per household
        // Using integer division for floor(y/2)
        long long consumption_per_household = x + (y / 2);
        
        // Calculate total consumption for all households
        long long total_consumption = H * consumption_per_household;
        
        // Compare with available water C
        if (total_consumption <= C) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```