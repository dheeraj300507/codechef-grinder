# [Drawing Chances (DRAWCH)](https://www.codechef.com/problems/DRAWCH)

- **Difficulty Rating**: 945
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a total of $N$ matches to be played in a tournament, where $M$ matches have already been completed, we are given the results of those $M$ matches as a string $S$ (where '1' represents an Alice win and '0' represents a Bob win). We need to determine if it is possible for the tournament to end in a draw, meaning both Alice and Bob finish with exactly $N/2$ wins each.

## Intuition & Mathematical Observation
1. **Parity Check**: A draw is only possible if the total number of matches $N$ is even. If $N$ is odd, it is impossible for both players to have the same number of wins, so we immediately output "No".
2. **Target Calculation**: For a draw to occur, Alice must end with exactly $N/2$ wins.
3. **Current State**: We count the number of wins Alice currently has from the string $S$ (let this be `alice_wins`).
4. **Remaining Matches**: The number of matches left to be played is $R = N - M$.
5. **Feasibility**: 
   - Alice needs `needed = (N/2) - alice_wins` more wins to reach the target.
   - If `needed` is negative, Alice has already exceeded the required wins for a draw, making it impossible.
   - If `needed` is greater than the number of remaining matches $R$, Alice cannot reach the target.
   - If $0 \le \text{needed} \le R$, it is possible for Alice to win exactly the required number of remaining matches to reach $N/2$, resulting in a draw.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the total number of matches. We iterate through the string $S$ of length $M$ once.
- **Space Complexity**: $O(M)$ to store the input string $S$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Total matches = N
 * Matches played = M
 * Matches remaining = R = N - M
 * Alice's current wins = A
 * 
 * For a tie, both must have N/2 wins.
 * This is only possible if N is even.
 * If N is even, Alice needs (N/2 - A) more wins.
 * Let x = N/2 - A.
 * We need 0 <= x <= R.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    string S;
    cin >> S;

    // A draw is impossible if the total number of matches is odd
    if (N % 2 != 0) {
        cout << "No" << "\n";
        return;
    }

    int alice_wins = 0;
    for (char c : S) {
        if (c == '1') {
            alice_wins++;
        }
    }

    int target = N / 2;
    int needed = target - alice_wins;
    int remaining = N - M;

    // Check if the required wins are achievable within the remaining matches
    if (needed >= 0 && needed <= remaining) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
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