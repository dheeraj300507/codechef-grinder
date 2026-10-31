# [Chef and Stocks (STOCKMARKET)](https://www.codechef.com/problems/STOCKMARKET)

- **Difficulty Rating**: 948
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a list of predicted stock price changes for $N$ days. He wants to choose exactly $N-1$ days to invest in, effectively skipping exactly one day. The goal is to maximize the total profit, which is the sum of the price changes of the chosen days.

## Intuition & Mathematical Observation
The total profit for $N-1$ days is calculated as:
$$\text{Total Profit} = \left( \sum_{i=1}^{N} A_i \right) - A_{\text{skipped}}$$

To maximize this value, we need to subtract the smallest possible value from the total sum. Therefore, the strategy is:
1. Calculate the sum of all $N$ elements in the array.
2. Identify the minimum element ($A_{min}$) in the array.
3. The maximum profit is simply `Total Sum - Minimum Element`.

Since the constraints on $A_i$ are small ($-100$ to $100$), this approach is highly efficient and avoids the need for complex data structures or sorting.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the sum and find the minimum element.
- **Space Complexity**: $O(1)$ (if we process elements on the fly) or $O(N)$ (if we store them in a vector). In the provided solution, we use $O(N)$ space to store the input, though it could be optimized to $O(1)$ by calculating the sum and minimum during input reading.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to skip exactly one day to maximize the total profit.
 * Total profit = (Sum of all A_i) - (A_i that is skipped).
 * To maximize the total profit, we need to minimize the value of the skipped day (A_i).
 */

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    long long total_sum = 0;
    // Initialize min_val with a value larger than any possible A_i (max 100)
    long long min_val = 200; 
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }
    
    // We skip the day with the minimum profit to maximize the remaining sum.
    cout << (total_sum - min_val) << "\n";
}

int main() {
    // Fast I/O for performance
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