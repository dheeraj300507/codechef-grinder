# [Reselling Items (RESELL)](https://www.codechef.com/problems/RESELL)

- **Difficulty Rating**: 903
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ items, each with a specific resale value $A_i$. He can purchase these items to resell them. The cost structure is as follows:
- The first $K$ items purchased cost 5 coins each.
- Any additional items purchased beyond the first $K$ cost 10 coins each.

The goal is to maximize the total profit, where profit for a single item is defined as `(Resale Value - Cost)`. We only buy an item if the resulting profit is positive.

## Intuition & Mathematical Observation
To maximize the total profit, we must make optimal decisions regarding which items to buy and how to assign the costs:

1.  **Greedy Strategy**: Since we want to maximize profit, we should always prioritize items with the highest resale values. By sorting the resale values in descending order, we ensure that the most valuable items are considered first.
2.  **Cost Assignment**: We have $K$ "cheap" slots (cost 5) and unlimited "expensive" slots (cost 10). To maximize the sum, we should assign the $K$ cheapest costs to the $K$ items with the highest resale values.
3.  **Profitability Check**: An item should only be purchased if its resale value is greater than its associated cost. 
    *   For the top $K$ items: Only buy if $A_i > 5$.
    *   For the remaining items: Only buy if $A_i > 10$.

By sorting the array $A$ in descending order, the first $K$ elements naturally receive the cost of 5, and the subsequent elements receive the cost of 10.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan through the array takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the resale values of the $N$ items.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Sort resale values in descending order to prioritize higher values.
 * 2. Assign the first K items a cost of 5.
 * 3. Assign the remaining items a cost of 10.
 * 4. Only add to total_profit if (Resale Value - Cost) > 0.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to prioritize higher resale values
    sort(A.rbegin(), A.rend());

    long long total_profit = 0;
    for (int i = 0; i < N; ++i) {
        if (i < K) {
            // First K items cost 5
            if (A[i] > 5) {
                total_profit += (A[i] - 5);
            }
        } else {
            // Remaining items cost 10
            if (A[i] > 10) {
                total_profit += (A[i] - 10);
            }
        }
    }

    cout << total_profit << "\n";
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