# [Monopoly in Chefland (MONOPOLY)](https://www.codechef.com/problems/MONOPOLY)

- **Difficulty Rating**: 482
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef owns three companies with annual revenues $R_1, R_2,$ and $R_3$. A company is considered to have a "monopolistic advantage" if its revenue is strictly greater than the sum of the revenues of the other two companies. Given the revenues of the three companies, determine if any of them possess this advantage.

## Intuition & Mathematical Observation
To determine if a company has a monopolistic advantage, we must check three distinct conditions based on the problem definition:
1. Company 1: $R_1 > R_2 + R_3$
2. Company 2: $R_2 > R_1 + R_3$
3. Company 3: $R_3 > R_1 + R_2$

If any one of these conditions evaluates to `true`, the answer is **YES**. If none of them are satisfied, the answer is **NO**. Since the constraints on $R$ are very small ($1 \le R \le 10$), standard integer types are perfectly sufficient to handle the arithmetic without overflow.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input revenues regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three companies with revenues R1, R2, and R3.
 * A company has a monopolistic advantage if its revenue is strictly greater 
 * than the sum of the other two.
 * 
 * Conditions:
 * 1. R1 > (R2 + R3)
 * 2. R2 > (R1 + R3)
 * 3. R3 > (R1 + R2)
 * 
 * If any of these conditions are true, output YES, otherwise NO.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long r1, r2, r3;
        cin >> r1 >> r2 >> r3;
        
        // Check if any company has a monopolistic advantage
        if ((r1 > (r2 + r3)) || (r2 > (r1 + r3)) || (r3 > (r1 + r2))) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```