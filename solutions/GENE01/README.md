# [Genes (GENE01)](https://www.codechef.com/problems/GENE01)

- **Difficulty Rating**: 826
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the eye color of a child based on the eye colors of their two parents. The eye colors follow a specific dominance hierarchy:
1. **Brown (R)** is the most dominant.
2. **Blue (B)** is the second most dominant.
3. **Green (G)** is the least dominant.

The child's eye color is determined by the most dominant color present in the parents' genes.

## Intuition & Mathematical Observation
The problem defines a clear hierarchy: **R > B > G**. 

To solve this efficiently, we can map each color to a numerical value representing its dominance:
- **R** = 3
- **B** = 2
- **G** = 1

By assigning these values, the child's eye color simply becomes the `maximum` of the two parents' values. After finding the maximum value, we map it back to the corresponding character ('R', 'B', or 'G') to get the final answer.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of comparisons and arithmetic operations regardless of the input.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that brown (R) is the most common, blue (B) is next, 
 * and green (G) is the rarest.
 * The child's eye color is the most common of the two parents' eye colors.
 * 
 * Hierarchy: R > B > G
 * If we assign values: R = 3, B = 2, G = 1
 * The child's color will be the maximum of the two parents' values.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char p1, p2;
    if (!(cin >> p1 >> p2)) return 0;

    // Map characters to priority values
    auto get_val = [](char c) {
        if (c == 'R') return 3;
        if (c == 'B') return 2;
        return 1; // G
    };

    int v1 = get_val(p1);
    int v2 = get_val(p2);

    int result_val = max(v1, v2);

    if (result_val == 3) {
        cout << "R" << "\n";
    } else if (result_val == 2) {
        cout << "B" << "\n";
    } else {
        cout << "G" << "\n";
    }

    return 0;
}
```