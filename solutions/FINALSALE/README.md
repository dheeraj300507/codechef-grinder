# [Sale (FINALSALE)](https://www.codechef.com/problems/FINALSALE)

- **Difficulty Rating**: 1180
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given an array $A$ representing the sales made on each day. If you choose to close the sale on day $k$ (1-indexed), the total profit is calculated as the sum of all sales from day 1 to day $k-1$, plus twice the sale amount of day $k$. Your goal is to find the maximum possible total profit by choosing the optimal day $k$ to close the sale.

## Intuition & Mathematical Observation
Let $S_k$ be the prefix sum of the array up to day $k$, i.e., $S_k = \sum_{i=1}^{k} A_i$.

The problem states that the profit for closing on day $k$ is:
$$\text{Profit}_k = \left( \sum_{i=1}^{k-1} A_i \right) + 2 \cdot A_k$$

We can rewrite this expression to simplify the calculation:
$$\text{Profit}_k = \left( \sum_{i=1}^{k-1} A_i \right) + A_k + A_k$$
$$\text{Profit}_k = S_k + A_k$$

By iterating through the array once, we can maintain a running prefix sum $S_k$ and calculate the potential profit for each day $k$. We keep track of the maximum value encountered during this iteration to find the optimal closing day.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of days. We perform a single pass through the array to calculate the prefix sum and the potential profit.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process the input values on the fly without storing them in a vector.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The total sales if closing on day k (1-indexed) is:
 * (Sum of A[1...k-1]) + 2 * A[k]
 * = (Sum of A[1...k]) + A[k]
 * 
 * Complexity: O(N) time, O(N) space.
 * Given the constraints and the TLE, we ensure fast I/O and efficient memory usage.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long current_prefix_sum = 0;
    long long max_total_sales = -2e18; // Initialize with a very small value

    for (int i = 0; i < N; ++i) {
        current_prefix_sum += A[i];
        long long current_total = current_prefix_sum + A[i];
        if (current_total > max_total_sales) {
            max_total_sales = current_total;
        }
    }

    cout << max_total_sales << "\n";
}

int main() {
    // Optimization for faster I/O
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