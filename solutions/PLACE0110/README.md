# [Placing 01 And 10 (PLACE0110)](https://www.codechef.com/problems/PLACE0110)

- **Difficulty Rating**: 1114
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given $X$ strings of "01" and $Y$ strings of "10". We need to arrange all these $X+Y$ strings in a sequence such that the total number of adjacent pairs $(s_i, s_{i+1})$ where $s_i$ ends with the same character that $s_{i+1}$ starts with is minimized. Specifically, we want to minimize the number of transitions between the concatenated strings.

## Intuition & Mathematical Observation
Each individual string ("01" or "10") already contains one internal transition (0 to 1 or 1 to 0). When we concatenate two strings, we create a new transition if the end of the first string matches the start of the second string.

1.  **Internal Transitions**: Every string contributes exactly 1 to the total count of transitions. Since there are $X+Y$ strings, we start with a base of $X+Y$ transitions.
2.  **Concatenation Transitions**:
    *   If we place "01" next to "10" (or vice versa), the end of the first matches the start of the second (e.g., "01" + "10" ends in '1' and starts with '1'). This creates an additional transition.
    *   To minimize the total, we want to avoid these extra transitions.
3.  **The Pattern**:
    *   If $X = Y$, we can alternate them: "01", "10", "01", "10"... This creates no extra transitions between the blocks. The total is simply $X + Y$.
    *   If $X \neq Y$, we are forced to place some identical strings next to each other. By pairing up the smaller count with the larger count, we are left with $|X - Y|$ blocks of the majority string. To connect these remaining blocks, we need $|X - Y| - 1$ additional transitions.
    *   The formula becomes: $(X + Y) + (|X - Y| - 1)$.
    *   Simplifying this: $2 \cdot \max(X, Y) - 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Analysis:
 * Each "01" and "10" string has 1 internal transition.
 * Total internal transitions = X + Y.
 * When we connect two strings:
 * - "01"+"10" or "10"+"01" adds 0 transitions.
 * - "01"+"01" or "10"+"10" adds 1 transition.
 * 
 * To minimize, we alternate as much as possible.
 * If X == Y, we have X+Y-1 connections, all 0-cost. Total = X+Y.
 * If X != Y, we have min(X, Y) pairs of (AB) and |X-Y| remaining strings.
 * The number of 1-cost connections is |X-Y| - 1.
 * Total = (X+Y) + (|X-Y| - 1) = 2*max(X, Y) - 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;
        if (X == Y) {
            cout << X + Y << "\n";
        } else {
            cout << 2 * max(X, Y) - 1 << "\n";
        }
    }
    return 0;
}
```