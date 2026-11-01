# [Dance Moves (DANCEMOVES)](https://www.codechef.com/problems/DANCEMOVES)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at position $X$ on a number line and wants to reach position $Y$. Chef has two types of moves:
1. **Moonwalk**: Move from $k$ to $k + 2$.
2. **Slide**: Move from $k$ to $k - 1$.

We need to find the minimum number of moves required to reach $Y$ starting from $X$.

## Intuition & Mathematical Observation
Let $a$ be the number of moonwalks and $b$ be the number of slides. The final position is given by:
$$X + 2a - b = Y \implies 2a - b = Y - X$$

Let $D = Y - X$. We want to minimize the total moves $M = a + b$.

1. **Case 1: $X \ge Y$**
   Since we only have a move that increases the position by 2 and a move that decreases it by 1, if we are already at or past the target, we can only use the slide move ($k \to k-1$). Thus, we need exactly $X - Y$ moves.

2. **Case 2: $X < Y$**
   We need to cover the distance $D = Y - X$ using a combination of $+2$ and $-1$ moves.
   - If $D$ is **even**: We can reach the target using only moonwalks. We need $D/2$ moves of $+2$. Total moves = $D/2$.
   - If $D$ is **odd**: We cannot reach the target using only $+2$ moves because the sum will always be even. We must use at least one slide move. 
     - If we use one slide ($-1$), we need to cover a net distance of $D+1$. Since $D+1$ is even, we can cover this with $(D+1)/2$ moonwalks.
     - Total moves = $(D+1)/2$ (moonwalks) + $1$ (slide) = $(D+1+2)/2 = (D+3)/2$.
     - Note: In integer division, `D / 2 + 2` is equivalent to `(D + 3) / 2` for odd $D$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations.
- **Space Complexity**: $O(1)$, as no extra data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts at X and wants to reach Y.
 * Moves:
 * 1. k -> k + 2
 * 2. k -> k - 1
 * 
 * Let 'a' be the number of moonwalks (+2) and 'b' be the number of slides (-1).
 * We want to reach Y from X: X + 2a - b = Y
 * 2a - b = Y - X
 * Let D = Y - X.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (X >= Y) {
        // If already at or past target, only slides are useful
        cout << (X - Y) << "\n";
    } else {
        long long D = Y - X;
        if (D % 2 == 0) {
            // Even distance: use only moonwalks
            cout << (D / 2) << "\n";
        } else {
            // Odd distance: use (D+1)/2 moonwalks and 1 slide
            // (D/2) + 2 is equivalent to (D+3)/2 for odd D
            cout << (D / 2 + 2) << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```