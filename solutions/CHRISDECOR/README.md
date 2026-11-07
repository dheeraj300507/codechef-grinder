# [Decorating Christmas Tree (CHRISDECOR)](https://www.codechef.com/problems/CHRISDECOR)

- **Difficulty Rating**: 1102
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ Christmas trees to decorate. There are two ways to decorate a tree:
1. Using **1 large** and **3 small** ornaments.
2. Using **2 large** ornaments.

Given $N$ trees, $X$ total large ornaments, and $Y$ total small ornaments, determine if it is possible to decorate all $N$ trees such that each tree is decorated using exactly one of the two methods.

## Intuition & Mathematical Observation
Let $a$ be the number of trees decorated using the first method (1 large, 3 small) and $b$ be the number of trees decorated using the second method (2 large).

We have the following system of constraints:
1. **Total trees**: $a + b = N \implies b = N - a$
2. **Large ornaments**: $1 \cdot a + 2 \cdot b \le X$
3. **Small ornaments**: $3 \cdot a \le Y$

Substitute $b = N - a$ into the large ornament constraint:
$a + 2(N - a) \le X$
$a + 2N - 2a \le X$
$2N - a \le X \implies a \ge 2N - X$

Additionally, we know:
- $a \ge 0$ (cannot have negative trees)
- $a \le N$ (cannot have more trees of type 1 than total trees)
- $a \le \lfloor Y/3 \rfloor$ (from the small ornament constraint)

Combining these, a valid $a$ exists if there is an integer in the range:
$[\max(0, 2N - X), \min(N, \lfloor Y/3 \rfloor)]$

If the `lower_bound` is less than or equal to the `upper_bound`, a solution exists.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and bounds.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let 'a' be the number of leaves decorated with (1 large, 3 small).
 * Let 'b' be the number of leaves decorated with (2 large).
 * 
 * We have the following constraints:
 * 1) a + b = N
 * 2) a + 2b <= X (Total large ornaments used must be <= X)
 * 3) 3a <= Y (Total small ornaments used must be <= Y)
 * 
 * From (1), b = N - a.
 * Substitute b into (2):
 * a + 2(N - a) <= X
 * a + 2N - 2a <= X
 * 2N - a <= X
 * a >= 2N - X
 * 
 * Also, since b >= 0, we have N - a >= 0 => a <= N.
 * Since a >= 0, we have a >= 0.
 * Combining: max(0, 2N - X) <= a <= min(N, Y / 3).
 * 
 * A solution exists if there exists an integer 'a' such that:
 * max(0, 2N - X) <= a <= min(N, Y / 3)
 */

void solve() {
    long long N, X, Y;
    cin >> N >> X >> Y;

    // Calculate the valid range for 'a'
    long long lower_bound = max(0LL, 2 * N - X);
    long long upper_bound = min(N, Y / 3);
    
    // If the range is valid, output YES
    if (lower_bound <= upper_bound) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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