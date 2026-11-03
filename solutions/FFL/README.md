# [Chef in Fantasy League (FFL)](https://www.codechef.com/problems/FFL)

- **Difficulty Rating**: 1225
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to build a fantasy football team. He has already spent $S$ dollars on players and has a remaining budget of $100 - S$ dollars. To complete his team, he must select exactly one defender (type 0) and one forward (type 1) from a given list of $N$ players, each with a specific price $P_i$ and type $T_i$. The goal is to determine if it is possible to pick one player of each type such that the total cost of these two players does not exceed the remaining budget.

## Intuition & Mathematical Observation
To maximize the chances of staying within the budget, we should always pick the cheapest available defender and the cheapest available forward. 

1. **Greedy Approach**: Since we only need one of each type, picking any player other than the cheapest one of that type would only increase the total cost, making it harder to satisfy the condition $S + \text{price}_{\text{defender}} + \text{price}_{\text{forward}} \le 100$.
2. **Implementation**: 
   - Initialize two variables, `min_defender` and `min_forward`, to a value larger than the maximum possible price (e.g., 101).
   - Iterate through the list of players once. If a player is a defender ($T_i = 0$), update `min_defender`. If a player is a forward ($T_i = 1$), update `min_forward`.
   - After the loop, check if both types were found and if the sum of their minimum prices plus $S$ is $\le 100$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of players. We perform a single pass through the input arrays to find the minimums.
- **Space Complexity**: $O(N)$ to store the prices and types, though this could be optimized to $O(1)$ by processing the input on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs to pick one defender (type 0) and one forward (type 1).
 * He already spent S dollars.
 * Total budget is 100.
 * So, we need to find min_defender_price + min_forward_price + S <= 100.
 */

void solve() {
    int N, S;
    cin >> N >> S;
    
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    
    int min_defender = 101; // Initialize with a value > max possible price
    int min_forward = 101;
    
    bool found_defender = false;
    bool found_forward = false;
    
    for (int i = 0; i < N; ++i) {
        if (T[i] == 0) { // Defender
            if (P[i] < min_defender) {
                min_defender = P[i];
                found_defender = true;
            }
        } else { // Forward
            if (P[i] < min_forward) {
                min_forward = P[i];
                found_forward = true;
            }
        }
    }
    
    if (found_defender && found_forward && (S + min_defender + min_forward <= 100)) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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