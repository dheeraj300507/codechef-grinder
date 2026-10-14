# [Little Chef and Sums (CHEFSUM)](https://www.codechef.com/problems/CHEFSUM)

- **Difficulty Rating**: 1252
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ positive integers, we define two functions for each index $i$ ($1 \le i \le N$):
1. `prefixSum(i)` = $\sum_{j=1}^{i} A[j]$
2. `suffixSum(i)` = $\sum_{j=i}^{N} A[j]$

The goal is to find the index $i$ that minimizes the value of `prefixSum(i) + suffixSum(i)`. If there are multiple such indices, choose the smallest one.

## Intuition & Mathematical Observation
Let $S$ be the total sum of the array, i.e., $S = \sum_{j=1}^{N} A[j]$.
Expanding the expression:
$$\text{prefixSum}(i) + \text{suffixSum}(i) = \left( \sum_{j=1}^{i} A[j] \right) + \left( \sum_{j=i}^{N} A[j] \right)$$

Notice that the element $A[i]$ is included in both the prefix sum and the suffix sum. Therefore:
$$\text{prefixSum}(i) + \text{suffixSum}(i) = \left( \sum_{j=1}^{N} A[j] \right) + A[i] = S + A[i]$$

Since $S$ is a constant for the entire array, minimizing $S + A[i]$ is mathematically equivalent to minimizing $A[i]$. Thus, the problem reduces to finding the index of the smallest element in the array. If there are multiple occurrences of the minimum value, the smallest index is chosen by default if we iterate from $1$ to $N$ and only update the index when we find a value strictly smaller than the current minimum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to iterate through the array once to find the minimum element.
- **Space Complexity**: $O(1)$, as we process the input on the fly without needing to store the entire array in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * prefixSum(i) + suffixSum(i) = (A[1] + ... + A[N]) + A[i]
 * 
 * Since (A[1] + ... + A[N]) is a constant for a given array,
 * minimizing (prefixSum(i) + suffixSum(i)) is equivalent to minimizing A[i].
 * 
 * To find the minimum index i for which this value is minimum, we simply need
 * to find the index i (1-based) where A[i] is the smallest.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Initialize min_val with a value larger than any possible A[i] (max 10^5)
    int min_val = 200000; 
    int min_idx = -1;
    
    for (int i = 1; i <= N; ++i) {
        int val;
        cin >> val;
        // Update only if we find a strictly smaller value to keep the smallest index
        if (val < min_val) {
            min_val = val;
            min_idx = i;
        }
    }
    
    cout << min_idx << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```