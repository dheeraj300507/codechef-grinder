# [Lucky Number (LUCKYNUM)](https://www.codechef.com/problems/LUCKYNUM)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $A, B,$ and $C$ (where each digit is between 0 and 9), determine if at least one of these numbers is equal to 7. If any of the numbers is 7, output "YES"; otherwise, output "NO".

## Intuition & Mathematical Observation
The problem asks for a simple logical check. Since we are provided with exactly three inputs, we can use the logical OR (`||`) operator in C++ to verify if any of the variables $A, B,$ or $C$ satisfy the condition $x == 7$. 

- If $A = 7$ OR $B = 7$ OR $C = 7$, the condition evaluates to true.
- Otherwise, it evaluates to false.

This approach is optimal as it performs a constant number of comparisons per test case.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of operations ($O(1)$), leading to a total time complexity of $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of extra space to store the three integers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYNUM
 * The task is to check if at least one of the three given digits (A, B, C) is equal to 7.
 * Constraints: 0 <= A, B, C <= 9, 1 <= T <= 1000.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Check if any of the digits is 7 using logical OR
        if (a == 7 || b == 7 || c == 7) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```