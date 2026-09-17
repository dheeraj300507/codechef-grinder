# [Monthly Budget (BUDGET_)](https://www.codechef.com/problems/BUDGET_)

- **Difficulty Rating**: 456
- **Solved in**: 1 attempt(s)

## Problem Summary
Akshat has a monthly budget of $X$ rupees. He spends $Y$ rupees every day. Given that a month consists of 30 days, determine if Akshat's budget is sufficient to cover his expenses for the entire month. Output "YES" if he has enough money, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem asks us to compare the total available money ($X$) with the total expenditure over 30 days. 
- The daily expenditure is $Y$.
- The total expenditure for 30 days is calculated as $30 \times Y$.
- We simply need to check the condition: $X \ge 30 \times Y$.

Since the constraints for $X$ and $Y$ are up to $10^5$, the maximum possible expenditure is $30 \times 10^5 = 3 \times 10^6$. This value fits comfortably within a standard 32-bit integer, though `long long` is used in the solution to ensure robustness against potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant time arithmetic operation and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Akshat has X rupees.
 * Daily expenditure is Y rupees.
 * The month has 30 days.
 * Total expenditure for the month = 30 * Y.
 * We need to check if X >= 30 * Y.
 * 
 * Constraints:
 * X, Y <= 10^5.
 * 30 * Y <= 3 * 10^6.
 * This fits within a standard 32-bit integer, but using long long is safer
 * and good practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate total required budget for 30 days
        long long total_required = 30 * y;
        
        // Check if available money is sufficient
        if (x >= total_required) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```