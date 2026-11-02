# [How Many Maximums (HOWMANYMAX)](https://www.codechef.com/problems/HOWMANYMAX)

- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a sequence of $N$ numbers $A_1, A_2, \dots, A_N$, we are provided with a string $S$ of length $N-1$ representing the relationship between adjacent elements:
- $S[i] = '0'$ implies $A_{i+1} < A_{i+2}$
- $S[i] = '1'$ implies $A_{i+1} > A_{i+2}$

We need to determine the number of local maximums in the array. An element $A_i$ is a local maximum if it is greater than its immediate neighbors (if they exist).

## Intuition & Mathematical Observation
To identify the maximums, we analyze the conditions based on the string $S$:

1.  **First Element ($A_1$):** It is a maximum if $A_1 > A_2$. This corresponds to $S[0] == '1'$.
2.  **Last Element ($A_N$):** It is a maximum if $A_{N-1} < A_N$. This corresponds to $S[N-2] == '0'$.
3.  **Intermediate Elements ($A_i$ where $1 < i < N$):** An element is a maximum if it is a "peak," meaning $A_{i-1} < A_i$ and $A_i > A_{i+1}$. In terms of the string $S$, this occurs when $S[i-2] == '0'$ and $S[i-1] == '1'$.

By iterating through the string $S$ and checking these specific patterns, we can count the total number of local maximums efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single linear scan through the string $S$ of length $N-1$.
- **Space Complexity**: $O(N)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N-1 where S[i] = '0' means A[i+1] < A[i+2]
 * and S[i] = '1' means A[i+1] > A[i+2].
 * 
 * An index i (1-indexed) can be a maximum if:
 * 1. For i = 1: S[0] must be '1' (A[1] > A[2]).
 * 2. For i = N: S[N-2] must be '0' (A[N-1] < A[N]).
 * 3. For 1 < i < N: A[i] is a maximum if A[i-1] < A[i] and A[i] > A[i+1].
 *    In terms of S, this means S[i-2] == '0' and S[i-1] == '1'.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 2) {
        // For N=2, there is always exactly one maximum.
        cout << 1 << "\n";
        return;
    }

    int count = 0;

    // Check index 1
    if (S[0] == '1') {
        count++;
    }

    // Check indices 2 to N-1
    for (int i = 0; i < N - 2; ++i) {
        if (S[i] == '0' && S[i + 1] == '1') {
            count++;
        }
    }

    // Check index N
    if (S[N - 2] == '0') {
        count++;
    }

    cout << count << "\n";
}

int main() {
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