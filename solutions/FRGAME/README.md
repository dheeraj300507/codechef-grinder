# [Game between friends (FRGAME)](https://www.codechef.com/problems/FRGAME)

- **Difficulty Rating**: 991
- **Solved in**: 1 attempt(s)

## Problem Summary
Nitin and Sobhagya start with $A$ and $B$ coins respectively. The game proceeds in two steps:
1. Ritik gives $C$ coins to the player who currently has fewer coins (if they are equal, Nitin is considered to be "not winning," so Sobhagya receives the coins).
2. Satyarth gives $D$ coins to the player who currently has fewer coins.

We need to determine the final winner. Sobhagya wins if $B > A$ at the end; otherwise, Nitin wins.

## Intuition & Mathematical Observation
The problem describes a simple simulation. Since the number of steps is fixed at two, we do not need complex logic or loops. We simply track the coin counts $A$ and $B$ and update them based on the condition provided:
- If $B > A$, Nitin is losing, so he receives the coins.
- If $A \ge B$, Sobhagya is losing (or tied), so she receives the coins.

By applying this logic sequentially for $C$ and then $D$, we arrive at the final state of the game. Using `long long` ensures that we avoid any potential overflow, although the constraints ($10^6$) are small enough that standard integers would also suffice.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate states.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Nitin starts with A coins, Sobhagya with B coins.
 * Winning condition: Sobhagya wins if B > A, otherwise Nitin wins (A >= B).
 * 
 * Step 1: Ritik gives C coins to the player who is not winning.
 * Step 2: Satyarth gives D coins to the player who is not winning.
 * 
 * We simulate these two steps sequentially.
 */

void solve() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    // First step: Ritik gives C coins
    if (B > A) {
        // Sobhagya is winning, so Nitin gets C
        A += C;
    } else {
        // Nitin is winning (or tied), so Sobhagya gets C
        B += C;
    }

    // Second step: Satyarth gives D coins
    if (B > A) {
        // Sobhagya is winning, so Nitin gets D
        A += D;
    } else {
        // Nitin is winning (or tied), so Sobhagya gets D
        B += D;
    }

    // Final check
    if (B > A) {
        cout << "S" << "\n";
    } else {
        cout << "N" << "\n";
    }
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