# [Movie Snacks (MOVPR)](https://www.codechef.com/problems/MOVPR)

- **Difficulty Rating**: 263
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef wants to buy exactly 2 popcorns and 3 drinks. He can buy them individually at prices $X$ (per popcorn) and $Y$ (per drink), or he can buy a combo pack for $Z$ which contains 1 popcorn and 1 drink. The goal is to find the minimum cost to acquire exactly 2 popcorns and 3 drinks.

## Intuition & Mathematical Observation
Since we need a fixed quantity (2 popcorns, 3 drinks), we can evaluate all possible ways to utilize the combo pack ($Z$). Because we only need 2 popcorns, we can purchase a maximum of 2 combos.

We compare the following three scenarios:
1. **Zero Combos**: Buy everything individually.
   - Cost = $2X + 3Y$
2. **One Combo**: Buy 1 combo, then buy the remaining 1 popcorn and 2 drinks individually.
   - Cost = $Z + (1X + 2Y)$
3. **Two Combos**: Buy 2 combos, then buy the remaining 1 drink individually.
   - Cost = $2Z + (1Y)$

By calculating these three values and taking the minimum, we guarantee the cheapest possible price for Chef.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated costs.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs 2 popcorns and 3 drinks.
 * Options:
 * 1. Buy everything individually: 2*X + 3*Y
 * 2. Buy 1 combo (1X + 1Y) and remaining (1X + 2Y): Z + X + 2*Y
 * 3. Buy 2 combos (2X + 2Y) and remaining (1Y): 2*Z + Y
 * 
 * Since we need 2 popcorns and 3 drinks, we can use at most 2 combos 
 * (because we only need 2 popcorns).
 * 
 * We compare these three scenarios to find the minimum cost.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    // Option 1: No combos
    long long cost1 = 2 * X + 3 * Y;
    
    // Option 2: 1 combo
    long long cost2 = Z + X + 2 * Y;
    
    // Option 3: 2 combos
    long long cost3 = 2 * Z + Y;
    
    // The minimum of these three options is the answer
    long long ans = min({cost1, cost2, cost3});
    cout << ans << endl;

    return 0;
}
```