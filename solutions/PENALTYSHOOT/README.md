# [Penalty Shoot-out (PENALTYSHOOT)](https://www.codechef.com/problems/PENALTYSHOOT)

- **Difficulty Rating**: 869
- **Solved in**: 2 attempt(s)

## Problem Summary
In a penalty shootout, Team A has already taken 3 shots and has 2 remaining, while Team B has taken 4 shots and has 1 remaining. Given the current scores $X$ (for Team A) and $Y$ (for Team B), determine if it is possible for the match to end in a draw after all 5 shots for each team are completed.

## Intuition & Mathematical Observation
The problem asks whether there exists a final score $S$ that both teams can achieve given their remaining shots.

1.  **Team A's potential range**: Since Team A has 2 shots left, their final score will be in the range $[X, X + 2]$.
2.  **Team B's potential range**: Since Team B has 1 shot left, their final score will be in the range $[Y, Y + 1]$.
3.  **Intersection Logic**: A draw is possible if there is at least one integer $S$ that falls into both intervals. Two intervals $[L_1, R_1]$ and $[L_2, R_2]$ intersect if and only if:
    $$\max(L_1, L_2) \le \min(R_1, R_2)$$
    Substituting our values:
    $$\max(X, Y) \le \min(X + 2, Y + 1)$$

If this condition holds, it is possible for both teams to reach the same score $S$, resulting in a draw.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic and comparison operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the scores and bounds.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Team A has 3 turns completed, 2 turns remaining.
 * Team B has 4 turns completed, 1 turn remaining.
 * 
 * Team A's final score will be in the range [X, X + 2].
 * Team B's final score will be in the range [Y, Y + 1].
 * 
 * A draw is possible if there exists a score S such that:
 * X <= S <= X + 2 AND Y <= S <= Y + 1.
 * This is equivalent to checking if the intersection of [X, X+2] 
 * and [Y, Y+1] is non-empty.
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;

    int min_A = X;
    int max_A = X + 2;
    int min_B = Y;
    int max_B = Y + 1;

    // Two intervals [L1, R1] and [L2, R2] intersect if 
    // max(L1, L2) <= min(R1, R2)
    if (max(min_A, min_B) <= min(max_A, max_B)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
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