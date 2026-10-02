# [Alternate Jumps (ALJMP)](https://www.codechef.com/problems/ALJMP)

- **Difficulty Rating**: 648
- **Solved in**: 1 attempt(s)

## Problem Summary
A frog starts at position $N$ on a number line. It performs $N-1$ jumps. For each jump $i$ (where $1 \le i \le N-1$):
- If $i$ is odd, the frog moves $X = X - (N - i)$.
- If $i$ is even, the frog moves $X = X + (N - i)$.
The goal is to determine the final position of the frog after $N-1$ jumps.

## Intuition & Mathematical Observation
To find the pattern, we can trace the frog's position for small values of $N$:

| $N$ | Sequence of Jumps | Final Position |
| :--- | :--- | :--- |
| 2 | $2 - 1 = 1$ | 1 |
| 3 | $3 - 2 = 1 \to 1 + 1 = 2$ | 2 |
| 4 | $4 - 3 = 1 \to 1 + 2 = 3 \to 3 - 1 = 2$ | 2 |
| 5 | $5 - 4 = 1 \to 1 + 3 = 4 \to 4 - 2 = 2 \to 2 + 1 = 3$ | 3 |
| 6 | $6 - 5 = 1 \to 1 + 4 = 5 \to 5 - 3 = 2 \to 2 + 2 = 4 \to 4 - 1 = 3$ | 3 |

By observing the results:
- $N=2 \to 1$
- $N=3 \to 2$
- $N=4 \to 2$
- $N=5 \to 3$
- $N=6 \to 3$

The pattern is clearly $\lceil N / 2 \rceil$. In integer arithmetic, this can be calculated efficiently using the formula `(N + 1) / 2`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the result is calculated using a simple arithmetic formula. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The frog starts at position N and makes N-1 jumps.
 * By tracing the sequence for small N, we observe that the 
 * final position follows the pattern ceil(N / 2).
 */

void solve() {
    long long N;
    cin >> N;
    // The pattern observed is ceil(N / 2.0)
    // Using integer arithmetic: (N + 1) / 2
    cout << (N + 1) / 2 << "\n";
}

int main() {
    // Fast I/O for performance
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