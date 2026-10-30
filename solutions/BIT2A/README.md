# [A - Books (BIT2A)](https://www.codechef.com/problems/BIT2A)

- **Difficulty Rating**: 1175
- **Solved in**: 3 attempt(s)

## Problem Summary
Given a sorted array $A$ of $N$ integers, for each element $A[i]$, we need to determine how many elements in the array are strictly greater than $A[i]$. The output should be a sequence of $N$ integers corresponding to these counts for each index.

## Intuition & Mathematical Observation
Since the input array is already sorted in non-decreasing order, all elements strictly greater than $A[i]$ must appear after the last occurrence of $A[i]$. 

Instead of iterating through the array for every element (which would be $O(N^2)$), we can leverage the sorted property:
1. For any element $A[i]$, the first element strictly greater than it can be found using binary search.
2. In C++, the `std::upper_bound` function efficiently finds the first element that is strictly greater than a given value in $O(\log N)$ time.
3. Once we have the iterator to this element, the number of elements greater than $A[i]$ is simply the distance from that iterator to the end of the vector.

*Note: While $N$ is small ($N \le 100$) and an $O(N^2)$ approach would pass, using `upper_bound` is a cleaner and more scalable approach.*

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of books. The `upper_bound` operation takes $O(\log N)$ and we perform it $N$ times per test case.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Given a sorted array A, for each A[i], we need the count of elements > A[i].
 * Since the array is sorted, all elements strictly greater than A[i] will 
 * appear after the last occurrence of A[i].
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // Find the first element strictly greater than A[i]
        // upper_bound returns an iterator to the first element > A[i]
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        
        // The number of elements strictly greater is the distance from 'it' to the end
        int count = (int)distance(it, A.end());
        
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
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