# [Valentine is Coming (VALENTINE)](https://www.codechef.com/problems/VALENTINE)

- **Difficulty Rating**: 691
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $X$ rupees and wants to buy as many chocolates as possible. Each chocolate costs $Y$ rupees. We need to determine the maximum number of chocolates Chef can purchase with his total budget.

## Intuition & Mathematical Observation
The problem asks for the maximum number of items that can be purchased given a total budget and a fixed cost per item. This is a classic application of **integer division**. 

If Chef has $X$ rupees and each chocolate costs $Y$ rupees, the number of chocolates he can buy is given by the floor of the division $X / Y$. In C++, when two integers are divided using the `/` operator, the result is automatically truncated toward zero (which acts as floor division for positive integers), providing the exact answer required.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a single division operation, which takes $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the variables $X$, $Y$, and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X rupees and each chocolate costs Y rupees.
 * The maximum number of chocolates Chef can buy is the integer part of X / Y.
 * This is equivalent to floor division in integer arithmetic.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= X, Y <= 100
 * Since X and Y are small, standard integer types are sufficient.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The maximum number of chocolates is X divided by Y (integer division).
        // If X < Y, the result of integer division is 0, which is correct.
        long long max_chocolates = x / y;
        
        cout << max_chocolates << "\n";
    }
    
    return 0;
}
```