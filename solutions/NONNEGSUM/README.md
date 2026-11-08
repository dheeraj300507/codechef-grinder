# [Non-Negative Sum (NONNEGSUM)](https://www.codechef.com/problems/NONNEGSUM)

- **Difficulty Rating**: 944
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array of integers, find the size of the largest subsequence such that the sum of its elements is non-negative ($\ge 0$).

## Intuition & Mathematical Observation
To maximize the size of a subsequence with a non-negative sum, we follow these logical steps:

1.  **Check the Total Sum**: If the sum of all elements in the array is already $\ge 0$, the largest subsequence is the entire array itself (size $N$).
2.  **Handle Negative Sums**: If the total sum is negative, we must remove elements to increase the sum. To keep the subsequence as large as possible, we want to remove the **minimum number of elements**.
3.  **Greedy Strategy**: Removing a negative number increases the total sum. To reach a non-negative sum as quickly as possible (by removing the fewest elements), we should greedily remove the "most negative" numbers first (i.e., the smallest values like $-10, -9, \dots$).
4.  **Edge Case**: If we remove all negative numbers and the sum is still less than $0$ (which happens if the array contains only negative numbers or zeros that don't sum to $\ge 0$), the largest subsequence with a non-negative sum is an empty set (size $0$).

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting of negative numbers. The initial pass through the array is $O(N)$, and the subsequent removal loop is at most $O(N)$.
- **Space Complexity**: $O(N)$ to store the negative numbers in a separate vector.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * 1. Calculate the total sum of the array.
 * 2. If total_sum >= 0, the largest subsequence is the entire array (size N).
 * 3. If total_sum < 0, remove the most negative numbers one by one 
 *    until the sum becomes non-negative.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    long long total_sum = 0;
    vector<long long> negatives;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
        if (A[i] < 0) {
            negatives.push_back(A[i]);
        }
    }

    // If total sum is already non-negative, the whole array is the answer.
    if (total_sum >= 0) {
        cout << N << "\n";
        return;
    }

    // Sort negative numbers ascending (e.g., -10, -5, -2)
    // Removing the smallest (most negative) values increases the sum fastest.
    sort(negatives.begin(), negatives.end());

    int removed = 0;
    for (long long val : negatives) {
        total_sum -= val; // Removing a negative value increases the sum
        removed++;
        if (total_sum >= 0) {
            cout << N - removed << "\n";
            return;
        }
    }

    // If we removed all negative numbers and the sum is still < 0,
    // the only non-negative sum possible is 0 (empty subsequence).
    cout << 0 << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```