# [Olympics 2024 (OLYMPICS24)](https://www.codechef.com/problems/OLYMPICS24)

- **Difficulty Rating**: 283
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to determine how many additional medals are required for a country to reach a total of 5 gold, 5 silver, and 5 bronze medals. You are given the current counts of gold ($G$), silver ($S$), and bronze ($B$) medals.

## Intuition & Mathematical Observation
The target for each category is 5 medals. Since the input guarantees that the current number of medals for each category is between 1 and 5, we can calculate the deficit for each type individually:
- Gold needed: $5 - G$
- Silver needed: $5 - S$
- Bronze needed: $5 - B$

The total number of additional medals required is simply the sum of these three differences:
$$\text{Total Needed} = (5 - G) + (5 - S) + (5 - B)$$
This can be simplified to:
$$\text{Total Needed} = 15 - (G + S + B)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The goal is to have 5 gold, 5 silver, and 5 bronze medals.
 * Given current medals G, S, B, the number of additional medals needed is:
 * (5 - G) + (5 - S) + (5 - B)
 * Since 1 <= G, S, B <= 5, the result will always be non-negative.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, S, B;
    
    // Reading the current medal counts
    if (cin >> G >> S >> B) {
        int needed_gold = 5 - G;
        int needed_silver = 5 - S;
        int needed_bronze = 5 - B;
        
        int total_needed = needed_gold + needed_silver + needed_bronze;
        
        cout << total_needed << "\n";
    }

    return 0;
}
```