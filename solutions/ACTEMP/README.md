# [Air Conditioner Temperature (ACTEMP)](https://www.codechef.com/problems/ACTEMP)

- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice, Bob, and Charlie want to set the air conditioner to a temperature $T$. Their requirements are as follows:
- Alice wants $T \ge A$.
- Bob wants $T \le B$.
- Charlie wants $T \ge C$.

We need to determine if there exists a temperature $T$ that satisfies all three conditions simultaneously.

## Intuition & Mathematical Observation
To satisfy all three conditions, the temperature $T$ must satisfy:
1. $T \ge A$
2. $T \ge C$
3. $T \le B$

Combining the first two conditions, we get $T \ge \max(A, C)$. 
For a valid temperature $T$ to exist, the lower bound must be less than or equal to the upper bound. Therefore, the condition for a solution to exist is:
$$\max(A, C) \le B$$

If this inequality holds, we can simply pick $T = \max(A, C)$, which will satisfy all three people. Otherwise, no such temperature exists.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing a comparison and a `max` operation. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice wants temperature T >= A.
 * Charlie wants temperature T >= C.
 * Combining these, T must be >= max(A, C).
 * Bob wants temperature T <= B.
 * 
 * For a valid temperature T to exist, we need:
 * max(A, C) <= T <= B
 * 
 * This is possible if and only if:
 * max(A, C) <= B
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // The condition for a valid temperature is that the lower bound
        // (the maximum of Alice's and Charlie's requirements) must be 
        // less than or equal to the upper bound (Bob's requirement).
        if (max(a, c) <= b) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```