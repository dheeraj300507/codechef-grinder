# [Total Expenses (FLOW009)](https://www.codechef.com/problems/FLOW009)

- **Difficulty Rating**: 861
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to calculate the total expenses for a given quantity and price per item. If the quantity of items purchased exceeds 1000, a discount of 10% is applied to the total cost. Otherwise, the total cost is simply the product of quantity and price. The output must be formatted to 6 decimal places.

## Intuition & Mathematical Observation
The problem presents a simple conditional logic scenario:
1. **Base Case**: If `quantity <= 1000`, the total expense is calculated as:
   $$\text{Total} = \text{quantity} \times \text{price}$$
2. **Discount Case**: If `quantity > 1000`, a 10% discount is applied. This is equivalent to paying 90% of the original total:
   $$\text{Total} = (\text{quantity} \times \text{price}) \times 0.9$$

Since the inputs can be large and the output requires precision, using the `double` data type is necessary. To ensure the output matches the required format, we use `fixed` and `setprecision(6)` from the `<iomanip>` library.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant number of arithmetic operations for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Problem: FLOW009 - Total Expenses
 * Logic: If quantity > 1000, total = quantity * price * 0.9
 * Otherwise, total = quantity * price
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double quantity, price;
        cin >> quantity >> price;

        double total;
        if (quantity > 1000) {
            // Apply 10% discount
            total = (quantity * price) * 0.9;
        } else {
            // No discount
            total = quantity * price;
        }

        // Output with 6 decimal places as per sample output
        cout << fixed << setprecision(6) << total << "\n";
    }

    return 0;
}
```