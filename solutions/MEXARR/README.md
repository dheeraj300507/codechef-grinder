# [MEXimize the Array (MEXARR)](https://www.codechef.com/problems/MEXARR)

- **Difficulty Rating**: 1289
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we want to maximize the MEX (Minimum Excluded value) of the array. The maximum possible MEX for an array of size $N$ is $N$, which is achieved if the array contains all integers from $0$ to $N-1$. We are allowed to change any element $A[i]$ to any integer $X$ with a cost of $|A[i] - X|$. The goal is to find the minimum total cost required to transform the array $A$ such that it contains all integers from $0$ to $N-1$.

## Intuition & Mathematical Observation
1. **Target State**: To achieve a MEX of $N$, the array must be a permutation of the set $\{0, 1, 2, \dots, N-1\}$.
2. **Minimizing Cost**: We have an input array $A$ and a target set $T = \{0, 1, 2, \dots, N-1\}$. To minimize the sum of absolute differences $\sum |A[i] - T[i]|$, a well-known mathematical property states that both arrays should be sorted.
3. **Greedy Strategy**: 
   - Sort the input array $A$ in non-decreasing order.
   - Sort the target set $T$ (which is already $0, 1, \dots, N-1$).
   - The minimum cost is obtained by calculating $\sum_{i=0}^{N-1} |A[i] - i|$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting of the input array. The subsequent linear scan takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the MEX of an array of length N, the best we can achieve is a MEX of N.
 * This happens if the array contains all integers from 0 to N-1.
 * 
 * Strategy:
 * 1. Sort the input array A in non-decreasing order.
 * 2. To minimize the total operations to transform A into the set {0, 1, 2, ..., N-1},
 *    we should map the smallest element of A to 0, the second smallest to 1, and so on.
 *    This is because if we have sorted arrays A and B, the sum of |A[i] - B[i]| 
 *    is minimized when both are sorted.
 * 3. The target array is {0, 1, 2, ..., N-1}.
 * 4. The total operations required will be the sum of |A[i] - i| for i from 0 to N-1.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to greedily match the smallest elements to 0, 1, ..., N-1
    sort(A.begin(), A.end());
    
    long long operations = 0;
    for (int i = 0; i < N; ++i) {
        // We want to transform A[i] to i
        operations += abs(A[i] - i);
    }
    
    cout << operations << "\n";
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