# [Chess Pairing (CHESS_PAIR)](https://www.codechef.com/problems/CHESS_PAIR)

- **Difficulty Rating**: 892
- **Solved in**: 1 attempt(s)

## Problem Summary
In a chess tournament with $2N$ total players, $X$ players are rated and $2N - X$ players are unrated. We want to form pairs such that the number of pairs consisting of two rated players is minimized. We need to find the minimum number of rated players who must be paired with another rated player.

## Intuition & Mathematical Observation
To minimize the number of rated-rated pairs, we should prioritize pairing rated players with unrated players.

1.  **Total Players**: $2N$
2.  **Rated Players**: $X$
3.  **Unrated Players**: $2N - X$

Each unrated player can "neutralize" one rated player by forming a (rated, unrated) pair. Since there are $2N - X$ unrated players, we can form at most $2N - X$ such pairs.

After using all available unrated players to pair with rated players, the number of rated players remaining is:
$$\text{Remaining Rated} = X - (2N - X) = 2X - 2N$$

*   If $2X - 2N \le 0$, it means we have enough unrated players to pair with every rated player (or there are no rated players left), so the number of rated-rated pairs is **0**.
*   If $2X - 2N > 0$, these remaining rated players have no unrated players left to pair with and must be paired with each other. Thus, the number of rated players involved in rated-rated pairings is exactly **$2X - 2N$**.

The final answer is simply $\max(0, 2X - 2N)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total players = 2N
 * Rated players = X
 * Unrated players = 2N - X
 * 
 * We want to pair rated players with unrated players as much as possible to minimize
 * the number of rated-rated pairs.
 * 
 * Each pair of (rated, unrated) uses 1 rated player and 1 unrated player.
 * We can form at most (2N - X) such pairs because there are only (2N - X) unrated players.
 * 
 * After using all (2N - X) unrated players, we have used (2N - X) rated players.
 * The remaining rated players are: X - (2N - X) = 2X - 2N.
 * 
 * If 2X - 2N <= 0, it means we can pair all rated players with unrated players 
 * (or there are no rated players left), so the answer is 0.
 * 
 * If 2X - 2N > 0, these remaining rated players must be paired with each other.
 * Thus, the answer is 2X - 2N.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        // Calculate remaining rated players after pairing with all unrated players
        long long remaining_rated = x - (2 * n - x);
        
        if (remaining_rated <= 0) {
            cout << 0 << "\n";
        } else {
            cout << remaining_rated << "\n";
        }
    }
    return 0;
}
```