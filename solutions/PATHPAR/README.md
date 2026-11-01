# [Path Parity (PATHPAR)](https://www.codechef.com/problems/PATHPAR)

- **Difficulty Rating**: 1098
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an $N \times N$ grid where the cell at row $i$ and column $j$ contains the value $A_{i,j} = i + N(j-1)$, we need to determine if there exists a path from $(1, 1)$ to $(N, N)$ moving only right or down such that the sum of the values of the cells in the path has a parity equal to $K$ (where $K=0$ for even and $K=1$ for odd).

## Intuition & Mathematical Observation
Any path from $(1, 1)$ to $(N, N)$ consists of exactly $2N-1$ cells. Let the path be a sequence of cells $(r_k, c_k)$ for $k=1, \dots, 2N-1$. The sum of the path is:
$$S = \sum_{k=1}^{2N-1} (r_k + N(c_k - 1))$$

By analyzing the parity of $S$:
1. **If $N$ is odd**: 
   - The term $N(c_k - 1)$ becomes even for all $c_k$.
   - The parity of the sum depends solely on the sum of row indices $\sum r_k$.
   - For any path from $(1, 1)$ to $(N, N)$ in an $N \times N$ grid, the sum of row indices is invariant modulo 2 when $N$ is odd. Specifically, the sum of values will always be odd. Thus, if $K=1$, the answer is "Yes"; if $K=0$, the answer is "No".

2. **If $N$ is even**:
   - The term $N(c_k - 1)$ is always even.
   - We can construct paths that result in both even and odd sums by choosing different routes (e.g., hugging the top-right vs. bottom-left).
   - Therefore, both $K=0$ and $K=1$ are achievable. The answer is always "Yes".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple parity checks. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * If N is odd, the parity of the path sum is always 1. 
 * So if K=1, YES; if K=0, NO.
 * If N is even, both parities (0 and 1) are possible. 
 * So YES for both K=0 and K=1.
 */

void solve() {
    long long N;
    int K;
    cin >> N >> K;

    if (N % 2 != 0) {
        // N is odd: only odd sums are possible
        if (K == 1) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    } else {
        // N is even: both even and odd sums are possible
        cout << "Yes" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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