# [Good Subsequence (GOODSUB7)](https://www.codechef.com/problems/GOODSUB7)

- **Difficulty Rating**: 899
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the length of the longest "good" subsequence. A subsequence is defined as "good" if the parity (even or odd) of every pair of adjacent elements in the subsequence is different. In other words, the subsequence must strictly alternate between odd and even numbers.

## Intuition & Mathematical Observation
To maximize the length of an alternating subsequence, we can use a **greedy approach**. 

1. We iterate through the array from left to right.
2. We keep track of the parity of the last element added to our "good" subsequence.
3. If the current element has a different parity than the last element added (or if it is the very first element we are picking), we include it in our subsequence.
4. By always picking the next available element that satisfies the alternating condition, we ensure that we don't miss any potential additions, resulting in the longest possible subsequence.

This works because picking an element of the required parity as early as possible never restricts our ability to pick future elements; it only increases our count.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform a single pass through the input array.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process elements on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A sequence is "good" if the parity of adjacent elements is different.
 * This means the sequence must alternate between odd and even numbers.
 * We greedily pick the first element, then look for the next element
 * with a different parity, and so on.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    int count = 0;
    int last_parity = -1; // -1 indicates no element has been picked yet

    for (int i = 0; i < N; ++i) {
        int current_parity = A[i] % 2;
        
        // If it's the first element or the parity is different from the last one
        if (last_parity == -1 || current_parity != last_parity) {
            count++;
            last_parity = current_parity;
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O for performance
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