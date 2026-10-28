# [Change Please (CHANGE_PLZ)](https://www.codechef.com/problems/CHANGE_PLZ)

- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an amount $X$ that you owe for a ride. You pay the driver 100 dollars. The driver must return the change in multiples of 10. You need to determine the total amount the driver will return to you, given that they return the maximum possible amount that is a multiple of 10 and does not exceed the actual change due ($100 - X$).

## Intuition & Mathematical Observation
1. **Calculate the exact change**: The actual change due is $R = 100 - X$.
2. **Constraint**: The driver can only return money in multiples of 10.
3. **Mathematical Logic**: To find the largest multiple of 10 less than or equal to $R$, we can use integer division. In C++, when you divide an integer by 10, the remainder is truncated. 
   - By calculating `(R / 10)`, we get the number of "tens" that fit into $R$.
   - Multiplying this result back by 10 gives us the largest multiple of 10 that is $\le R$.
   
   *Example:* If $X = 66$, then $R = 34$. 
   $34 / 10 = 3$ (integer division).
   $3 \times 10 = 30$. The driver returns 30.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You owe X dollars. You pay 100 dollars.
 * The change due is (100 - X) dollars.
 * The driver can only pay back in multiples of 10.
 * We need the maximum multiple of 10 that is less than or equal to (100 - X).
 * 
 * Let R = 100 - X.
 * The driver pays back floor(R / 10) * 10.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the change due
        int change_due = 100 - x;
        
        // Calculate the maximum multiple of 10 <= change_due
        // Using integer division: (change_due / 10) * 10
        int result = (change_due / 10) * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}
```