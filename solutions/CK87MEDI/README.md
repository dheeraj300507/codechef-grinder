# [Chef and Employment Test (CK87MEDI)](https://www.codechef.com/problems/CK87MEDI)

- **Difficulty Rating**: 1142
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we are allowed to add $K$ additional integers to the array. The goal is to maximize the median of the resulting array of size $M = N + K$. The median of an array of size $M$ (where $M$ is odd) is defined as the element at index $\lfloor M/2 \rfloor$ in the sorted version of the array (0-indexed).

## Intuition & Mathematical Observation
1. **Total Size**: The final array will have $N + K$ elements. The median will be located at index `target = (N + K) / 2` after sorting.
2. **Maximizing the Median**: To make the median as large as possible, we should choose the $K$ additional elements to be as large as possible (e.g., equal to the maximum value currently in the array).
3. **Sorted Structure**: If we sort the original array $A$ in non-decreasing order, adding $K$ very large elements effectively appends them to the end of the sorted array:
   $[A_0, A_1, \dots, A_{N-1}, \text{Large}, \dots, \text{Large}]$.
4. **Logic**:
   - If the `target` index is less than $N$, the median is simply the element at $A[\text{target}]$ in the original sorted array.
   - If the `target` index is $\ge N$, the median falls into the range of the $K$ elements we added. Since we can choose these to be as large as the maximum element of the original array, the median will be $A[N-1]$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, due to the sorting of the array $A$. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of N elements and we need to add K elements.
 * The total number of elements will be M = N + K.
 * The median of an array of size M (where M is odd) is the element at index (M/2) 
 * in the sorted array (0-indexed).
 * 
 * To maximize the median, we add K elements that are as large as the 
 * maximum element in the original array.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    // Sort the array to easily pick the median index
    sort(A.begin(), A.end());

    // The median index in the final array of size (N + K)
    int target_idx = (N + K) / 2;
    
    // If the target index is within the bounds of the original array,
    // the median is simply the element at that index.
    // Otherwise, the median is the largest element of the original array.
    if (target_idx < N) {
        cout << A[target_idx] << "\n";
    } else {
        cout << A[N - 1] << "\n";
    }
}

int main() {
    // Optimize I/O operations
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