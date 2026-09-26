# [Cricket Tournament (CRICKETUDYAM)](https://www.codechef.com/problems/CRICKETUDYAM)

- **Difficulty Rating**: 669
- **Solved in**: 1 attempt(s)

## Problem Summary
In a knockout cricket tournament involving $N$ teams, a match is played between two teams, and the loser is eliminated. This process continues until only one team remains (the winner). We need to determine if the total number of matches played in such a tournament is at least $M$.

## Intuition & Mathematical Observation
In any knockout tournament, every match results in exactly one team being eliminated. To determine a single winner from $N$ teams, $N-1$ teams must be eliminated. Since each match eliminates exactly one team, the tournament must consist of exactly $N-1$ matches.

The problem asks if the tournament is "interesting," which is defined as having at least $M$ matches. Therefore, we simply need to check the condition:
$$(N - 1) \ge M$$

If this condition holds, the answer is `YES`; otherwise, it is `NO`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic comparison.
- **Space Complexity**: $O(1)$, as no additional data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In a knockout tournament with N teams, every match results in exactly one team being knocked out.
 * To declare a winner, N-1 teams must be knocked out.
 * Since each match eliminates exactly one team, the total number of matches played 
 * in any knockout tournament with N teams is always exactly N - 1.
 * 
 * The problem asks if it is possible for the tournament to be "interesting", 
 * meaning at least M matches are played.
 * Since the number of matches is fixed at N - 1, the condition is:
 * Is (N - 1) >= M?
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // The total number of matches in a knockout tournament with N teams is always N - 1.
        // We need to check if N - 1 >= M.
        if ((n - 1) >= m) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```