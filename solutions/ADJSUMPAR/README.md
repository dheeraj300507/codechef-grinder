# [Adjacent Sum Parity (ADJSUMPAR)](https://www.codechef.com/problems/ADJSUMPAR)

- **Difficulty Rating**: 1013
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $B$ of length $N$ consisting of 0s and 1s, determine if there exists a binary array $A$ of length $N$ such that:
- $B_i = (A_i + A_{i+1}) \pmod 2$ for $1 \le i < N$
- $B_N = (A_N + A_1) \pmod 2$

## Intuition & Mathematical Observation
The problem asks if we can reconstruct a binary array $A$ from the given parity sums $B$. Let's analyze the sum of all elements in $B$:

$$\sum_{i=1}^{N} B_i = (A_1 + A_2) + (A_2 + A_3) + \dots + (A_{N-1} + A_N) + (A_N + A_1) \pmod 2$$

Notice that in this summation, every element $A_i$ appears exactly twice:
$$\sum_{i=1}^{N} B_i = 2 \cdot \sum_{i=1}^{N} A_i \pmod 2$$

Since $2 \cdot (\text{any integer})$ is always even, the sum of all elements in $B$ must be even (i.e., $0 \pmod 2$). Therefore, a necessary condition for a valid array $A$ to exist is that the number of 1s in array $B$ must be even.

If the number of 1s in $B$ is even, we can always construct $A$ by setting $A_1 = 0$ (or $1$) and iteratively determining the remaining elements:
1. $A_2 = (B_1 - A_1) \pmod 2$
2. $A_3 = (B_2 - A_2) \pmod 2$
3. ... and so on.

The final condition $B_N = (A_N + A_1) \pmod 2$ will be satisfied if and only if the total parity of $B$ is even.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array $B$ exactly once to count the number of 1s.
- **Space Complexity**: $O(1)$, as we only store the count of 1s and do not need to store the entire array $B$ in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The sum of all elements in B is 2 * Sum(A) (mod 2).
 * Since 2 * X is always even, the sum of elements in B must be even.
 * If the count of 1s in B is even, a valid A exists.
 */

void solve() {
    int N;
    cin >> N;
    int ones_count = 0;
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        if (b == 1) {
            ones_count++;
        }
    }

    // If the number of 1s is even, the condition is satisfied.
    if (ones_count % 2 == 0) {
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