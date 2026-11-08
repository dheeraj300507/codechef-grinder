# [Chef and Easy Queries (CHEFEZQ)](https://www.codechef.com/problems/CHEFEZQ)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef receives a specific number of queries $Q_i$ on each day $i$ for $n$ days. Chef can process at most $k$ queries per day. Any queries not processed on day $i$ are carried over to day $i+1$. We need to determine the first day on which Chef processes fewer than $k$ queries. If he finishes all $n$ days and still has pending queries, we must calculate the day he finally clears the backlog.

## Intuition & Mathematical Observation
1. **Simulation**: We maintain a `carry` variable representing the number of queries brought forward from the previous day.
2. **Daily Processing**: For each day $i$ (from $1$ to $n$):
   - The total available queries are `carry + Q[i]`.
   - If `total < k`, Chef processes all of them and finishes on day $i$. This is the answer.
   - Otherwise, Chef processes exactly $k$ queries, and the new `carry` becomes `total - k`.
3. **Handling the Backlog**: If the loop completes and `carry > 0`, Chef continues to process $k$ queries per day until the backlog is empty. The number of additional days required is $\lceil \text{carry} / k \rceil$. Using integer arithmetic, this is calculated as `(carry + k) / k`. The final day is $n + \text{additional\_days}$.

## Complexity Analysis
- **Time Complexity**: $O(n)$ per test case, as we iterate through the $n$ days exactly once.
- **Space Complexity**: $O(n)$ to store the input array, though this could be optimized to $O(1)$ by processing queries on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef receives Q_i queries on day i. He can answer at most k queries per day.
 * Let S_i be the number of queries carried over to day i.
 * S_1 = 0
 * On day i, total queries available = S_i + Q_i.
 * If (S_i + Q_i) < k, Chef answers all (S_i + Q_i) queries and is free on day i.
 * Otherwise, he answers k queries and carries over (S_i + Q_i - k) to day i+1.
 */

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<long long> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    
    long long carry = 0;
    for (int i = 0; i < n; ++i) {
        long long total = carry + q[i];
        if (total < k) {
            cout << i + 1 << "\n";
            return;
        }
        carry = total - k;
    }
    
    // If we reach here, Chef still has 'carry' queries left after day n.
    // He answers k queries per day until he is done.
    // The number of additional days required is ceil(carry / k).
    // ceil(a/b) = (a + b - 1) / b using integer division.
    
    long long additional_days = (carry + k) / k;
    cout << n + additional_days << "\n";
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