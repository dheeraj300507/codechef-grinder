# [Table Strength (STRONGTABLE)](https://www.codechef.com/problems/STRONGTABLE)

- **Difficulty Rating**: 1211
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ table legs, each with a specific strength $W_i$. If you choose a subset of $k$ legs to support a table, the weight $W$ is distributed equally among them, meaning each leg bears a load of $W/k$. For the table to remain stable, the load on each leg must not exceed its individual strength. Therefore, for every leg $j$ in the chosen subset, $W/k \le W_j$ must hold. This implies $W \le k \times \min(W_{subset})$. The goal is to maximize the total weight $W$ the table can support.

## Intuition & Mathematical Observation
To maximize $W = k \times \min(W_{subset})$, we need to make an optimal choice for the subset:
1. If we decide that the minimum strength in our subset will be $W_i$, then to maximize the total weight, we should include every leg that has a strength greater than or equal to $W_i$.
2. By sorting the array of strengths in non-decreasing order ($W_0 \le W_1 \le \dots \le W_{N-1}$), if we pick $W_i$ as the minimum strength, all legs from index $i$ to $N-1$ satisfy the condition.
3. The number of such legs is $k = (N - i)$.
4. The maximum weight for a chosen minimum $W_i$ is $W_i \times (N - i)$.
5. By iterating through all possible values of $i$ from $0$ to $N-1$ and calculating this product, we can find the global maximum weight.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the strengths of the $N$ legs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Suppose we choose a subset of k legs with strengths W_1, W_2, ..., W_k.
 * Let the minimum strength among these be W_min.
 * The weight W distributed equally is W/k.
 * For the table to hold, W/k <= W_i for all i in the subset.
 * This implies W/k <= W_min, so W <= k * W_min.
 * To maximize W, we should pick a subset of size k such that all legs have strength >= W_min.
 * If we sort the strengths in non-decreasing order: W_0 <= W_1 <= ... <= W_{N-1},
 * and we decide that the minimum strength in our subset is W_i,
 * then to maximize the number of legs k, we should pick all legs from index i to N-1.
 * The number of such legs is (N - i).
 * The maximum weight for this choice is (N - i) * W_i.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    // Sort the strengths to easily count how many legs have strength >= W_i
    sort(w.begin(), w.end());

    long long max_weight = 0;
    for (int i = 0; i < n; ++i) {
        // If we pick w[i] as the minimum strength, 
        // we can include all legs from i to n-1.
        // The number of legs is (n - i).
        long long current_weight = w[i] * (n - i);
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }

    cout << max_weight << "\n";
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