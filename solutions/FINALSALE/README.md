# [Sale (FINALSALE)](https://www.codechef.com/problems/FINALSALE)

- **Difficulty Rating**: 1180
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a record of sales for $N$ days, denoted by $A_1, A_2, \dots, A_N$. If Chef decides to close the shop on day $k$ (where $1 \le k \le N$), the total sales calculated is the sum of all sales from day 1 to $k-1$, plus twice the sales of day $k$. The goal is to choose an index $k$ that maximizes this total value.

## Intuition & Mathematical Observation
Let $S_k$ be the prefix sum of the sales up to day $k$, defined as $S_k = \sum_{i=1}^{k} A_i$.
The problem states that if the shop closes on day $k$, the total sales $T_k$ is:
$$T_k = \left( \sum_{i=1}^{k-1} A_i \right) + 2 \cdot A_k$$

We can rewrite this expression by splitting the $2 \cdot A_k$ term:
$$T_k = \left( \sum_{i=1}^{k-1} A_i \right) + A_k + A_k$$
$$T_k = \left( \sum_{i=1}^{k} A_i \right) + A_k$$
$$T_k = S_k + A_k$$

To find the maximum possible sales, we simply need to iterate through all possible days $k$ from $1$ to $N$, maintain a running prefix sum, calculate $S_k + A_k$ for each day, and track the maximum value encountered. Since $A_i$ can be up to $10^9$ and $N$ up to $3 \cdot 10^5$, the total sum will exceed the capacity of a 32-bit integer, so we must use `long long` in C++.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the prefix sum and the potential total for each day. Given the sum of $N$ over all test cases is $3 \cdot 10^5$, this is well within the time limits.
- **Space Complexity**: $O(N)$ to store the input array. This could be optimized to $O(1)$ by calculating the sum on the fly, but $O(N)$ is well within memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N days with sales A_1, A_2, ..., A_N.
 * If Chef closes the shop on day k (1 <= k <= N), the total sales will be:
 * Total = (A_1 + A_2 + ... + A_{k-1}) + (2 * A_k)
 * Total = (A_1 + A_2 + ... + A_k) + A_k
 * 
 * Let S_k be the prefix sum of the first k days: S_k = A_1 + A_2 + ... + A_k.
 * Then the total sales if closed on day k is S_k + A_k.
 * We need to maximize (S_k + A_k) for 1 <= k <= N.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    long long current_prefix_sum = 0;
    long long max_sales = -1; 
    
    for (int i = 0; i < n; ++i) {
        current_prefix_sum += a[i];
        long long current_total = current_prefix_sum + a[i];
        if (current_total > max_sales) {
            max_sales = current_total;
        }
    }
    
    cout << max_sales << "\n";
}

int main() {
    // Fast I/O
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