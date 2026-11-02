# [Swish Game (SWISHGAME)](https://www.codechef.com/problems/SWISHGAME)

- **Difficulty Rating**: 1188
- **Solved in**: 2 attempt(s)

## Problem Summary
In the Swish Game, a player throws $N$ rings. We are given the results of the first $M$ throws as a string $S$ (where 'S' represents a swish and 'O' represents a miss). The game ends at the earliest moment the player either reaches $K$ swishes or it becomes mathematically impossible to reach $K$ swishes with the remaining throws. Given $M$, $K$, and the string $S$, we need to determine the total number of throws $N$ that occurred in the game.

## Intuition & Mathematical Observation
The game ends based on two conditions:

1.  **Condition 1: Success.** If the number of swishes in the first $M$ throws is already $\ge K$, the game ended exactly at $M$ throws because the goal was achieved. Thus, $N = M$.
2.  **Condition 2: Failure.** If the number of swishes in the first $M$ throws is less than $K$, the game continues until it is impossible to reach $K$ swishes. Let the current number of swishes be `swishes`. The number of remaining throws is $(N - M)$. Even if every remaining throw were a swish, the total would be `swishes + (N - M)`. The game ends the moment this sum is strictly less than $K$. 
    *   The threshold for ending is when `swishes + (N - M) = K - 1`.
    *   Rearranging for $N$: $N = M + K - \text{swishes} - 1$.

## Complexity Analysis
- **Time Complexity**: $O(M)$ per test case, where $M$ is the length of the string $S$. We iterate through the string once to count the swishes.
- **Space Complexity**: $O(M)$ to store the input string $S$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Logic:
 * 1. If the total swishes in S >= K, the game ended because he reached K swishes.
 *    Therefore, N = M.
 * 2. If the total swishes in S < K, the game ended because it became impossible
 *    to reach K swishes.
 *    The game ends at move N if: (swishes_at_M) + (N - M) < K.
 *    The smallest N satisfying this is N = M + K - swishes_at_M - 1.
 */

void solve() {
    int M, K;
    cin >> M >> K;
    string S;
    cin >> S;

    int swishes = 0;
    for (char c : S) {
        if (c == 'S') swishes++;
    }

    if (swishes >= K) {
        // Goal reached at exactly M throws
        cout << M << "\n";
    } else {
        // Goal impossible to reach: 
        // swishes + (N - M) = K - 1
        // N = M + K - swishes - 1
        cout << M + K - swishes - 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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