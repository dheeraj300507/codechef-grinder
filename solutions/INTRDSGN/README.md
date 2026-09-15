# [Interior Design (INTRDSGN)](https://www.codechef.com/problems/INTRDSGN)

- **Difficulty Rating**: 373
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare two different interior design options. Each option consists of two components with specific costs. We are given four integers: $X_1, Y_1$ (the costs for the first design) and $X_2, Y_2$ (the costs for the second design). We need to calculate the total cost for each design ($X_1 + Y_1$ and $X_2 + Y_2$) and output the minimum of the two.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. 
1. Calculate the total cost of the first design: $Cost_1 = X_1 + Y_1$.
2. Calculate the total cost of the second design: $Cost_2 = X_2 + Y_2$.
3. Use a simple conditional statement (or the `std::min` function) to determine which value is smaller.
4. Since the constraints are small, standard integer types are sufficient, though `long long` is used here as a best practice to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and a comparison, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Interior Design
 * The task is to compare the sum of two pairs of integers (X1 + Y1) and (X2 + Y2)
 * and output the minimum of the two sums.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        long long cost1 = x1 + y1;
        long long cost2 = x2 + y2;
        
        // Output the minimum of the two costs
        if (cost1 < cost2) {
            cout << cost1 << "\n";
        } else {
            cout << cost2 << "\n";
        }
    }
    
    return 0;
}
```