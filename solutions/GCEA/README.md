# [Gotta Catch Em All (GCEA)](https://www.codechef.com/problems/GCEA)

- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ Pekómon, each with a specific difficulty level $A_i$. To catch a Pekómon, you have two options:
1. Use **Normal Pekóballs**: The cost is $A_i \times X$.
2. Use a **Master Pekóball**: The cost is a flat rate of $Y$.

The goal is to calculate the minimum total cost required to catch all $N$ Pekómon.

## Intuition & Mathematical Observation
For each individual Pekómon $i$, we want to minimize the expenditure. Since the choice for one Pekómon does not affect the cost of another, we can make an independent greedy decision for each:
- Calculate the cost of using Normal Pekóballs: $C_{normal} = A_i \times X$.
- Calculate the cost of using a Master Pekóball: $C_{master} = Y$.
- The optimal cost for the $i$-th Pekómon is simply $\min(C_{normal}, C_{master})$.

The total cost is the summation of these minimum values across all $N$ Pekómon:
$$\text{Total Cost} = \sum_{i=1}^{N} \min(A_i \times X, Y)$$

Given the constraints ($N, X, Y, A_i \le 100$), the maximum possible cost is $100 \times 100 \times 100 = 1,000,000$, which fits comfortably within a standard 32-bit integer. Using `long long` is recommended to prevent potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the list of Pekómon exactly once.
- **Space Complexity**: $O(N)$ to store the difficulty levels, though this could be optimized to $O(1)$ by processing the input values on the fly without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each Pekómon with difficulty A_i, we have two choices:
 * 1. Use Normal Pekóballs: Cost = A_i * X
 * 2. Use a Master Pekóball: Cost = Y
 * 
 * To minimize the total cost, for each Pekómon, we should choose the minimum
 * of these two options: min(A_i * X, Y).
 * 
 * Total cost = sum_{i=1 to N} min(A_i * X, Y)
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        // Cost to catch the i-th Pekómon is the minimum of using Normal or Master balls
        total_cost += min((long long)A[i] * X, Y);
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
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