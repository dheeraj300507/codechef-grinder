# [Chef and Contest (CHEFCONTEST)](https://www.codechef.com/problems/CHEFCONTEST)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Chefina participated in a contest. Chef solved the problem in $X$ minutes with $P$ wrong submissions, while Chefina solved it in $Y$ minutes with $Q$ wrong submissions. Each wrong submission adds a penalty of 10 minutes to the total time taken. We need to determine who finished with a lower total penalty, or if it resulted in a draw.

## Intuition & Mathematical Observation
The total penalty for each participant is calculated as:
- **Chef's Total Penalty** = $X + (P \times 10)$
- **Chefina's Total Penalty** = $Y + (Q \times 10)$

By calculating these two values, we can directly compare them:
1. If Chef's penalty < Chefina's penalty, **Chef** wins.
2. If Chefina's penalty < Chef's penalty, **Chefina** wins.
3. If both penalties are equal, it is a **Draw**.

Since the constraints are small ($X, Y, P, Q \le 100$), standard integer arithmetic is perfectly safe and will not overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated penalties.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's penalty = X + (P * 10)
 * Chefina's penalty = Y + (Q * 10)
 * We need to compare these two values and output the winner.
 * Constraints are small (X, Y, P, Q <= 100), so standard integer types are sufficient.
 */

void solve() {
    long long X, Y, P, Q;
    if (!(cin >> X >> Y >> P >> Q)) return;

    long long chef_penalty = X + (P * 10);
    long long chefina_penalty = Y + (Q * 10);

    if (chef_penalty < chefina_penalty) {
        cout << "Chef" << "\n";
    } else if (chefina_penalty < chef_penalty) {
        cout << "Chefina" << "\n";
    } else {
        cout << "Draw" << "\n";
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