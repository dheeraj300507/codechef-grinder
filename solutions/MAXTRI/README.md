# [Max Triangle (MAXTRI)](https://www.codechef.com/problems/MAXTRI)

- **Difficulty Rating**: 664
- **Solved in**: 3 attempt(s)

## Problem Summary
Given a set of sticks with lengths $1, 2, 3, \dots, N$, the goal is to select three sticks that form a non-degenerate triangle such that their perimeter ($A + B + C$) is maximized. If no such triangle can be formed, output $-1$.

## Intuition & Mathematical Observation
To maximize the perimeter $A + B + C$, we should aim to pick the largest possible values for the sides. Let the sides be $A, B,$ and $C$ such that $A < B < C$. To maximize the sum, we start by testing the largest available sticks: $C = N$, $B = N-1$, and $A = N-2$.

For a triangle to be non-degenerate, it must satisfy the triangle inequality: the sum of the two smaller sides must be strictly greater than the largest side ($A + B > C$).

Substituting our chosen values:
$$(N-2) + (N-1) > N$$
$$2N - 3 > N$$
$$N > 3$$

*   **If $N < 4$**: It is impossible to satisfy the triangle inequality with the available sticks. For example, if $N=3$, the only possible combination is $(1, 2, 3)$, where $1+2=3$, which is degenerate. Thus, we output $-1$.
*   **If $N \ge 4$**: The largest possible perimeter is obtained by picking $N, N-1,$ and $N-2$. The perimeter is $N + (N-1) + (N-2) = 3N - 3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * We have sticks of lengths 1, 2, ..., N.
 * A triangle is non-degenerate if A + B > C, where C is the max side.
 * To maximize perimeter A + B + C, we pick the largest available sticks:
 * C = N, B = N-1, A = N-2.
 * Condition: (N-1) + (N-2) > N  => 2N - 3 > N => N > 3.
 * 
 * If N < 4, no such triangle exists.
 * If N >= 4, the maximum perimeter is N + (N-1) + (N-2) = 3N - 3.
 */

void solve() {
    long long N;
    if (!(std::cin >> N)) return;

    // The smallest N that allows a triangle is 4 (sides 2, 3, 4: 2+3 > 4).
    // For N=3, sides are 1, 2, 3: 1+2 = 3 (degenerate).
    if (N < 4) {
        std::cout << -1 << "\n";
    } else {
        // 3N - 3 can be up to 3 * 10^8 - 3, which fits in a standard 32-bit signed int,
        // but using long long is safer for competitive programming.
        std::cout << (3 * N - 3) << "\n";
    }
}

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    if (!(std::cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```