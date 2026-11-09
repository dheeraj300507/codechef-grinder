# [Maximum Coins (MAXCOIN)](https://www.codechef.com/problems/MAXCOIN)

- **Difficulty Rating**: 951
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef plays $N$ games. In the $i$-th game, the prize is $2^i$ coins. If Chef wins, they gain $2^i$ coins; if they lose, they lose $2^i$ coins. Chef wins exactly $X$ games and loses $N-X$ games. The goal is to maximize the total number of coins Chef has after all $N$ games.

## Intuition & Mathematical Observation
To maximize the total coins, we need to assign the "win" status to the games with the highest values and the "lose" status to the games with the lowest values.

1.  **Strategy**: Since the value of the $i$-th game is $2^i$, the values grow exponentially. A game with a higher index $i$ is always worth more than the sum of all games with indices smaller than $i$. Therefore, to maximize the total, Chef should win the $X$ games with the largest indices ($N, N-1, \dots, N-X+1$) and lose the $N-X$ games with the smallest indices ($1, 2, \dots, N-X$).
2.  **Calculation**:
    *   Total Coins = $\sum_{i=N-X+1}^{N} 2^i - \sum_{i=1}^{N-X} 2^i$
3.  **Implementation Note**: Since $N$ is relatively small (typically up to 20-30 in such problems to fit in a 64-bit integer), we can use bitwise left-shift operators (`1LL << i`) to calculate $2^i$ efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from 1 to $N$ to calculate the sum. Given the constraints, this is highly efficient.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the sum and loop indices.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef wins X games and loses N-X games.
 * To maximize the total coins, Chef should win the games with the largest 
 * indices (N, N-1, ..., N-X+1) and lose the games with the smallest 
 * indices (1, 2, ..., N-X).
 */

void solve() {
    int N, X;
    if (!(cin >> N >> X)) return;

    long long total_coins = 0;

    // Chef wins games from N-X+1 to N
    // Chef loses games from 1 to N-X
    for (int i = 1; i <= N; ++i) {
        if (i > N - X) {
            // Win: Add 2^i
            total_coins += (1LL << i);
        } else {
            // Lose: Subtract 2^i
            total_coins -= (1LL << i);
        }
    }

    cout << total_coins << "\n";
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