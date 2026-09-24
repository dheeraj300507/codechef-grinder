# [Sweets Shop (SWEETSHOP)](https://www.codechef.com/problems/SWEETSHOP)

- **Difficulty Rating**: 262
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an initial amount of money $X$ and the number of laddus $N$ you wish to purchase. Each laddu costs 10 units. After buying the laddus, you want to spend all your remaining money on jalebis, which cost 20 units each. The goal is to calculate the maximum number of jalebis you can buy with the leftover money.

## Intuition & Mathematical Observation
The problem can be broken down into two simple arithmetic steps:
1. **Calculate Remaining Money**: Since each laddu costs 10, the total cost for $N$ laddus is $10 \times N$. Subtracting this from the initial amount $X$ gives the remaining budget:
   $$\text{Remaining Money} = X - (10 \times N)$$
2. **Calculate Jalebis**: Since each jalebi costs 20, the number of jalebis you can afford is the integer division of the remaining money by 20:
   $$\text{Number of Jalebis} = \lfloor \frac{\text{Remaining Money}}{20} \rfloor$$

Because the constraints are small ($X \le 100, N \le 10$), standard integer arithmetic is sufficient to solve this problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Initial money: X
 * - Cost of one laddu: 10
 * - Number of laddus bought: N
 * - Cost of one jalebi: 20
 * 
 * Calculation:
 * 1. Total cost of laddus = 10 * N
 * 2. Remaining money = X - (10 * N)
 * 3. Number of jalebis = Remaining money / 20 (integer division)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, N;
    // Reading input until EOF to handle test cases
    while (cin >> X >> N) {
        // Calculate remaining money after buying laddus
        long long remaining_money = (long long)X - (10LL * N);
        
        // Calculate how many jalebis can be bought with the remainder
        long long jalebis = remaining_money / 20LL;
        
        cout << jalebis << "\n";
    }

    return 0;
}
```