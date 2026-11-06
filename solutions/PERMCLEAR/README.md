# [Permutation Clear (PERMCLEAR)](https://www.codechef.com/problems/PERMCLEAR)

- **Difficulty Rating**: 1308
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a permutation $A$ of length $N$ containing elements from $1$ to $N$, and a set $B$ containing $K$ distinct integers that are also present in $A$, the task is to remove all elements of $B$ from $A$ while preserving the relative order of the remaining elements.

## Intuition & Mathematical Observation
The problem requires filtering an array based on a set of values. Since the values in $A$ are bounded by $N$ (a permutation of $1$ to $N$), we can use a **Boolean Lookup Table** (or a frequency array) to achieve $O(1)$ lookup time for elements in $B$.

1.  **Marking**: Create a boolean array `to_remove` of size $N+1$. Iterate through the input set $B$ and set `to_remove[x] = true` for every $x \in B$.
2.  **Filtering**: Iterate through the original array $A$ from index $0$ to $N-1$. If `to_remove[A[i]]` is `false`, it means the element should be kept.
3.  **Output**: Print the kept elements in the order they appear in $A$.

This approach is optimal because it avoids nested loops (which would result in $O(N \cdot K)$ complexity) and utilizes the constraints of the problem effectively.

## Complexity Analysis
- **Time Complexity**: $O(N + K)$ per test case. We iterate through the array $A$ once ($N$) and the set $B$ once ($K$). Given the sum of $N$ over all test cases is $2 \cdot 10^5$, this comfortably fits within the time limit.
- **Space Complexity**: $O(N)$ to store the input array $A$ and the boolean lookup table `to_remove`.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a permutation A of length N and a set of K numbers B.
 * We need to remove all elements present in B from A while maintaining the relative order.
 * 
 * Optimal Approach:
 * 1. Use a boolean array to mark all elements present in B.
 *    Since 1 <= B_i <= N, a boolean array of size N+1 is efficient (O(1) lookup).
 * 2. Iterate through the original array A.
 * 3. If the current element A[i] is not marked in the boolean array, print it.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int K;
    cin >> K;
    
    // Using a boolean vector to keep track of elements to be removed.
    // Size N+1 because elements are 1-indexed up to N.
    vector<bool> to_remove(N + 1, false);
    for (int i = 0; i < K; ++i) {
        int b;
        cin >> b;
        to_remove[b] = true;
    }
    
    bool first = true;
    for (int i = 0; i < N; ++i) {
        if (!to_remove[A[i]]) {
            if (!first) {
                cout << " ";
            }
            cout << A[i];
            first = false;
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O setup
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