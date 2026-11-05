# [Posh Shopping (POSHOP)](https://www.codechef.com/problems/POSHOP)

- **Difficulty Rating**: 773
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ items with costs $C_1, C_2, \dots, C_N$. You can choose to buy either one item or two items. If you buy two items at indices $i$ and $j$ (where $i < j$), the condition $C_i \le C_j$ must be satisfied. The goal is to maximize the total cost of the items purchased.

## Intuition & Mathematical Observation
The problem allows for two scenarios:
1. **Buying one item**: The maximum cost is simply the maximum value present in the array $C$.
2. **Buying two items**: We must select two indices $i$ and $j$ such that $i < j$ and $C_i \le C_j$. The total cost is $C_i + C_j$.

Given the constraints $N \le 100$, an $O(N^2)$ approach is perfectly efficient. We can iterate through all possible pairs $(i, j)$ where $i < j$, check if the condition $C_i \le C_j$ holds, and keep track of the maximum sum found. We initialize our answer with the maximum single item cost to cover the case where buying only one item is optimal.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case, as we use nested loops to iterate through all pairs of items. With $N=100$, $N^2 = 10,000$, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the costs of the items in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N items with costs C_1, C_2, ..., C_N.
 * We can buy at most two items.
 * If we buy one item, we can pick any item i.
 * If we buy two items i and j (where i < j), we must have C_i <= C_j.
 * We want to maximize the total cost.
 * 
 * Constraints: N <= 100, C_i <= 100.
 * Since N is small, we can iterate through all possible pairs (i, j) 
 * where 0 <= i < j < N and check the condition C_i <= C_j.
 * We also consider buying only one item (the maximum single item cost).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> C(N);
    int max_single = 0;
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        if (C[i] > max_single) {
            max_single = C[i];
        }
    }

    long long max_spent = max_single;

    // Check all pairs (i, j) such that i < j
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (C[i] <= C[j]) {
                long long current_sum = (long long)C[i] + C[j];
                if (current_sum > max_spent) {
                    max_spent = current_sum;
                }
            }
        }
    }

    cout << max_spent << "\n";
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