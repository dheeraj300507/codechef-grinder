# [Chef and Linear Chess (LINCHESS)](https://www.codechef.com/problems/LINCHESS)

- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is positioned at coordinate $K$ on a linear board. There are $N$ other players, each starting at a position $P_i$. A player at $P_i$ can capture Chef if they can reach $K$ by making jumps of size $P_i$. This is possible if and only if $K$ is a multiple of $P_i$ (i.e., $K \pmod{P_i} == 0$). If multiple players can capture Chef, we need to find the one who reaches $K$ in the minimum number of moves. If no player can capture Chef, output -1.

## Intuition & Mathematical Observation
1. **Condition for Capture**: A player at $P_i$ can reach $K$ if $K$ is divisible by $P_i$.
2. **Calculating Moves**: If the condition is met, the number of moves required is exactly $\frac{K}{P_i}$.
3. **Optimization**: To minimize the number of moves ($\frac{K}{P_i}$), we must maximize the value of $P_i$. 
4. **Strategy**: Iterate through all given positions $P_i$. For each $P_i$, check if it is a divisor of $K$. Among all valid divisors, keep track of the one that results in the smallest quotient ($K/P_i$).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of players. Given $T$ test cases, the total time complexity is $O(T \times N)$. With $T \le 100$ and $N \le 1000$, the total operations are $\approx 10^5$, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only store a few variables to track the best player found so far, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at position K. A player at position P_i can capture Chef if K is a multiple of P_i.
 * That is, K % P_i == 0.
 * If this condition is met, the number of moves required is K / P_i.
 * We want to minimize the number of moves, which is equivalent to maximizing P_i 
 * among all P_i that satisfy K % P_i == 0.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;

    long long best_p = -1;
    long long min_moves = -1;

    for (int i = 0; i < N; ++i) {
        long long p;
        cin >> p;

        // Check if player can reach K
        if (K % p == 0) {
            long long moves = K / p;
            // We want the smallest number of moves.
            // If we haven't found a player yet, or this player is faster:
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
                best_p = p;
            }
        }
    }

    cout << best_p << "\n";
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