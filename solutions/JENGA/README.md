# [Jenga Night (JENGA)](https://www.codechef.com/problems/JENGA)

- **Difficulty Rating**: 613
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ people playing a game of Jenga with $X$ tiles. In each round, every person must take exactly one tile. We need to determine if it is possible to distribute all $X$ tiles such that every person receives an equal number of tiles across all rounds. In other words, we need to check if $X$ can be perfectly divided by $N$.

## Intuition & Mathematical Observation
For the game to be valid:
1. Every person must receive the same number of tiles.
2. All $X$ tiles must be used up.

If we let $k$ be the number of rounds played, then the total number of tiles used is $N \times k$. Therefore, for the game to be valid, $X$ must be equal to $N \times k$ for some positive integer $k$. This is mathematically equivalent to checking if $X$ is perfectly divisible by $N$, which can be expressed as:
$$X \pmod N = 0$$

If this condition holds, we output "YES"; otherwise, we output "NO".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time modulo operation, making the solution very efficient.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N people and X tiles.
 * In each round, every person takes 1 tile.
 * This means in one round, N tiles are consumed.
 * For the game to be valid:
 * 1. All tiles must be used (X must be divisible by N).
 * 2. All players must have a tile in each round (X must be >= N).
 * 
 * Combining these, the condition is simply:
 * (X % N == 0)
 * 
 * Constraints:
 * 1 <= T <= 10^4
 * 1 <= N, X <= 1000
 * Since N and X are small, standard integer types are sufficient.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x;
        cin >> n >> x;

        // The game is valid if the total number of tiles X is a multiple of N.
        // If X % N == 0, it implies X = k * N for some integer k >= 1.
        // This satisfies both conditions:
        // 1. All tiles are used (X / N rounds).
        // 2. Each round uses exactly N tiles, so everyone gets one.
        if (x % n == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```