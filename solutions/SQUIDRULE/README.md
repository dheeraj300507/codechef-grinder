# [The Squid Game (SQUIDRULE)](https://www.codechef.com/problems/SQUIDRULE)

- **Difficulty Rating**: 970
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game with $N$ players, each player $i$ has an associated value $A_i$. When a player is eliminated, their value $A_i$ is added to the prize pool. We need to choose one player to be the winner. The winner is not eliminated, meaning their value $A_i$ is **not** added to the prize pool. The goal is to choose the winner such that the total prize pool is maximized.

## Intuition & Mathematical Observation
The total prize pool is the sum of the values of all players who are eliminated. If we choose player $k$ as the winner, the prize pool will be the sum of all $A_i$ for $i \neq k$.

Mathematically, the prize pool for a chosen winner $k$ is:
$$\text{Prize} = \left( \sum_{i=1}^{N} A_i \right) - A_k$$

To maximize this value, we need to subtract the smallest possible $A_k$. Therefore, the optimal strategy is to identify the player with the minimum value in the array and exclude them from the total sum.

**Algorithm:**
1. Calculate the sum of all elements in the array.
2. Find the minimum element in the array.
3. Subtract the minimum element from the total sum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the sum and find the minimum value.
- **Space Complexity**: $O(1)$, as we only store a few variables (`total_sum`, `min_val`, `val`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N players. When player i is eliminated, A_i is added to the pool.
 * If we choose player k to be the winner, they are NOT eliminated.
 * Therefore, the prize pool will contain the sum of all A_i except A_k.
 * To maximize the prize pool, we need to choose k such that the sum of all A_i 
 * excluding A_k is maximized.
 * This is equivalent to (Total Sum of all A_i) - (Minimum A_i).
 */

void solve() {
    int N;
    cin >> N;
    
    long long total_sum = 0;
    long long min_val = -1;
    
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        total_sum += val;
        
        // Initialize min_val with the first element, then update if a smaller value is found
        if (i == 0) {
            min_val = val;
        } else {
            if (val < min_val) {
                min_val = val;
            }
        }
    }
    
    // The winner gets the sum of all A_i except the one that would have been 
    // added if the winner were eliminated. To maximize the prize, we exclude 
    // the smallest value.
    cout << (total_sum - min_val) << "\n";
}

int main() {
    // Fast I/O setup
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