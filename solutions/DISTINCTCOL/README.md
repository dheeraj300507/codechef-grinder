# [Distinct Colors (DISTINCTCOL)](https://www.codechef.com/problems/DISTINCTCOL)

- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ types of colors, where the $i$-th color has $A_i$ balls. We need to distribute these balls into boxes such that no box contains two balls of the same color. The goal is to find the minimum number of boxes required to satisfy this condition.

## Intuition & Mathematical Observation
To ensure that no box contains two balls of the same color, every ball of a specific color must be placed in a unique box. 

1. If we have a color that appears $M$ times (where $M = \max(A_1, A_2, \dots, A_N)$), we are forced to use at least $M$ boxes because each of those $M$ balls must occupy a different box.
2. If we have $M$ boxes, we can always distribute the balls of any color $i$ (where $A_i \le M$) across $A_i$ distinct boxes. Since no color exceeds $M$ balls, we will never be forced to put two balls of the same color in the same box.

Therefore, the minimum number of boxes required is simply the maximum value among all $A_i$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the list of $N$ integers exactly once to find the maximum.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the current maximum value and the input variable.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N types of colors, with A_i balls of color i.
 * We need to place these balls into boxes such that no box contains two balls of the same color.
 * 
 * Let M be the maximum number of balls of any single color, i.e., M = max(A_1, A_2, ..., A_N).
 * If we have M balls of a specific color, we must have at least M boxes to ensure that 
 * each of those M balls is in a different box.
 * 
 * Conversely, if we have M boxes, we can always distribute the balls such that no box 
 * contains two balls of the same color. We can do this by placing the balls of each color 
 * into distinct boxes. Since no color has more than M balls, we will never run out of 
 * boxes for any color.
 * 
 * Therefore, the minimum number of boxes required is exactly the maximum value among A_i.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        long long max_balls = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            // Update max_balls if the current color count is higher
            if (a > max_balls) {
                max_balls = a;
            }
        }
        
        cout << max_balls << "\n";
    }
    
    return 0;
}
```