# [Mirror Swap (MRSWAP)](https://www.codechef.com/problems/MRSWAP)

- **Difficulty Rating**: 667
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $2N$, we are allowed to perform a "mirror swap" operation. For any index $i$ (where $1 \le i \le N$), we can swap the element at position $i$ with the element at position $2N + 1 - i$. The goal is to maximize the sum of the elements in the first half of the array (indices $1$ to $N$) after performing any number of these swaps.

## Intuition & Mathematical Observation
The problem states that for each index $i$ in the first half ($1 \le i \le N$), we have a corresponding "mirror" index $2N + 1 - i$ in the second half. Since we can swap these two elements freely, we effectively have a pair of numbers $(A[i], A[2N + 1 - i])$ for each $i$. 

To maximize the sum of the first $N$ elements, we simply need to make an independent decision for each pair:
1. Compare the two elements in the pair.
2. Place the larger of the two elements into the first half.
3. Place the smaller of the two elements into the second half.

By choosing the maximum value for every pair, we guarantee the largest possible sum for the first half of the array.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the first $N$ elements of the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array of size $2N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (1-based indexing).
 * This means for each pair (A[i], A[2N + 1 - i]), we can choose which one 
 * goes into the first half (indices 1 to N) and which one goes into the 
 * second half (indices N+1 to 2N).
 * 
 * To maximize the sum of the first half, for each pair (A[i], A[2N + 1 - i]) 
 * where 1 <= i <= N, we should pick the maximum of the two values to be 
 * placed in the first half.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    // The pairs are (A[0], A[2N-1]), (A[1], A[2N-2]), ..., (A[N-1], A[N])
    for (int i = 0; i < N; ++i) {
        int left = A[i];
        int right = A[2 * N - 1 - i];
        max_sum += max(left, right);
    }

    cout << max_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```