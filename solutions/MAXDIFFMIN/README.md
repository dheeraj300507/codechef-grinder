# [Max minus Min (MAXDIFFMIN)](https://www.codechef.com/problems/MAXDIFFMIN)

- **Difficulty Rating**: 339
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $A$, $B$, and $C$ such that $A < B < C$, we are required to calculate the difference between the maximum value and the minimum value among the three integers.

## Intuition & Mathematical Observation
The problem explicitly states the condition $A < B < C$. 
- Since $C$ is the largest value, $\max(A, B, C) = C$.
- Since $A$ is the smallest value, $\min(A, B, C) = A$.

Therefore, the expression $\max(A, B, C) - \min(A, B, C)$ simplifies directly to $C - A$. We do not need to perform any comparisons or sorting because the relative order is already provided by the problem constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing a single subtraction operation.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three integers A, B, and C such that A < B < C.
 * We need to find max(A, B, C) - min(A, B, C).
 * Since A < B < C, the maximum value is always C and the minimum value is always A.
 * Therefore, the result is simply C - A.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Given the constraint A < B < C, 
        // max(A, B, C) is C and min(A, B, C) is A.
        long long result = c - a;
        
        cout << result << "\n";
    }
    
    return 0;
}
```