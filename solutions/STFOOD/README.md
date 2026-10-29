# [Chef and Street Food (STFOOD)](https://www.codechef.com/problems/STFOOD)

- **Difficulty Rating**: 1268
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is considering opening a new street food store. There are $N$ different types of food available. For each food type $i$, there are already $S_i$ stores in the market. The total number of people interested in food type $i$ is $P_i$, and the price of one unit of food type $i$ is $V_i$. If Chef opens a new store, the total number of stores for that food type becomes $S_i + 1$. The $P_i$ people are distributed equally among all stores. We need to calculate the maximum profit Chef can make by choosing the optimal food type to sell.

## Intuition & Mathematical Observation
For a specific food type $i$:
1. The total number of stores after Chef opens his shop is $S_i + 1$.
2. Since the $P_i$ people are distributed equally, the number of people visiting each store is $\lfloor \frac{P_i}{S_i + 1} \rfloor$.
3. The profit for food type $i$ is calculated as:
   $$\text{Profit}_i = \left\lfloor \frac{P_i}{S_i + 1} \right\rfloor \times V_i$$
4. Since we want to maximize the profit, we iterate through all $N$ food types, calculate the potential profit for each, and keep track of the maximum value found.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of food types. Given $T$ test cases, the total time complexity is $O(T \times N)$. With $T, N \le 100$, this easily passes within the time limit.
- **Space Complexity**: $O(1)$, as we only store a few variables to keep track of the current and maximum profit.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each food type i, there are S_i stores already present.
 * Chef opens a new store, so the total number of stores becomes (S_i + 1).
 * The number of people P_i is distributed among (S_i + 1) stores.
 * The number of people who buy from Chef's new store is floor(P_i / (S_i + 1)).
 * The profit for food type i is: floor(P_i / (S_i + 1)) * V_i.
 * We need to find the maximum profit among all N types.
 */

void solve() {
    int N;
    cin >> N;
    
    long long max_profit = 0;
    
    for (int i = 0; i < N; ++i) {
        long long S, P, V;
        cin >> S >> P >> V;
        
        // Chef opens a new store, so total stores = S + 1
        // Number of people per store = floor(P / (S + 1))
        long long people_per_store = P / (S + 1);
        long long current_profit = people_per_store * V;
        
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
    }
    
    cout << max_profit << "\n";
}

int main() {
    // Optimize I/O operations
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