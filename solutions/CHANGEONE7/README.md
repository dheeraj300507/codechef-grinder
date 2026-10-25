# [Change One (CHANGEONE7)](https://www.codechef.com/problems/CHANGEONE7)

- **Difficulty Rating**: 738
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, you are allowed to change exactly one element of the array to any integer of your choice. The goal is to minimize the difference between the maximum and minimum elements of the array (the range) after performing this operation.

## Intuition & Mathematical Observation
To minimize the range of an array, we want to bring the maximum and minimum values as close to each other as possible. 

1. **Sorting**: First, sort the array in non-decreasing order: $S_1, S_2, \dots, S_N$.
2. **The Range**: The current range is $S_N - S_1$.
3. **Strategy**: Since we can change only one element, we have two primary candidates to reduce the range:
   - **Remove the influence of the minimum**: Change $S_1$ to be equal to $S_2$. The new range becomes $S_N - S_2$.
   - **Remove the influence of the maximum**: Change $S_N$ to be equal to $S_{N-1}$. The new range becomes $S_{N-1} - S_1$.
4. **Edge Case**: If $N \le 2$, we can always make the two elements equal to each other, resulting in a range of $0$.
5. **Conclusion**: The optimal answer is $\min(S_N - S_2, S_{N-1} - S_1)$ for $N > 2$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent calculations are performed in $O(1)$ time.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We must change exactly one element to minimize (max(A) - min(A)).
 * 
 * Let the sorted array be S_1, S_2, ..., S_N.
 * The current range is S_N - S_1.
 * 
 * To minimize the range by changing one element:
 * 1. We can change the minimum element (S_1) to be equal to S_2. The new range becomes S_N - S_2.
 * 2. We can change the maximum element (S_N) to be equal to S_{N-1}. The new range becomes S_{N-1} - S_1.
 * 
 * Since we want the minimum of these two possibilities, the answer is min(S_N - S_2, S_{N-1} - S_1).
 * 
 * Special case: If N=2, we can always make the two elements equal, resulting in a range of 0.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N <= 2) {
        cout << 0 << "\n";
        return;
    }

    sort(A.begin(), A.end());

    // Option 1: Change the smallest element to match the second smallest
    int range1 = A[N - 1] - A[1];
    
    // Option 2: Change the largest element to match the second largest
    int range2 = A[N - 2] - A[0];

    cout << min(range1, range2) << "\n";
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