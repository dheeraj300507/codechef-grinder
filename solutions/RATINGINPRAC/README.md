# [Difficulty Rating Order (RATINGINPRAC)](https://www.codechef.com/problems/RATINGINPRAC)

- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers representing the difficulty ratings of problems, determine if the ratings are sorted in non-decreasing order. That is, for every index $i$ from $0$ to $N-2$, the condition $A[i] \le A[i+1]$ must hold true.

## Intuition & Mathematical Observation
To verify if an array is sorted in non-decreasing order, we only need to perform a single linear scan. We compare each element with its immediate successor. If we encounter any pair where the current element is strictly greater than the next element ($A[i] > A[i+1]$), the array violates the non-decreasing condition, and we can immediately conclude the answer is "No". If we complete the loop without finding such a pair, the array is sorted, and the answer is "Yes".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array. Note that this could be optimized to $O(1)$ by storing only the previous element and comparing it with the current input, but $O(N)$ is well within the limits for this problem.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Difficulty Rating Order
 * The task is to check if an array of N integers is sorted in non-decreasing order.
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the input array.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    bool is_non_decreasing = true;
    for (int i = 0; i < N - 1; ++i) {
        // If current element is greater than the next, it's not non-decreasing
        if (A[i] > A[i + 1]) {
            is_non_decreasing = false;
            break;
        }
    }

    if (is_non_decreasing) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
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