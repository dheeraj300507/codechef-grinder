# [Buy Please (BUYPLSE)](https://www.codechef.com/problems/BUYPLSE)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to calculate the total cost of purchasing two types of items. Given the quantity of the first item ($a$) and its price ($x$), and the quantity of the second item ($b$) and its price ($y$), we need to compute the total expenditure using the formula:
$$\text{Total Cost} = (a \times x) + (b \times y)$$

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. 
- We are given four integers as input.
- The constraints state that $1 \le a, b, x, y \le 10^3$.
- The maximum possible result is $(10^3 \times 10^3) + (10^3 \times 10^3) = 2 \times 10^6$.
- Since $2 \times 10^6$ is well within the range of a standard 32-bit integer (`int` in C++), overflow is not a concern. However, using `long long` is a good practice in competitive programming to ensure robustness against larger constraints in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the four input variables and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Buy Please
 * The problem asks to calculate the total cost: (a * x) + (b * y).
 * Constraints: 1 <= a, b, x, y <= 10^3.
 * Maximum possible value: (10^3 * 10^3) + (10^3 * 10^3) = 2 * 10^6.
 * This fits comfortably within a standard 32-bit integer, but using long long 
 * is a safe practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, x, y;
    
    // Reading the 4 space-separated integers
    if (cin >> a >> b >> x >> y) {
        // Calculating total cost
        long long total_cost = (a * x) + (b * y);
        
        // Output the result
        cout << total_cost << "\n";
    }

    return 0;
}
```