# [Streak Star (STKSTR)](https://www.codechef.com/problems/STKSTR)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers and a multiplier $X$, we are allowed to multiply exactly one element $A[i]$ by $X$. The goal is to maximize the length of the longest non-decreasing subarray after performing this operation exactly once.

## Intuition & Mathematical Observation
The constraints on $N$ are relatively small (the sum of $N$ over all test cases is $\le 1000$). This allows for a brute-force approach:

1.  **Brute Force Strategy**: Since we only need to modify one element, we can iterate through every index $i$ from $0$ to $N-1$. For each index, we temporarily update $A[i] = A[i] \times X$, calculate the length of the longest non-decreasing subarray, and then revert the change (backtrack).
2.  **Streak Calculation**: To calculate the longest non-decreasing subarray, we perform a single linear scan ($O(N)$) through the array, keeping track of the current streak length and updating the global maximum whenever the non-decreasing condition ($A[i] \ge A[i-1]$) is broken.
3.  **Efficiency**: By checking every possible modification, we ensure we find the global optimum. With $N \le 1000$, an $O(N^2)$ approach performs roughly $10^6$ operations, which comfortably fits within the standard 1-second time limit.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, where $N$ is the number of elements in the array. We perform $N$ modifications, and for each, we traverse the array in $O(N)$ time.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of length N and a multiplier X.
 * We can multiply exactly one element A[i] by X.
 * We want to maximize the length of the longest non-decreasing subarray.
 * 
 * Since N is small (sum of N <= 1000), we can iterate through every possible 
 * index i (0 to N-1) where we apply the operation A[i] *= X.
 * For each modified array, we calculate the streak value in O(N).
 * Total complexity: O(N^2), which is well within the limits (10^6 operations).
 */

int get_streak(const vector<long long>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    int max_streak = 1;
    int current_streak = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1]) {
            current_streak++;
        } else {
            max_streak = max(max_streak, current_streak);
            current_streak = 1;
        }
    }
    max_streak = max(max_streak, current_streak);
    return max_streak;
}

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Case 1: No operation performed (or initial state)
    int max_val = get_streak(A);

    // Case 2: Try modifying each index i
    for (int i = 0; i < N; ++i) {
        long long original = A[i];
        A[i] *= X;
        max_val = max(max_val, get_streak(A));
        A[i] = original; // backtrack
    }

    cout << max_val << "\n";
}

int main() {
    // Fast I/O
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