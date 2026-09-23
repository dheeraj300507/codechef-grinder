# [Perfect Trio (PERFECTTRIO)](https://www.codechef.com/problems/PERFECTTRIO)

- **Difficulty Rating**: 455
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $A$, $B$, and $C$ representing the ages of three people, determine if the group is "perfect." A group is considered perfect if any one of the ages is equal to the sum of the other two. Specifically, the condition is satisfied if $A = B + C$, $B = A + C$, or $C = A + B$.

## Intuition & Mathematical Observation
The problem asks us to verify if the given set of numbers satisfies a specific additive property. Since there are only three possible scenarios where one number equals the sum of the remaining two, we can simply use a conditional `if` statement to check all three possibilities:
1. Is $A$ the sum of $B$ and $C$?
2. Is $B$ the sum of $A$ and $C$?
3. Is $C$ the sum of $A$ and $B$?

If any of these conditions evaluate to `true`, the group is perfect, and we output "YES". Otherwise, we output "NO". Given the constraints ($1 \le A, B, C \le 100$), standard integer arithmetic is perfectly safe and efficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a constant number of arithmetic operations and comparisons, the time taken does not scale with the input values.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A group of three people with ages A, B, and C is "perfect" if:
 * 1. A = B + C
 * 2. B = A + C
 * 3. C = A + B
 * 
 * Since the constraints are small (1 <= A, B, C <= 100), standard integer types
 * are sufficient. We check these three conditions for each test case.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // Check if any one age is the sum of the other two
        if ((a == b + c) || (b == a + c) || (c == a + B)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```