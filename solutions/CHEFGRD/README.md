# [Akash and Grid (CHEFGRD)](https://www.codechef.com/problems/CHEFGRD)

- **Difficulty Rating**: 1311
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an $N \times N$ grid (where $N$ is odd), the center of the grid is defined at coordinates $(C, C)$, where $C = \frac{N+1}{2}$. We are given a starting position $(x_s, y_s)$. We can move diagonally for free (cost 0) or move horizontally/vertically to an adjacent cell (cost 1). The goal is to find the minimum cost to reach the center $(C, C)$.

## Intuition & Mathematical Observation
The key to this problem lies in the **parity** of the coordinates. 

1.  **Diagonal Moves**: A diagonal move changes both the $x$ and $y$ coordinates by $\pm 1$. Consequently, the sum $(x + y)$ changes by either $+2, 0,$ or $-2$. This means the parity of $(x + y)$ remains **invariant** under diagonal moves.
2.  **Center Parity**: The center is at $(C, C)$, so the sum of its coordinates is $2C$. Since $2C$ is always even, the target sum is always even.
3.  **Reaching the Center**:
    *   If the starting sum $(x_s + y_s)$ has the same parity as the center sum $(2C)$, it means $(x_s + y_s)$ is even. Since diagonal moves preserve parity, we can reach the center using only diagonal moves at a **cost of 0**.
    *   If the starting sum $(x_s + y_s)$ has a different parity than the center sum, it means $(x_s + y_s)$ is odd. We must perform at least one horizontal or vertical move to change the parity of the sum to even. Once the parity is even, we can reach the center using only diagonal moves. Thus, the minimum **cost is 1**.

Essentially, the answer is $0$ if $(x_s + y_s) \equiv (C + C) \pmod 2$, and $1$ otherwise.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the center coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid is N x N where N is odd. The center is (C, C) where C = (N + 1) / 2.
 * Diagonal moves cost 0. Horizontal/Vertical moves cost 1.
 * 
 * Parity of (x + y) is invariant under diagonal moves.
 * If (xs + ys) has the same parity as (C + C), cost is 0.
 * Otherwise, cost is 1.
 */

void solve() {
    long long N, xs, ys;
    if (!(cin >> N >> xs >> ys)) return;
    
    long long center = (N + 1) / 2;
    
    // Parity of center coordinates sum: (center + center) = 2 * center (always even)
    // Parity of current coordinates sum: (xs + ys)
    
    if ((xs + ys) % 2 == (center + center) % 2) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O
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