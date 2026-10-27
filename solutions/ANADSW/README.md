# [Anti Adjacent Swaps (ANADSW)](https://www.codechef.com/problems/ANADSW)

- **Difficulty Rating**: 1306
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ of size $N$. We are allowed to swap any two elements $A[i]$ and $A[j]$ if and only if $|i - j| > 1$. The goal is to determine if the array can be sorted in non-decreasing order using any number of these operations.

## Intuition & Mathematical Observation
The problem boils down to understanding the reachability of permutations under the given constraint:

1.  **Case $N = 1$**: The array is trivially sorted. Always **YES**.
2.  **Case $N = 2$**: The only possible swap is between indices 1 and 2. Since $|1 - 2| = 1$, no swaps are allowed. The array must already be sorted. **YES** if $A[0] \le A[1]$, else **NO**.
3.  **Case $N = 3$**: The only allowed swap is between index 0 and index 2 ($|0 - 2| = 2 > 1$). We can either keep the array as is or swap the first and last elements. We check if either the original array or the swapped array is sorted.
4.  **Case $N \ge 4$**: With four or more elements, the connectivity of the swap graph increases significantly. We can use an intermediate element to perform a 3-cycle or effectively swap adjacent elements by utilizing the extra space. It is a known result in permutation group theory that if you can swap elements at distance $\ge 2$, you can generate the entire symmetric group $S_N$ for $N \ge 4$. Thus, any array can be sorted. Always **YES**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a simple check for $N=3$ and constant time operations for other cases.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - N=1: Always sorted.
 * - N=2: Only sorted if A[0] <= A[1] (no swaps possible).
 * - N=3: Can swap A[0] and A[2]. Check if original or swapped is sorted.
 * - N>=4: Always possible to sort.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        // Check if original is sorted
        bool sorted = is_sorted(A.begin(), A.end());
        if (sorted) {
            cout << "YES" << "\n";
            return;
        }
        // Check after swapping A[0] and A[2]
        swap(A[0], A[2]);
        if (is_sorted(A.begin(), A.end())) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, it is always possible to sort the array.
        cout << "YES" << "\n";
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