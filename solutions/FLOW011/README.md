# [Gross Salary (FLOW011)](https://www.codechef.com/problems/FLOW011)

- **Difficulty Rating**: 823
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to calculate the **Gross Salary** of an employee based on their **Basic Salary**. The calculation depends on the following conditions:
1. If Basic Salary < 1500:
   - HRA = 10% of Basic Salary
   - DA = 90% of Basic Salary
2. If Basic Salary ≥ 1500:
   - HRA = 500
   - DA = 98% of Basic Salary

The Gross Salary is defined as: `Basic Salary + HRA + DA`.

## Intuition & Mathematical Observation
The problem can be solved using simple conditional logic (`if-else` statements). 

- **Case 1 (Basic < 1500):**
  - $Gross = Basic + (0.10 \times Basic) + (0.90 \times Basic)$
  - Simplifying this: $Gross = Basic \times (1 + 0.10 + 0.90) = 2.0 \times Basic$

- **Case 2 (Basic ≥ 1500):**
  - $Gross = Basic + 500 + (0.98 \times Basic)$
  - Simplifying this: $Gross = 1.98 \times Basic + 500$

Since the output requires precision up to 2 decimal places, we use `fixed` and `setprecision(2)` from the `<iomanip>` library.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the salary and gross values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Gross Salary
 * Logic:
 * If basic salary < 1500:
 *   HRA = 0.10 * basic
 *   DA = 0.90 * basic
 *   Gross = basic + 0.10 * basic + 0.90 * basic = 2.0 * basic
 * 
 * If basic salary >= 1500:
 *   HRA = 500
 *   DA = 0.98 * basic
 *   Gross = basic + 500 + 0.98 * basic = 1.98 * basic + 500
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double salary;
        cin >> salary;

        double gross;
        if (salary < 1500) {
            gross = salary + (0.10 * salary) + (0.90 * salary);
        } else {
            gross = salary + 500 + (0.98 * salary);
        }

        // Set precision to 2 decimal places as per sample output requirements
        cout << fixed << setprecision(2) << gross << "\n";
    }

    return 0;
}
```