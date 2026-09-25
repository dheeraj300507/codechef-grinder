# [Rectangle (RECTANGL)](https://www.codechef.com/problems/RECTANGL)

- **Difficulty Rating**: 1146
- **Solved in**: 2 attempt(s)

## Problem Summary
Given four integers representing the lengths of four line segments, determine if these segments can form a rectangle. A rectangle is defined by two pairs of equal opposite sides.

## Intuition & Mathematical Observation
To form a rectangle, the four given side lengths must be able to be grouped into two pairs of equal values. For example, if the sides are $\{a, b, c, d\}$, they form a rectangle if and only if:
1. Two sides are equal to $x$ and the other two are equal to $y$ (where $x$ and $y$ can be the same, forming a square).

**The Sorting Strategy:**
By sorting the four input integers in non-decreasing order, we simplify the comparison logic significantly. If the sides are sorted such that $s_0 \le s_1 \le s_2 \le s_3$, then for the segments to form a rectangle, it must be true that:
- The two smallest sides are equal ($s_0 == s_1$)
- The two largest sides are equal ($s_2 == s_3$)

If these two conditions are met, the segments can be arranged as opposite pairs, satisfying the definition of a rectangle.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Since sorting four elements takes constant time $O(1)$, the overall complexity per test case is $O(1)$.
- **Space Complexity**: $O(1)$, as we only use a fixed-size array of 4 integers regardless of the input values.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * A rectangle requires two pairs of equal sides. 
 * By sorting the four input integers, we ensure that if a rectangle 
 * can be formed, the sides must satisfy:
 * sides[0] == sides[1] AND sides[2] == sides[3].
 */

void solve() {
    int sides[4];
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> sides[i])) return;
    }
    
    // Sort the sides to easily compare pairs
    sort(sides, sides + 4);
    
    // Check if the two smallest are equal and the two largest are equal
    if (sides[0] == sides[1] && sides[2] == sides[3]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```