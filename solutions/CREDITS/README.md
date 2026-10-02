# [Complete the credits (CREDITS)](https://www.codechef.com/problems/CREDITS)

- **Difficulty Rating**: 809
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to categorize a student's credit score ($X$) into one of three categories based on the following rules:
- **Overload**: If the credits are strictly greater than 65.
- **Underload**: If the credits are strictly less than 35.
- **Normal**: If the credits are between 35 and 65 (inclusive).

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the ranges are mutually exclusive and cover all possible integer values for $X$, we can use a simple `if-else if-else` structure:
1. Check if $X > 65$ first.
2. If not, check if $X < 35$.
3. If neither condition is met, the value must fall within the range $[35, 65]$, which corresponds to "Normal".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only store a single integer variable $X$ per test case and do not use any auxiliary data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Overload: X > 65
 * - Underload: X < 35
 * - Normal: 35 <= X <= 65
 * 
 * Constraints:
 * - 1 <= T <= 100
 * - 1 <= X <= 100
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
        
        if (x > 65) {
            cout << "Overload" << "\n";
        } else if (x < 35) {
            cout << "Underload" << "\n";
        } else {
            cout << "Normal" << "\n";
        }
    }
    
    return 0;
}
```