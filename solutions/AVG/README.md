# [Average Number (AVG)](https://www.codechef.com/problems/AVG)

- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ of $N$ integers. We are told that this array was originally part of a larger sequence of length $N+K$, where the average of all $N+K$ elements was $V$. We need to find the value of the $K$ missing elements, assuming all $K$ missing elements are equal to some integer $X$. If no such positive integer $X$ exists, we output -1.

## Intuition & Mathematical Observation
Let the sum of the $N$ given elements be $S_A$.
Let the value of each of the $K$ missing elements be $X$.

The total sum of the original sequence of length $N+K$ is given by:
$$\text{Total Sum} = V \times (N + K)$$

We also know that the total sum is the sum of the $N$ known elements plus the sum of the $K$ missing elements:
$$\text{Total Sum} = S_A + (K \times X)$$

Equating these two expressions:
$$V \times (N + K) = S_A + (K \times X)$$
$$K \times X = V \times (N + K) - S_A$$
$$X = \frac{V \times (N + K) - S_A}{K}$$

For $X$ to be a valid solution, two conditions must be met:
1. **Divisibility**: The numerator $(V \times (N + K) - S_A)$ must be perfectly divisible by $K$ (i.e., the remainder must be 0).
2. **Positivity**: Since the problem implies the missing numbers are positive integers, $X$ must be greater than 0.

If these conditions are met, $X$ is our answer; otherwise, the answer is -1.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to calculate the sum of the $N$ elements.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the original sequence be S of length N + K.
 * The average of all elements is V.
 * Sum of all elements = V * (N + K).
 * Let the sum of the remaining N elements be S_A = sum(A_1, ..., A_N).
 * Let the value of the K deleted elements be X.
 * Then, S_A + K * X = V * (N + K).
 * K * X = V * (N + K) - S_A.
 * X = (V * (N + K) - S_A) / K.
 * 
 * Conditions for X to be valid:
 * 1. (V * (N + K) - S_A) must be divisible by K (i.e., remainder is 0).
 * 2. X must be a positive integer (X > 0).
 */

void solve() {
    long long N, K, V;
    cin >> N >> K >> V;
    
    long long sum_A = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum_A += a;
    }
    
    long long total_sum = V * (N + K);
    long long remaining_sum = total_sum - sum_A;
    
    // Check if the remaining sum is positive and divisible by K
    if (remaining_sum > 0 && remaining_sum % K == 0) {
        cout << remaining_sum / K << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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