# [Odd Even Binary String (ODDEVENBS)](https://www.codechef.com/problems/ODDEVENBS)

- **Difficulty Rating**: 1099
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a binary array $B$ of length $N$, where $B_i$ represents the parity of the frequency of the number $i$ in an unknown array $A$ of length $N$. Specifically, $B_i = 1$ if the frequency of $i$ in $A$ is odd, and $B_i = 0$ if it is even. We need to determine if such an array $A$ can exist.

## Intuition & Mathematical Observation
Let $f_i$ be the frequency of the number $i$ in array $A$. We are given that the total number of elements in $A$ is $N$, so:
$$\sum_{i=1}^{N} f_i = N$$

We know that $f_i \equiv B_i \pmod 2$. We can express each frequency as $f_i = 2k_i + B_i$, where $k_i \ge 0$ is some non-negative integer. Substituting this into the summation:
$$\sum_{i=1}^{N} (2k_i + B_i) = N$$
$$2 \sum_{i=1}^{N} k_i + \sum_{i=1}^{N} B_i = N$$

Let $S = \sum_{i=1}^{N} B_i$ be the total count of $1$s in the binary array $B$. The equation becomes:
$$2 \sum_{i=1}^{N} k_i = N - S$$

For a valid array $A$ to exist, there must exist non-negative integers $k_i$ satisfying this equation. Since the left side is always even, $N - S$ must be even. This implies that $N$ and $S$ must have the same parity ($N \equiv S \pmod 2$). Additionally, since $k_i \ge 0$, we require $N - S \ge 0$, which is always true because $S$ (the number of $1$s) cannot exceed $N$ (the total length of the array).

Thus, the condition for a valid array $A$ is simply: **$N$ and $S$ must have the same parity.**

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to count the number of $1$s.
- **Space Complexity**: $O(1)$, as we only store the count of $1$s and the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary array B of length N.
 * B_i = 1 if the frequency of element i in array A is odd.
 * B_i = 0 if the frequency of element i in array A is even.
 * 
 * Let f_i be the frequency of element i in array A.
 * The sum of frequencies must equal the total number of elements in A, which is N.
 * sum_{i=1}^N f_i = N
 * 
 * We know that f_i % 2 = B_i.
 * Therefore, f_i = 2 * k_i + B_i, where k_i >= 0.
 * Substituting this into the sum:
 * sum_{i=1}^N (2 * k_i + B_i) = N
 * 2 * sum_{i=1}^N k_i + sum_{i=1}^N B_i = N
 * 
 * Let S = sum_{i=1}^N B_i be the number of 1s in array B.
 * 2 * (sum k_i) = N - S
 * 
 * For a valid array A to exist, we need:
 * 1. N - S must be even (i.e., N and S must have the same parity).
 * 2. Since k_i >= 0, we need sum k_i >= 0, which implies N - S >= 0, or S <= N.
 *    Since S is the count of 1s in an array of length N, S <= N is always true.
 * 
 * Thus, the condition simplifies to: (N - S) % 2 == 0.
 * This is equivalent to saying N % 2 == S % 2.
 */

void solve() {
    int N;
    cin >> N;
    int S = 0;
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        if (b == 1) {
            S++;
        }
    }

    // Check if N and S have the same parity
    if ((N % 2) == (S % 2)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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