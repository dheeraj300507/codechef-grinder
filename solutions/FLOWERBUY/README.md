# [Buying Flowers (FLOWERBUY)](https://www.codechef.com/problems/FLOWERBUY)

- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary
We are tasked with buying exactly $N$ flowers. We have two options:
1. Buy a bundle of 2 flowers for 4 coins.
2. Buy a bundle of 3 flowers for 5 coins.

The goal is to find the minimum cost to obtain exactly $N$ flowers. If it is impossible to obtain exactly $N$ flowers using these bundles, the problem implies we should handle that (though for $N \ge 2$, solutions exist).

## Intuition & Mathematical Observation
This is a classic variation of the **Change Making Problem** or the **Unbounded Knapsack Problem**. 

Since we want to minimize the total cost, we can define a Dynamic Programming state `dp[i]` representing the minimum cost to acquire exactly `i` flowers. 
- To reach `i` flowers, we could have come from `i-2` flowers (by adding a bundle of 2) or `i-3` flowers (by adding a bundle of 3).
- The recurrence relation is:
  $$dp[i] = \min(dp[i-2] + 4, dp[i-3] + 5)$$
- **Base Case**: `dp[0] = 0` (0 cost to get 0 flowers). All other values are initialized to infinity to represent unreachable states.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from 1 to $N$ once. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the `dp` array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 2*x + 3*y = N, where x, y >= 0 are integers.
 * We want to minimize the cost: 4*x + 5*y.
 * 
 * Since N is small, we use dynamic programming:
 * dp[i] = min(dp[i-2] + 4, dp[i-3] + 5)
 */

void solve() {
    int N;
    cin >> N;

    // dp[i] stores the minimum cost to get exactly i flowers.
    // Initialize with a large value representing infinity.
    vector<long long> dp(N + 1, 1e18);
    
    dp[0] = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (i >= 2 && dp[i - 2] != 1e18) {
            dp[i] = min(dp[i], dp[i - 2] + 4);
        }
        if (i >= 3 && dp[i - 3] != 1e18) {
            dp[i] = min(dp[i], dp[i - 3] + 5);
        }
    }
    
    cout << dp[N] << "\n";
}

int main() {
    // Fast I/O
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