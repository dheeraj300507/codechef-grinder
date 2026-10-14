# [Blue and Black Pens (BLUEBLACK)](https://www.codechef.com/problems/BLUEBLACK)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to purchase pens for his work. He has two possible ways to satisfy his requirement:
1. Buy 3 blue pens.
2. Buy 1 blue pen and 1 black pen.

Given the cost of a single blue pen ($A$) and a single black pen ($B$), determine the minimum cost required to satisfy the requirement.

## Intuition & Mathematical Observation
The problem asks us to choose the cheaper of two distinct strategies. 
- The cost of the first strategy is simply $3 \times A$.
- The cost of the second strategy is $A + B$.

By comparing these two values using the `min()` function, we can identify the minimum expenditure required. Given the constraints $10 \le A, B \le 50$, the maximum possible cost is $150$, which fits comfortably within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution performs a constant number of arithmetic operations and a single comparison.
- **Space Complexity**: $O(1)$ as we only store two integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs either:
 * 1. 3 blue pens: Cost = 3 * A
 * 2. 1 blue pen and 1 black pen: Cost = A + B
 * 
 * We need to find the minimum of these two options: min(3 * A, A + B).
 * Constraints: 10 <= A, B <= 50.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    
    // Reading the two integers A and B
    if (cin >> A >> B) {
        long long option1 = 3 * A;
        long long option2 = A + B;
        
        // Output the minimum of the two calculated costs
        cout << min(option1, option2) << "\n";
    }

    return 0;
}
```