# [Retrieve the Array (ARRAYRET)](https://www.codechef.com/problems/ARRAYRET)

- **Difficulty Rating**: 1193
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $B$ of length $N$, where each element $B_i$ is defined as the sum of the prefix sum $f(i)$ and the suffix sum $g(i)$ of an unknown array $A$. Specifically:
- $f(i) = A_1 + A_2 + \dots + A_i$
- $g(i) = A_i + A_{i+1} + \dots + A_N$
- $B_i = f(i) + g(i)$

The goal is to reconstruct the original array $A$ given the array $B$.

## Intuition & Mathematical Observation
By expanding the definition of $B_i$:
$B_i = (A_1 + \dots + A_i) + (A_i + \dots + A_N)$

Notice that the sum of all elements in $A$ is $S = \sum_{j=1}^{N} A_j$. We can rewrite the expression for $B_i$ as:
$B_i = (A_1 + \dots + A_N) + A_i$
$B_i = S + A_i$

To find $S$, we sum all elements of $B$:
$\sum_{i=1}^{N} B_i = \sum_{i=1}^{N} (S + A_i)$
$\sum_{i=1}^{N} B_i = N \cdot S + \sum_{i=1}^{N} A_i$
$\sum_{i=1}^{N} B_i = N \cdot S + S = S(N + 1)$

Thus, we can calculate the total sum $S$ of the original array $A$ using:
$S = \frac{\sum B_i}{N + 1}$

Once $S$ is known, each element of the original array is simply:
$A_i = B_i - S$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array $B$ once to calculate the sum and once to reconstruct $A$.
- **Space Complexity**: $O(N)$ to store the input array $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(i) = A_1 + A_2 + ... + A_i
 * g(i) = A_i + A_{i+1} + ... + A_N
 * B_i = f(i) + g(i) = (A_1 + ... + A_i) + (A_i + ... + A_N)
 * B_i = (A_1 + ... + A_N) + A_i
 * Let S = A_1 + A_2 + ... + A_N.
 * Then B_i = S + A_i.
 * 
 * Summing all B_i:
 * sum(B) = sum(S + A_i) = N * S + sum(A_i)
 * Since sum(A_i) = S, we have:
 * sum(B) = N * S + S = S * (N + 1)
 * Therefore, S = sum(B) / (N + 1).
 * 
 * Once S is found, A_i = B_i - S.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> B(N);
    long long sum_B = 0;
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        sum_B += B[i];
    }

    // Calculate the total sum S of the original array A
    long long S = sum_B / (N + 1);
    
    // Reconstruct and print array A
    for (int i = 0; i < N; ++i) {
        cout << (B[i] - S) << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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