# [Arya In Grid (ARYAGRID)](https://www.codechef.com/problems/ARYAGRID)

- **Difficulty Rating**: 1341
- **Solved in**: 1 attempt(s)

## Problem Summary
Arya is placed at a starting coordinate $(X_0, Y_0)$ on an $N \times M$ grid. She can move exactly $L$ units in any of the four cardinal directions (up, down, left, right). We need to determine the total number of distinct cells $(x, y)$ in the grid that Arya can reach, where $1 \le x \le N$ and $1 \le y \le M$.

## Intuition & Mathematical Observation
The movement constraint implies that Arya can reach any cell $(x, y)$ if and only if:
1. $x \equiv X_0 \pmod L$ and $1 \le x \le N$
2. $y \equiv Y_0 \pmod L$ and $1 \le y \le M$

Because the movement in the $x$-direction is independent of the movement in the $y$-direction, the total number of reachable cells is simply the product of the number of reachable rows and the number of reachable columns.

**Calculating reachable rows:**
Arya can reach row $x$ if $x = X_0 + k \cdot L$ for some integer $k$.
- The number of rows reachable "above" $X_0$ (including $X_0$ itself) is given by how many times we can subtract $L$ until we hit the boundary $1$. This is $\lfloor \frac{X_0 - 1}{L} \rfloor$.
- The number of rows reachable "below" $X_0$ is given by how many times we can add $L$ until we hit the boundary $N$. This is $\lfloor \frac{N - X_0}{L} \rfloor$.
- Including the starting row $X_0$ itself, the total count is:
  $$\text{Total Rows} = \left\lfloor \frac{X_0 - 1}{L} \right\rfloor + \left\lfloor \frac{N - X_0}{L} \right\rfloor + 1$$

The same logic applies to the columns using $M$ and $Y_0$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Arya starts at (X0, Y0) and can jump exactly L units in 4 directions.
 * This means Arya can reach any cell (x, y) such that:
 * x = X0 + k1 * L, where 1 <= x <= N
 * y = Y0 + k2 * L, where 1 <= y <= M
 * 
 * The total number of reachable cells is (number of reachable rows) * (number of reachable columns).
 */

void solve() {
    long long N, M, X0, Y0, L;
    if (!(cin >> N >> M >> X0 >> Y0 >> L)) return;

    // Number of reachable rows:
    // Rows are X0 + k*L.
    // k can be negative: X0 - k*L >= 1  => k*L <= X0 - 1 => k <= (X0 - 1) / L
    // k can be positive: X0 + k*L <= N  => k*L <= N - X0 => k <= (N - X0) / L
    long long rows_below = (X0 - 1) / L;
    long long rows_above = (N - X0) / L;
    long long total_rows = rows_below + rows_above + 1;

    // Number of reachable columns:
    long long cols_left = (Y0 - 1) / L;
    long long cols_right = (M - Y0) / L;
    long long total_cols = cols_left + cols_right + 1;

    long long ans = total_rows * total_cols;
    cout << ans << "\n";
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