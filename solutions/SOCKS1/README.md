# [Valid Pair (SOCKS1)](https://www.codechef.com/problems/SOCKS1)

- **Difficulty Rating**: 851
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $A$, $B$, and $C$ representing the colors of three individual socks, determine if it is possible to form at least one matching pair. A pair is formed if any two socks share the same color.

## Intuition & Mathematical Observation
To form a pair, at least two of the three given integers must be equal. We can evaluate this using simple logical comparisons:
1. Check if $A$ is equal to $B$.
2. Check if $A$ is equal to $C$.
3. Check if $B$ is equal to $C$.

If any of these conditions evaluate to `true`, then a matching pair exists, and we output "YES". Otherwise, all three socks have distinct colors, and we output "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input values.
- **Space Complexity**: $O(1)$ — We only store three integer variables, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three integers A, B, and C representing the colors of three socks.
 * We need to determine if at least two of these socks have the same color.
 * This is equivalent to checking if:
 * A == B OR A == C OR B == C.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    // Read the three sock colors
    if (cin >> A >> B >> C) {
        // Check if any two socks match
        if (A == B || A == C || B == C) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```