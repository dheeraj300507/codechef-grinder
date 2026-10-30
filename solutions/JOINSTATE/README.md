# [Join States (JOINSTATE)](https://www.codechef.com/problems/JOINSTATE)

- **Difficulty Rating**: 1043
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ of $N$ integers representing the populations of various regions and a threshold $M$. We want to partition the array into the maximum number of contiguous subarrays such that the sum of each subarray is at least $M$. Any elements remaining at the end that do not form a sum of at least $M$ are merged into the last valid subarray.

## Intuition & Mathematical Observation
To maximize the number of subarrays (states), we should aim to make each subarray as small as possible while still satisfying the condition $\text{sum} \ge M$. 

This is a classic **Greedy** approach:
1. Iterate through the array while maintaining a `current_sum`.
2. Add the current element to `current_sum`.
3. As soon as `current_sum` reaches or exceeds $M$, we have successfully formed a valid state. We increment our counter and reset `current_sum` to $0$ to begin forming the next state.
4. By "closing" the state immediately upon reaching $M$, we ensure that we leave as many remaining elements as possible to potentially form subsequent states, thereby maximizing the total count.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We perform a single pass through the array.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process elements on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and a threshold M.
 * We need to partition the array into the maximum number of contiguous subarrays
 * such that the sum of each subarray is at least M.
 * 
 * Greedy Strategy:
 * Iterate through the array and maintain a running sum.
 * As soon as the running sum reaches or exceeds M, we have formed a valid state.
 * We increment our count of states and reset the running sum to 0.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int state_count = 0;
    long long current_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        // As soon as we hit the threshold, count it and reset
        if (current_sum >= M) {
            state_count++;
            current_sum = 0;
        }
    }
    
    cout << state_count << "\n";
}

int main() {
    // Fast I/O setup
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