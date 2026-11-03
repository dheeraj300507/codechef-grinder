# [Make A and B equal (MAKEABEQUAL)](https://www.codechef.com/problems/MAKEABEQUAL)

- **Difficulty Rating**: 1264
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two arrays $A$ and $B$ of length $N$, we want to make them identical. In one operation, we can choose an index $i$ and increment $A[i]$ by 1, and choose an index $j$ and increment $B[j]$ by 1. We want to find the minimum number of operations required to make $A$ equal to $B$, or determine if it is impossible.

## Intuition & Mathematical Observation
Let $x_i$ be the total amount added to $A[i]$ and $y_j$ be the total amount added to $B[j]$. Since we perform the same number of operations $K$ on both arrays, the total sum of increments must be equal:
$$\sum_{i=0}^{N-1} x_i = \sum_{j=0}^{N-1} y_j = K$$

For the arrays to be equal at the end, the final value at each index $i$ must be $V_i = A[i] + x_i = B[i] + y_i$. This rearranges to:
$$x_i - y_i = B[i] - A[i]$$

Let $diff_i = B[i] - A[i]$.
- If $B[i] > A[i]$, we must add at least $B[i] - A[i]$ to $A[i]$ to make it reach $B[i]$.
- If $A[i] > B[i]$, we must add at least $A[i] - B[i]$ to $B[i]$ to make it reach $A[i]$.

Let `pos_diff` be the sum of all positive differences ($B[i] - A[i]$) and `neg_diff` be the sum of all absolute values of negative differences ($A[i] - B[i]$).
1. If `pos_diff == neg_diff`, it means the total "deficit" in $A$ is exactly balanced by the "surplus" in $A$ relative to $B$. We can satisfy the condition in exactly `pos_diff` operations.
2. If `pos_diff != neg_diff`, it is impossible to make the arrays equal because the total number of increments applied to $A$ must equal the total number of increments applied to $B$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the arrays once to calculate the differences.
- **Space Complexity**: $O(N)$ to store the input arrays, though this could be optimized to $O(1)$ by processing elements on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two arrays A and B of length N.
 * In one operation, we pick A[i] and B[j] and increment both by 1.
 * The total increments applied to A must equal the total increments applied to B.
 * 
 * Let pos_diff = sum of (B[i] - A[i]) for all i where B[i] > A[i].
 * Let neg_diff = sum of (A[i] - B[i]) for all i where A[i] > B[i].
 * 
 * If pos_diff == neg_diff, then K = pos_diff is the minimum operations.
 * Otherwise, it is impossible.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long pos_diff = 0; // Sum of (B[i] - A[i]) where B[i] > A[i]
    long long neg_diff = 0; // Sum of (A[i] - B[i]) where A[i] > B[i]

    for (int i = 0; i < N; ++i) {
        if (B[i] > A[i]) {
            pos_diff += (B[i] - A[i]);
        } else if (A[i] > B[i]) {
            neg_diff += (A[i] - B[i]);
        }
    }

    if (pos_diff == neg_diff) {
        cout << pos_diff << "\n";
    } else {
        cout << -1 << "\n";
    }
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