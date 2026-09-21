# [Possible Victory (T20MCH)](https://www.codechef.com/problems/T20MCH)

- **Difficulty Rating**: 769
- **Solved in**: 1 attempt(s)

## Problem Summary
In a T20 cricket match, Team A has scored $R$ runs. Team B has already played $O$ overs and scored $C$ runs. We need to determine if it is mathematically possible for Team B to score more than $R$ runs by the end of the 20th over, assuming they score the maximum possible runs (6 runs per ball) for every remaining ball.

## Intuition & Mathematical Observation
1. **Calculate Remaining Overs**: A T20 match consists of 20 overs. If Team B has already played $O$ overs, the remaining overs are $20 - O$.
2. **Calculate Maximum Runs per Over**: Each over consists of 6 balls. If the team scores the maximum possible runs (6) on every ball, they can score $6 \times 6 = 36$ runs per over.
3. **Calculate Maximum Potential Score**: The maximum additional runs Team B can score is $(20 - O) \times 36$. Adding this to their current score $C$ gives the maximum possible total score:
   $$\text{Max Score} = C + (20 - O) \times 36$$
4. **Comparison**: If $\text{Max Score} > R$, Team B can potentially win, so we output "YES". Otherwise, we output "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and intermediate results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Team A scored R runs.
 * Team B has played O overs and scored C runs.
 * Remaining overs = 20 - O.
 * Each over has 6 balls, and each ball can score a maximum of 6 runs.
 * Maximum runs per over = 6 * 6 = 36.
 * Maximum runs possible in remaining overs = (20 - O) * 36.
 * Maximum total score for Team B = C + (20 - O) * 36.
 * Team B wins if (Maximum total score) > R.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, O, C;
    if (cin >> R >> O >> C) {
        int remaining_overs = 20 - O;
        int max_additional_runs = remaining_overs * 36;
        int max_total_score = C + max_additional_runs;

        if (max_total_score > R) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```