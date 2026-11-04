# [Asymmetric Swaps (ARRSWAP)](https://www.codechef.com/problems/ARRSWAP)

- **Difficulty Rating**: 1230
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two arrays $A$ and $B$, both of size $N$, we are allowed to perform any number of swaps between elements of $A$ and $B$. After performing these swaps, we want to minimize the difference between the maximum and minimum elements of array $A$ (i.e., $\max(A) - \min(A)$).

## Intuition & Mathematical Observation
1. **Combined Pool**: Since we can swap any element from $A$ with any element from $B$, we effectively have a pool of $2N$ elements. After all swaps, array $A$ will simply consist of some subset of size $N$ chosen from these $2N$ elements.
2. **Sorting Strategy**: To minimize the range ($\max - \min$) of a subset of size $N$, we should pick elements that are as close to each other as possible. If we sort the combined $2N$ elements in non-decreasing order, any optimal subset of size $N$ must consist of a **contiguous subarray** of length $N$ from the sorted list.
3. **Sliding Window**: Let the sorted combined array be $C$. We need to evaluate the difference $C[i+N-1] - C[i]$ for all possible starting positions $i$ (where $0 \le i \le N$). The minimum of these values will be our answer.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan to find the minimum difference takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the combined array of $2N$ elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two arrays A and B of size N. We can swap any element of A with any element of B.
 * Effectively, this means we can choose any subset of size N from the combined 2N elements
 * to form the new array A.
 * 
 * To minimize (max(A) - min(A)), we should sort the combined 2N elements.
 * Let the sorted combined array be C. Any subarray of length N in C, i.e.,
 * C[i], C[i+1], ..., C[i+N-1] for 0 <= i <= N, represents a possible set of 
 * elements for array A.
 * 
 * The range of this subset is C[i+N-1] - C[i].
 * We need to find the minimum value of (C[i+N-1] - C[i]) for all 0 <= i <= N.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> combined(2 * N);
    for (int i = 0; i < N; ++i) {
        cin >> combined[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> combined[i + N];
    }

    // Sort the combined pool of 2N elements
    sort(combined.begin(), combined.end());

    long long min_diff = -1;

    // We look at all windows of size N in the sorted combined array
    // The possible windows start at index i and end at index i + N - 1
    // i ranges from 0 to N
    for (int i = 0; i <= N; ++i) {
        long long current_diff = combined[i + N - 1] - combined[i];
        if (min_diff == -1 || current_diff < min_diff) {
            min_diff = current_diff;
        }
    }

    cout << min_diff << "\n";
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