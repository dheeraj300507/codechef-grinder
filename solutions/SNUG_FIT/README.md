# [School of Geometry (SNUG_FIT)](https://www.codechef.com/problems/SNUG_FIT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two arrays $A$ and $B$ of size $N$, we need to pair each element $A_i$ with exactly one element $B_j$ such that every element is used exactly once. The goal is to maximize the sum of the diameters of the largest inscribed circles for each pair. The diameter of a circle inscribed in a rectangle of dimensions $A_i \times B_j$ is given by $\min(A_i, B_j)$. We must find a permutation $P$ of indices that maximizes $\sum_{i=1}^{N} \min(A_i, B_{P_i})$.

## Intuition & Mathematical Observation
To maximize the sum of the minimums of paired elements, we should employ a **greedy strategy**. 

1. **Sorting**: If we sort both arrays $A$ and $B$ in non-decreasing order, we align the smallest elements of $A$ with the smallest elements of $B$, and the largest with the largest.
2. **Greedy Logic**: By pairing the $i$-th smallest element of $A$ with the $i$-th smallest element of $B$, we ensure that we are not "wasting" large values by pairing them with very small values (which would result in the small value being the minimum). This approach effectively pairs elements of similar magnitudes, which maximizes the sum of their minimums.
3. **Data Types**: Since $A_i, B_i \le 10^9$ and $N \le 10^4$, the total sum can reach $10^{13}$, which exceeds the capacity of a 32-bit integer. Therefore, we must use `long long` to store the result.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting of arrays $A$ and $B$. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the input arrays $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a rectangle with dimensions A_i x B_j, the diameter of the largest 
 * inscribed circle is min(A_i, B_j).
 * We want to maximize the sum of min(A_i, B_{P_i}) for all i=1 to N,
 * where P is a permutation of 1 to N.
 * 
 * By the Rearrangement Inequality (or simply greedy logic), to maximize the 
 * sum of minimums of pairs, we should sort both arrays A and B in non-decreasing 
 * order and pair them up: A_sorted[i] with B_sorted[i].
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    // Sort both arrays to apply the greedy strategy
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        // The diameter of the inscribed circle is min(A[i], B[i])
        total_sum += min(A[i], B[i]);
    }
    
    cout << total_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```