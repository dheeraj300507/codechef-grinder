# [Test Score (CHEFSCORE)](https://www.codechef.com/problems/CHEFSCORE)

- **Difficulty Rating**: 610
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a test consisting of $N$ problems, where each problem is worth $X$ marks. For each problem, Chef can either score $X$ marks (if solved correctly) or $0$ marks (if solved incorrectly). Given the total score $Y$ that Chef achieved, determine if it is possible for Chef to have obtained exactly $Y$ marks.

## Intuition & Mathematical Observation
Since each problem is worth $X$ marks, any total score $Y$ must be a multiple of $X$. Let $k$ be the number of problems Chef solved correctly. Then:
$$Y = k \times X$$

From this equation, we can derive two conditions that must be satisfied for $Y$ to be a valid score:
1. **Divisibility**: $Y$ must be perfectly divisible by $X$ (i.e., $Y \pmod X == 0$). This ensures that the score is composed of full-mark problems.
2. **Constraint on $k$**: The number of problems solved ($k = Y / X$) cannot exceed the total number of problems available ($N$). Therefore, $Y / X \le N$.

If both conditions are met, it is possible to achieve the score $Y$. Note that if $Y=0$, the conditions are naturally satisfied (Chef solved 0 problems), which is always possible.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N problems, each worth X marks.
 * Chef can get either 0 or X marks per problem.
 * Total score Y must be a multiple of X, specifically Y = k * X,
 * where k is the number of problems solved correctly.
 * Since there are N problems, 0 <= k <= N.
 * Therefore, Y must satisfy:
 * 1. Y % X == 0 (Y must be divisible by X)
 * 2. (Y / X) <= N (The number of problems solved cannot exceed total problems)
 * 3. Y >= 0 (Already guaranteed by constraints)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // Case where Chef scores 0: Always possible
        if (y == 0) {
            cout << "YES" << "\n";
        } 
        // Check if Y is a multiple of X and the number of problems solved is <= N
        else if (y % x == 0 && (y / x) <= n) {
            cout << "YES" << "\n";
        } 
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```