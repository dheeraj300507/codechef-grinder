# [Chess Olympiad (CHOLY)](https://www.codechef.com/problems/CHOLY)

- **Difficulty Rating**: 641
- **Solved in**: 1 attempt(s)

## Problem Summary
In a Chess Olympiad, a team plays a total of 4 games. Given the current number of wins ($X$), draws ($Y$), and losses ($Z$) for our team, we need to determine if it is possible for our team to have a strictly higher total score than the opponent after all 4 games are completed. A win awards 1 point, a draw awards 0.5 points, and a loss awards 0 points.

## Intuition & Mathematical Observation
1. **Scoring Rules**: 
   - Our current score: $P_{us} = X \times 1 + Y \times 0.5$
   - Opponent's current score: $P_{opp} = Z \times 1 + Y \times 0.5$
2. **Remaining Games**: The total number of games is 4. The number of games already played is $X + Y + Z$. Therefore, the number of remaining games is $R = 4 - (X + Y + Z)$.
3. **Winning Condition**: To check if it is *possible* to win, we assume our team wins all remaining $R$ games.
   - Final score for us: $P_{us\_final} = P_{us} + R$
   - Final score for opponent: $P_{opp\_final} = P_{opp}$
4. **Comparison**: If $P_{us\_final} > P_{opp\_final}$, output "Yes"; otherwise, output "No".

*Note: Since we are dealing with 0.5 points, we can either use `double` or multiply all values by 2 to work entirely with integers.*

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated scores.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each team plays 4 games in total.
 * Current state: X wins, Y draws, Z losses.
 * Total games played = X + Y + Z.
 * Remaining games = 4 - (X + Y + Z).
 * 
 * Current points for our team: P_us = X * 1.0 + Y * 0.5
 * Current points for opponent: P_opp = Z * 1.0 + Y * 0.5
 * 
 * To maximize our chances of winning, we assume we win all remaining games.
 * If we win all remaining games, our final points will be:
 * P_us_final = P_us + (4 - (X + Y + Z))
 * P_opp_final = P_opp
 * 
 * We win the round if P_us_final > P_opp_final.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    // Calculate current points (using double to handle 0.5)
    double p_us = (double)X + (double)Y * 0.5;
    double p_opp = (double)Z + (double)Y * 0.5;

    // Number of games remaining
    int remaining = 4 - (X + Y + Z);

    // If we win all remaining games, our score increases by 'remaining'
    double p_us_final = p_us + (double)remaining;
    double p_opp_final = p_opp;

    // Check if strictly greater
    if (p_us_final > p_opp_final) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```