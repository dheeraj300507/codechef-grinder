# [K Median (KMED)](https://www.codechef.com/problems/KMED)

- **Difficulty Rating**: 1110
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we are required to delete exactly $K$ elements, leaving $M = N - K$ elements. The median of the remaining elements is defined as the $\lceil M/2 \rceil$-th smallest element. We need to find all possible values that can serve as the median of the remaining array after choosing which $K$ elements to remove.

## Intuition & Mathematical Observation
1. **Sorting**: First, sort the array $A$ in non-decreasing order. Let the sorted array be $S$.
2. **Median Index**: After removing $K$ elements, we are left with $M = N - K$ elements. The median is the element at the 1-based index $m_{idx} = \lceil M/2 \rceil$ in the sorted version of the remaining elements.
3. **Selection Logic**: If we designate $S[i]$ as the median of the remaining $M$ elements:
   - We must be able to select $(m_{idx} - 1)$ elements from the elements smaller than or equal to $S[i]$ (indices $0$ to $i-1$). This is possible if $i \ge (m_{idx} - 1)$.
   - We must be able to select $(M - m_{idx})$ elements from the elements larger than or equal to $S[i]$ (indices $i+1$ to $N-1$). This is possible if $(N - 1 - i) \ge (M - m_{idx})$.
4. **Implementation**: Iterate through every element $S[i]$ in the sorted array. If the conditions above are met, $S[i]$ is a valid median. We use a `std::set` to store these values to ensure they are printed in sorted order and to handle duplicate values correctly.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent iteration and set insertion take $O(N \log N)$ or $O(N)$ depending on the number of unique possible medians. Given $N \le 100$, this is highly efficient.
- **Space Complexity**: $O(N)$ to store the array and the set of possible medians.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * After sorting the array, we check each element to see if it can be the median.
 * For an element at index i (0-indexed) to be the median of M elements:
 * 1. We need (m_idx - 1) elements to its left.
 * 2. We need (M - m_idx) elements to its right.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int M = N - K;
    int m_idx = (M + 1) / 2; // 1-based index of median
    
    set<long long> possible_medians;
    for (int i = 0; i < N; ++i) {
        // Check if we can pick enough elements from left and right
        if (i >= (m_idx - 1) && (N - 1 - i) >= (M - m_idx)) {
            possible_medians.insert(A[i]);
        }
    }

    bool first = true;
    for (long long val : possible_medians) {
        if (!first) cout << " ";
        cout << val;
        first = false;
    }
    cout << "\n";
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