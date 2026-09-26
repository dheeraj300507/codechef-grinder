# [Election Hopes (ELHP)](https://www.codechef.com/problems/ELHP)

- **Difficulty Rating**: 245
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if Chef has a dominant lead over Chefu in an election. We are given two integers, $X$ and $Y$, representing the number of votes Chef and Chefu have received, respectively. Chef is considered to have a dominant lead if their vote count is at least twice the vote count of Chefu. We need to output "Yes" if this condition is met, and "No" otherwise.

## Intuition & Mathematical Observation
The condition for Chef to have a dominant lead is mathematically defined as:
$$X \ge 2 \times Y$$

Since the constraints on $X$ and $Y$ are small ($1 \le X, Y \le 100$), a simple conditional `if` statement is sufficient to evaluate this inequality. If the condition evaluates to true, we print "Yes"; otherwise, we print "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single arithmetic comparison and a constant-time output operation.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the two input integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Election Hopes
 * Logic: Chef dominates if X >= 2 * Y.
 * Constraints: 1 <= X, Y <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    if (cin >> X >> Y) {
        // Check if Chef's votes are at least double Chefu's votes
        if (X >= 2 * Y) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```