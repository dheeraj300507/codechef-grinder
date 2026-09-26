# [Chef and Price Control (PRICECON)](https://www.codechef.com/problems/PRICECON)

- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef sells $N$ items, each with a specific price $P_i$. The government introduces a price ceiling $K$. Any item with a price $P_i > K$ must now be sold at price $K$. The goal is to calculate the total revenue lost by Chef due to this new price ceiling.

## Intuition & Mathematical Observation
The revenue lost for a single item $i$ is the difference between its original price and the ceiling price, provided the original price is greater than the ceiling. Mathematically, the lost revenue for item $i$ is:
$$\text{Loss}_i = \max(0, P_i - K)$$

To find the total lost revenue, we sum these individual losses:
$$\text{Total Loss} = \sum_{i=1}^{N} \max(0, P_i - K)$$

Alternatively, this can be viewed as:
$$\text{Total Loss} = (\text{Original Total Revenue}) - (\text{New Total Revenue})$$
Where the new revenue is $\sum \min(P_i, K)$. Both approaches yield the same result, but the first approach is more direct as it calculates the loss incrementally.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of items. We iterate through the list of prices exactly once. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$, as we only store the running sum of the lost revenue and do not need to store the entire array of prices.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N items with prices P_i.
 * A price ceiling K is introduced.
 * If P_i > K, the price becomes K.
 * The lost revenue for a single item i is:
 * - If P_i > K: P_i - K
 * - If P_i <= K: 0
 * Total lost revenue = Sum of max(0, P_i - K) for all i from 1 to N.
 */

void solve() {
    int N;
    long long K;
    if (!(cin >> N >> K)) return;
    
    long long lost_revenue = 0;
    for (int i = 0; i < N; ++i) {
        long long P;
        cin >> P;
        // If the price exceeds the ceiling, add the difference to total loss
        if (P > K) {
            lost_revenue += (P - K);
        }
    }
    cout << lost_revenue << "\n";
}

int main() {
    // Fast I/O setup for performance
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