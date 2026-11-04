# [Maximum Sum (MAXSUM77)](https://www.codechef.com/problems/MAXSUM77)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array $A$ of $N$ integers. You are allowed to perform exactly $K$ operations. In each operation, you must remove either the current first element or the current last element of the array. The goal is to maximize the sum of the remaining $N - K$ elements after all $K$ operations are completed.

## Intuition & Mathematical Observation
The key observation is that after performing $K$ operations, the elements remaining will always form a **contiguous subarray** of the original array with a length of exactly $M = N - K$.

If we remove $i$ elements from the left side, we must remove $K - i$ elements from the right side to satisfy the total of $K$ removals. This leaves us with the subarray starting at index $i$ and ending at index $i + M - 1$. Since $0 \le i \le K$, we simply need to iterate through all possible starting positions $i$ for a subarray of length $M$ and calculate the sum of each. The maximum of these sums will be our answer.

Using a **prefix sum array** allows us to calculate the sum of any subarray in $O(1)$ time, making the overall approach very efficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We iterate through the array once to build the prefix sum array and once more to find the maximum subarray sum.
- **Space Complexity**: $O(N)$ to store the input array and the prefix sum array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of N elements and we perform K removals.
 * Each removal must be either the current first or current last element.
 * After K removals, we are left with N - K elements.
 * 
 * If we remove K elements in total, we are essentially choosing a contiguous 
 * subarray of length (N - K).
 * Let M = N - K be the number of elements remaining.
 * The remaining elements will form a contiguous subarray A[i...i+M-1] 
 * for some 0 <= i <= K.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int remaining_len = N - K;
    
    // Calculate prefix sums to compute subarray sums in O(1)
    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }

    // Initialize max_sum with a very small value
    long long max_sum = -2e18; 

    // Iterate over all possible starting positions of the remaining subarray
    // The subarray starts at index i and has length remaining_len.
    // Valid i range: 0 to K
    for (int i = 0; i <= K; ++i) {
        long long current_sum = prefix_sum[i + remaining_len] - prefix_sum[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    cout << max_sum << "\n";
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