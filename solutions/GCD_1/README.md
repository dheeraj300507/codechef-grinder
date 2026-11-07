# [GCD to 1 (Easy) (GCD_1)](https://www.codechef.com/problems/GCD_1)

- **Difficulty Rating**: 1277
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $M$, construct an $N \times M$ matrix such that every element $A_{i,j} \ge 2$, and the Greatest Common Divisor (GCD) of every row and every column is exactly 1.

## Intuition & Mathematical Observation
To ensure the GCD of a set of numbers is 1, it is sufficient to include at least two coprime numbers in that set. The simplest pair of coprime numbers is 2 and 3, since $\gcd(2, 3) = 1$.

If we can construct the matrix such that every row and every column contains at least one 2 and at least one 3, the GCD of that row/column will necessarily be 1. 

We can achieve this using a checkerboard pattern:
- Assign $A_{i,j} = 2$ if $(i + j)$ is even.
- Assign $A_{i,j} = 3$ if $(i + j)$ is odd.

**Why this works:**
- In any row or column of length $\ge 2$, the indices $(i+j)$ will alternate between even and odd values.
- Therefore, every row and every column will contain both a 2 and a 3.
- Since $\gcd(2, 3) = 1$, the GCD of any row or column containing both will be 1.

## Complexity Analysis
- **Time Complexity**: $O(N \times M)$, as we iterate through every cell of the $N \times M$ matrix exactly once to print the values.
- **Space Complexity**: $O(1)$, as we print the values directly without storing the matrix in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct an N x M matrix such that the GCD of every row and every column is 1.
 * Elements must be >= 2.
 * 
 * Strategy:
 * Use a checkerboard pattern with 2 and 3.
 * A[i][j] = 2 if (i + j) is even
 * A[i][j] = 3 if (i + j) is odd
 * This ensures every row and column contains at least one 2 and one 3.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Checkerboard pattern
            if ((i + j) % 2 == 0) {
                cout << 2 << (j == M - 1 ? "" : " ");
            } else {
                cout << 3 << (j == M - 1 ? "" : " ");
            }
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```