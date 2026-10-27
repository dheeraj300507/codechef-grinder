# [Convert to permutation (PERMUTATION)](https://www.codechef.com/problems/PERMUTATION)

- **Difficulty Rating**: 1197
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to transform it into a permutation of $\{1, 2, \dots, N\}$. The only allowed operation is to increment any element by 1. We need to find the minimum number of operations required to achieve this, or determine if it is impossible.

## Intuition & Mathematical Observation
1. **Sorting is Key**: To minimize the total number of increments, we should map the smallest elements in the array to the smallest target values ($1, 2, \dots, N$). Sorting the array $A$ in non-decreasing order allows us to greedily assign the $i$-th smallest element to the target value $i+1$.
2. **Feasibility Check**: Since we can only **increment** values, an element $A[i]$ can only reach a target value $T$ if $A[i] \le T$. If after sorting, any $A[i] > (i+1)$, it is impossible to transform the array into a permutation, and we should output `-1`.
3. **Calculating Cost**: If the condition $A[i] \le (i+1)$ holds for all $i$, the cost to transform $A[i]$ to $(i+1)$ is simply $(i+1) - A[i]$. The total cost is the sum of these differences.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the size of the array. The sorting step dominates the complexity per test case. Given $N \le 1000$ and $T \le 500$, this approach comfortably fits within the time limits.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to transform array A into a permutation of {1, 2, ..., N} using only increments.
 * 1. Sort the array A.
 * 2. The smallest element must eventually become 1, the second smallest 2, ..., the N-th smallest N.
 * 3. If any element A[i] is already greater than its target (i + 1), it's impossible.
 * 4. Otherwise, the cost is the sum of (target - A[i]).
 * 
 * Complexity: O(T * N log N), which is efficient enough for N=1000, T=500.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to match the smallest elements to the smallest targets
    sort(A.begin(), A.end());

    long long operations = 0;
    for (int i = 0; i < N; ++i) {
        int target = i + 1;
        
        // If the current element is already greater than the target,
        // we cannot decrease it to reach the target.
        if (A[i] > target) {
            cout << -1 << "\n";
            return;
        }
        
        // Add the difference to operations
        operations += (long long)(target - A[i]);
    }

    cout << operations << "\n";
}

int main() {
    // Optimize standard I/O operations
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