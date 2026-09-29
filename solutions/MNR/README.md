# [Range Minimize (MNR)](https://www.codechef.com/problems/MNR)

- **Difficulty Rating**: 949
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, you are allowed to remove at most two elements from the array. The goal is to minimize the difference between the maximum and minimum elements of the remaining array (the range).

## Intuition & Mathematical Observation
To minimize the range of an array, we want the remaining elements to be as close to each other as possible. Sorting the array is the most effective way to visualize the distribution of elements. Let the sorted array be $A[0], A[1], \dots, A[N-1]$.

When we remove two elements, we are essentially choosing a contiguous subarray of length $N-2$ from the sorted array. There are only three ways to remove two elements to minimize the range:
1. **Remove the two smallest elements:** The remaining range is $A[N-1] - A[2]$.
2. **Remove the two largest elements:** The remaining range is $A[N-3] - A[0]$.
3. **Remove one smallest and one largest element:** The remaining range is $A[N-2] - A[1]$.

If $N \le 3$, we can remove elements until only one or zero elements remain, resulting in a range of $0$. For $N > 3$, we simply calculate these three possibilities and take the minimum.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent calculations are $O(1)$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are allowed to delete at most two elements from an array of size N.
 * To minimize (max - min), we should sort the array first.
 * Let the sorted array be A[0], A[1], ..., A[N-1].
 * After deleting two elements, we have three optimal strategies to minimize the range:
 * 1. Delete the two smallest elements: The new range is A[N-1] - A[2].
 * 2. Delete the two largest elements: The new range is A[N-3] - A[0].
 * 3. Delete the smallest and the largest element: The new range is A[N-2] - A[1].
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // If N <= 3, we can remove elements until the range is 0
    if (N <= 3) {
        cout << 0 << "\n";
        return;
    }

    sort(A.begin(), A.end());

    // Option 1: Delete two smallest
    long long opt1 = A[N - 1] - A[2];
    // Option 2: Delete two largest
    long long opt2 = A[N - 3] - A[0];
    // Option 3: Delete one smallest and one largest
    long long opt3 = A[N - 2] - A[1];

    long long ans = min({opt1, opt2, opt3});
    cout << ans << "\n";
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