# [Vishesh and his Popcorn Combo (POPCORN)](https://www.codechef.com/problems/POPCORN)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
Vishesh is choosing between three different popcorn combos (A, B, and C). Each combo consists of two components, each with a specific preparation time. The "satisfaction" of a combo is defined as the sum of the preparation times of its two components. The goal is to determine the maximum satisfaction value among the three available combos.

## Intuition & Mathematical Observation
The problem asks us to compare three values, where each value is the sum of two integers. 
1. Let the durations for combo A be $a_1$ and $a_2$. Satisfaction $S_A = a_1 + a_2$.
2. Let the durations for combo B be $b_1$ and $b_2$. Satisfaction $S_B = b_1 + b_2$.
3. Let the durations for combo C be $c_1$ and $c_2$. Satisfaction $S_C = c_1 + c_2$.

We simply need to calculate these three sums and output $\max(S_A, S_B, S_C)$. Since the input values can be as large as $10^9$, the sum can reach $2 \times 10^9$. While this fits within a standard 32-bit signed integer, using `long long` in C++ is a best practice to ensure no overflow occurs during intermediate calculations.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of additions and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three combos A, B, and C.
 * Each combo consists of two parts (Popcorn and Coke) with given durations.
 * Satisfaction = Sum of durations of the two parts in a combo.
 * We need to find the maximum satisfaction among the three combos.
 * 
 * Constraints:
 * Durations are up to 10^9. The sum can be up to 2 * 10^9, which fits in a 
 * standard 32-bit signed integer, but using 'long long' is safer and 
 * standard practice in competitive programming to prevent overflow.
 * 
 * Complexity:
 * Time: O(1) per test case, O(T) total.
 * Space: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a1, a2, b1, b2, c1, c2;
        
        // Read input for the three combos
        cin >> a1 >> a2;
        cin >> b1 >> b2;
        cin >> c1 >> c2;
        
        // Calculate satisfaction for each combo
        long long satA = a1 + a2;
        long long satB = b1 + b2;
        long long satC = c1 + c2;
        
        // Find the maximum of the three
        long long maxSat = max({satA, satB, satC});
        
        // Output the result
        cout << maxSat << "\n";
    }
    
    return 0;
}
```