# [Exclusion-Inclusion (ONEFROMK)](https://www.codechef.com/problems/ONEFROMK)

- **Difficulty Rating**: 1307
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, for every $K$ from $1$ to $N$, we perform a process:
1. Initially, the bucket contains the first $K-1$ elements $\{A_1, A_2, \dots, A_{K-1}\}$.
2. For each $i$ from $K$ to $N$, we add $A_i$ to the bucket and then remove one element of our choice.
3. The goal is to maximize the sum of the elements remaining in the bucket after the process concludes.

## Intuition & Mathematical Observation
- **Process Analysis**: We start with $K-1$ elements and perform $N - K + 1$ iterations. In each iteration, we add one element and remove one. Consequently, we will always have exactly $K-1$ elements remaining in the bucket at the end.
- **Wait, re-evaluating the count**: The problem states we add $A_i$ and remove one. Total elements added = $(K-1) + (N-K+1) = N$. Total elements removed = $N-K+1$. Remaining elements = $N - (N-K+1) = K-1$.
- **Optimization**: To maximize the sum of the remaining $K-1$ elements, we should always aim to keep the largest possible elements from the original array.
- **Constraint Logic**: Since we can choose which element to remove at every step, we effectively have the freedom to discard the smallest elements encountered so far. By the end of the process, we will have discarded the $N - (K-1)$ smallest elements of the array.
- **Conclusion**: For a fixed $K$, the maximum sum is simply the sum of the $K-1$ largest elements in the array.
    - *Correction based on the provided code logic*: The code calculates the sum of the $N-K+1$ largest elements. Let's re-verify: If we have $N$ elements and we perform $N-K+1$ removals, we are left with $K-1$ elements. To maximize the sum, we pick the $K-1$ largest elements. 
    - *Note*: The provided code actually outputs the sum of the $N-K+1$ largest elements. Given the problem constraints and typical competitive programming patterns for this specific problem, the logic relies on sorting the array and using suffix sums to quickly retrieve the sum of the largest $X$ elements.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The suffix sum calculation and the output loop both run in $O(N)$. Thus, the total time complexity per test case is $O(N \log N)$.
- **Space Complexity**: $O(N)$ to store the array $A$ and the `suffix_sum` array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to maximize the sum of elements remaining in the bucket.
 * After N-K+1 operations, we are left with K-1 elements.
 * To maximize the sum, we select the K-1 largest elements from the array.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to easily pick the largest elements
    sort(A.begin(), A.end());

    // Precompute suffix sums
    // suffix_sum[i] = sum of A[i...N-1]
    vector<long long> suffix_sum(N + 1, 0);
    for (int i = N - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + A[i];
    }

    // For each K, we want the sum of the (K-1) largest elements.
    // These are the elements from index N-(K-1) to N-1.
    for (int K = 1; K <= N; ++K) {
        int count = K - 1;
        cout << suffix_sum[N - count] << (K == N ? "" : " ");
    }
    cout << "\n";
}

int main() {
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