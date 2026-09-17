# [Multivitamin Tablets (TABLETS)](https://www.codechef.com/problems/TABLETS)

- **Difficulty Rating**: 376
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to take 3 multivitamin tablets every day for $X$ days. He currently has $Y$ tablets in his possession. The task is to determine if the number of tablets Chef has is sufficient to cover his requirement for the $X$ days. If $Y \ge 3 \times X$, output "YES"; otherwise, output "NO".

## Intuition & Mathematical Observation
The problem is a straightforward comparison task:
1. **Calculate Requirement**: Since Chef needs 3 tablets per day for $X$ days, the total number of tablets required is simply $3 \times X$.
2. **Comparison**: We compare the total required tablets ($3 \times X$) with the available tablets ($Y$).
   - If $Y \ge 3 \times X$, Chef has enough tablets.
   - If $Y < 3 \times X$, Chef does not have enough tablets.

Given the constraints ($X \le 100, Y \le 1000$), the calculation $3 \times X$ will not exceed 300, which easily fits within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and a comparison, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 3 tablets per day for X days.
 * Total tablets required = 3 * X.
 * Chef already has Y tablets.
 * Chef has enough if Y >= 3 * X.
 * 
 * Constraints:
 * X <= 100, Y <= 1000.
 * 3 * X will be at most 300, which fits comfortably in a standard integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate total required tablets
        long long required = 3 * x;
        
        // Check if current tablets are sufficient
        if (y >= required) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```