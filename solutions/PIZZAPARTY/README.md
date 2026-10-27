# [Pizza Party (PIZZAPARTY)](https://www.codechef.com/problems/PIZZAPARTY)

- **Difficulty Rating**: 238
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef is hosting a party. There are $A$ friends (boys) and $B$ girls attending. Including Chef, there are $A+1$ boys in total. Each boy consumes 4 slices of pizza, and each girl consumes 3 slices. Given that each pizza contains 8 slices, calculate the minimum number of pizzas required to ensure everyone gets enough slices.

## Intuition & Mathematical Observation
1. **Calculate Total Slices**: 
   - Total boys = $A + 1$.
   - Total girls = $B$.
   - Total slices needed = $(A + 1) \times 4 + B \times 3$.
2. **Calculate Pizzas Needed**:
   - Since each pizza has 8 slices, we need to divide the total slices by 8.
   - Because we cannot order a fraction of a pizza, we must round up to the nearest whole number (ceiling division).
   - In integer arithmetic, the ceiling of $\frac{x}{y}$ can be calculated using the formula: `(x + y - 1) / y`.
   - Therefore, the number of pizzas = `(total_slices + 8 - 1) / 8` or `(total_slices + 7) / 8`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Chef is a boy, so total boys = A + 1.
 * - Total girls = B.
 * - Each boy eats 4 slices, each girl eats 3 slices.
 * - Total slices needed = (A + 1) * 4 + B * 3.
 * - Each pizza has 8 slices.
 * - Number of pizzas needed = ceil(Total slices / 8).
 * - Using integer arithmetic, ceil(x / y) = (x + y - 1) / y.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // Read A and B
    if (cin >> A >> B) {
        long long total_boys = A + 1;
        long long total_girls = B;
        long long total_slices = (total_boys * 4) + (total_girls * 3);

        // Calculate ceiling division: (total_slices + 8 - 1) / 8
        long long pizzas_needed = (total_slices + 7) / 8;

        cout << pizzas_needed << endl;
    }

    return 0;
}
```