# [Chess Ratings (C_RATING)](https://www.codechef.com/problems/C_RATING)

- **Difficulty Rating**: 651
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice currently has a chess rating of $X$. She wants to reach a target rating of at least $Y$. Each game she wins increases her rating by exactly 8 points. We need to determine the minimum number of games Alice must win to achieve a rating of at least $Y$.

## Intuition & Mathematical Observation
To reach the target rating $Y$ starting from $X$, Alice needs a total increase of at least $Y - X$. 

1. If $X \ge Y$, Alice has already reached her goal, so the number of games required is **0**.
2. If $X < Y$, let $n$ be the number of games won. Each win adds 8 points, so we need:
   $$X + 8n \ge Y$$
   $$8n \ge Y - X$$
   $$n \ge \frac{Y - X}{8}$$

Since $n$ must be an integer, we take the ceiling of the division: $n = \lceil \frac{Y - X}{8} \rceil$. 
In integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated as `(a + b - 1) / b`. Thus, the formula becomes `(Y - X + 7) / 8`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice starts with rating X and needs to reach at least Y.
 * Each win increases the rating by 8.
 * Let n be the number of games won.
 * We need: X + 8 * n >= Y
 * 8 * n >= Y - X
 * n >= (Y - X) / 8
 * Since n must be an integer, n = ceil((Y - X) / 8).
 * 
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b
 * for positive integers a and b.
 * Here, a = Y - X, b = 8.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (x >= y) {
            cout << 0 << "\n";
        } else {
            long long diff = y - x;
            // Calculate ceiling of diff / 8 using integer division
            long long n = (diff + 7) / 8;
            cout << n << "\n";
        }
    }

    return 0;
}
```