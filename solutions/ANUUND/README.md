# [Ups and Downs (ANUUND)](https://www.codechef.com/problems/ANUUND)

- **Difficulty Rating**: 1198
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to rearrange the elements such that they satisfy the "up-down" property:
$A[0] \le A[1] \ge A[2] \le A[3] \ge A[4] \dots$
In other words, the elements at odd indices must be greater than or equal to their immediate neighbors (if they exist).

## Intuition & Mathematical Observation
The key to solving this problem efficiently is to start with a sorted version of the array. Let the sorted array be $S$. 

1. **Sorting**: By sorting the array, we ensure that $S[0] \le S[1] \le S[2] \le \dots \le S[N-1]$.
2. **The Pattern**: We want $A[0] \le A[1]$, $A[1] \ge A[2]$, $A[2] \le A[3]$, and so on.
3. **Swapping Strategy**: If we iterate through the sorted array and swap every adjacent pair starting from index 1 (i.e., swap $S[1]$ with $S[2]$, $S[3]$ with $S[4]$, etc.), we create local peaks at the odd indices.
   - After sorting: $S[0], S[1], S[2], S[3], S[4] \dots$
   - After swapping pairs $(S[1], S[2]), (S[3], S[4]), \dots$:
     The array becomes $S[0], S[2], S[1], S[4], S[3] \dots$
   - **Verification**:
     - $A[0] \le A[1]$ becomes $S[0] \le S[2]$ (True, since sorted)
     - $A[1] \ge A[2]$ becomes $S[2] \ge S[1]$ (True, since sorted)
     - $A[2] \le A[3]$ becomes $S[1] \le S[4]$ (True, since $S[1] \le S[2] \le S[4]$)
     - $A[3] \ge A[4]$ becomes $S[4] \ge S[3]$ (True, since sorted)

This greedy approach ensures the condition is met for all $i$ by leveraging the properties of the sorted array.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan to perform swaps takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to satisfy: A[0] <= A[1] >= A[2] <= A[3] >= A[4] ...
 * 
 * Strategy:
 * 1. Sort the array in non-decreasing order.
 * 2. Iterate from i = 1 to N-2 with a step of 2.
 * 3. Swap A[i] and A[i+1].
 * 
 * This ensures that every element at an odd index is greater than or equal 
 * to its neighbors, satisfying the alternating condition.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Step 1: Sort the array
    sort(a.begin(), a.end());
    
    // Step 2: Swap adjacent pairs starting from index 1
    for (int i = 1; i + 1 < n; i += 2) {
        swap(a[i], a[i + 1]);
    }
    
    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
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