# [Tasty Decisions (TASTEDEC)](https://www.codechef.com/problems/TASTEDEC)

- **Difficulty Rating**: 324
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given two types of snacks:
1. **Chocolate**: A packet contains 2 bars, each with a tastiness value of $X$.
2. **Candy**: A packet contains 5 pieces, each with a tastiness value of $Y$.

The goal is to determine which packet provides a higher total tastiness. If the total tastiness is equal, output "Either".

## Intuition & Mathematical Observation
To solve this problem, we need to calculate the total tastiness for both options:
- Total tastiness of Chocolate = $2 \times X$
- Total tastiness of Candy = $5 \times Y$

By comparing these two values:
- If $2X > 5Y$, the Chocolate is tastier.
- If $5Y > 2X$, the Candy is tastier.
- If $2X = 5Y$, both are equally tasty.

Since the constraints on $X$ and $Y$ are small, standard integer types are sufficient, though `long long` is used here for safety.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant number of operations for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Tasty Decisions
 * Logic:
 * - Chocolate packet contains 2 bars of tastiness X: Total = 2 * X
 * - Candy packet contains 5 pieces of tastiness Y: Total = 5 * Y
 * - Compare 2*X and 5*Y and output the result accordingly.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        long long chocolate_tastiness = 2 * x;
        long long candy_tastiness = 5 * y;
        
        if (chocolate_tastiness > candy_tastiness) {
            cout << "Chocolate" << "\n";
        } else if (candy_tastiness > chocolate_tastiness) {
            cout << "Candy" << "\n";
        } else {
            cout << "Either" << "\n";
        }
    }
    
    return 0;
}
```