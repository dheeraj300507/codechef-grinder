# [Pintu and Fruits (CHPINTU)](https://www.codechef.com/problems/CHPINTU)

- **Difficulty Rating**: 1313
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ baskets, where each basket contains a specific type of fruit $F_i$ and has an associated price $P_i$. We need to select exactly one fruit type (from $1$ to $M$) and purchase all baskets containing that specific fruit type. The goal is to choose the fruit type that minimizes the total cost of all baskets associated with it.

## Intuition & Mathematical Observation
The problem asks us to calculate the sum of prices for each distinct fruit type present in the input. Since $N$ and $M$ are small (up to 50), we can use an array to aggregate the costs.

1. **Data Aggregation**: We maintain an array `total_cost` of size $M+1$ to store the cumulative price for each fruit type.
2. **Tracking Presence**: Since we only care about fruit types that actually appear in the input, we use a boolean array `exists` to mark which fruit types are present.
3. **Finding the Minimum**: After iterating through all $N$ baskets and populating the `total_cost` array, we iterate through the range $[1, M]$. For every fruit type where `exists[i]` is true, we compare its `total_cost` with the current minimum found so far.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$ per test case. We iterate through the $N$ baskets once to calculate the sums and then iterate through the $M$ possible fruit types to find the minimum.
- **Space Complexity**: $O(M)$ to store the `total_cost` and `exists` arrays.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N baskets, each having a fruit type F_i and a price P_i.
 * We need to choose one fruit type (from 1 to M) such that we buy all baskets
 * containing that fruit type. We want to minimize the total cost.
 * 
 * Constraints:
 * N, M <= 50.
 * This allows an O(N + M) approach per test case.
 */

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // total_cost[i] stores the sum of prices for fruit type i
    // exists[i] tracks if fruit type i is available in at least one basket
    vector<long long> total_cost(M + 1, 0);
    vector<bool> exists(M + 1, false);

    for (int i = 0; i < N; ++i) {
        total_cost[F[i]] += P[i];
        exists[F[i]] = true;
    }

    long long min_price = -1;

    for (int i = 1; i <= M; ++i) {
        if (exists[i]) {
            if (min_price == -1 || total_cost[i] < min_price) {
                min_price = total_cost[i];
            }
        }
    }

    cout << min_price << "\n";
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