# [Airline Restrictions (AIRLINE)](https://www.codechef.com/problems/AIRLINE)

- **Difficulty Rating**: 1042
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has three bags with weights $A$, $B$, and $C$. To board the flight, she must check in two bags and carry one bag with her. The airline has two strict constraints:
1. The sum of the weights of the two checked-in bags must not exceed $D$.
2. The weight of the bag carried by hand must not exceed $E$.

We need to determine if there exists a combination of bags that satisfies both conditions.

## Intuition & Mathematical Observation
Since there are only three bags, there are exactly three possible scenarios for which bag Chef carries by hand:
1. **Carry bag $A$**: The checked-in bags are $B$ and $C$. Condition: $(B + C \le D)$ and $(A \le E)$.
2. **Carry bag $B$**: The checked-in bags are $A$ and $C$. Condition: $(A + C \le D)$ and $(B \le E)$.
3. **Carry bag $C$**: The checked-in bags are $A$ and $B$. Condition: $(A + B \le D)$ and $(C \le E)$.

If any one of these three scenarios evaluates to true, the answer is "YES". If none of them satisfy the conditions, the answer is "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a constant number of arithmetic operations and comparisons regardless of the input values, the execution time is constant.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the weights and constraints, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 3 bags with weights A, B, and C.
 * She must check-in 2 bags and carry 1 bag.
 * Constraints:
 * 1. Sum of checked-in bags <= D
 * 2. Weight of carried bag <= E
 * 
 * There are 3 possible scenarios for which bag is carried:
 * 1. Carry A: Check-in (B+C) <= D and A <= E
 * 2. Carry B: Check-in (A+C) <= D and B <= E
 * 3. Carry C: Check-in (A+B) <= D and C <= E
 * 
 * If any of these scenarios are true, output YES, otherwise NO.
 */

void solve() {
    int A, B, C, D, E;
    if (!(cin >> A >> B >> C >> D >> E)) return;

    bool possible = false;

    // Scenario 1: Carry A
    if ((B + C <= D) && (A <= E)) {
        possible = true;
    }
    // Scenario 2: Carry B
    else if ((A + C <= D) && (B <= E)) {
        possible = true;
    }
    // Scenario 3: Carry C
    else if ((A + B <= D) && (C <= E)) {
        possible = true;
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
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