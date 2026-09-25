# [Coin Flip (CONFLIP)](https://www.codechef.com/problems/CONFLIP)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ coins, all initially set to the same state (either all Heads or all Tails). We perform $N$ rounds of operations. In the $i$-th round (where $1 \le i \le N$), we flip all coins from position $1$ to $i$. After all $N$ rounds are completed, we need to determine how many coins are in a specific state (Heads or Tails) based on the input query.

## Intuition & Mathematical Observation
The key observation is to determine how many times each coin is flipped. 
- A coin at position $j$ (where $1 \le j \le N$) is flipped in every round $k$ where $k \ge j$.
- Therefore, the coin at position $j$ is flipped exactly $(N - j + 1)$ times.

**Parity Analysis:**
- If $(N - j + 1)$ is **even**, the coin returns to its initial state.
- If $(N - j + 1)$ is **odd**, the coin changes to the opposite state.

**Counting the flips:**
- Among the $N$ coins, exactly $\lfloor N/2 \rfloor$ coins will be flipped an odd number of times, and $\lceil N/2 \rceil$ coins will be flipped an even number of times.
- If $N$ is even, both counts are exactly $N/2$.
- If $N$ is odd, the number of coins flipped an odd number of times is $(N-1)/2$, and the number of coins flipped an even number of times is $(N+1)/2$.

**Logic for Queries:**
- If the initial state is Heads ($I=1$):
    - Coins flipped an odd number of times become Tails.
    - Coins flipped an even number of times remain Heads.
- If the initial state is Tails ($I=2$):
    - Coins flipped an odd number of times become Heads.
    - Coins flipped an even number of times remain Tails.

By comparing the initial state ($I$) and the requested state ($Q$), we can derive the answer using simple arithmetic without simulating the flips.

## Complexity Analysis
- **Time Complexity**: $O(T \times G)$, where $T$ is the number of test cases and $G$ is the number of games per test case. Since each game is solved in $O(1)$ time, the total complexity is linear relative to the number of queries.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the state and counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Coin i is flipped (N - i + 1) times.
 * If (N - i + 1) is odd, the coin flips. If even, it stays the same.
 * Total coins flipped odd times = N / 2.
 * Total coins flipped even times = N - (N / 2).
 */

void solve() {
    int G;
    cin >> G;
    while (G--) {
        long long I, N, Q;
        cin >> I >> N >> Q;

        long long heads, tails;
        if (N % 2 == 0) {
            // If N is even, exactly N/2 coins flip and N/2 stay.
            heads = N / 2;
            tails = N / 2;
        } else {
            // If N is odd, the distribution depends on the initial state.
            if (I == 1) {
                // Initial Heads: N/2 coins become Tails, (N/2 + 1) stay Heads.
                heads = N / 2 + 1;
                tails = N / 2;
            } else {
                // Initial Tails: N/2 coins become Heads, (N/2 + 1) stay Tails.
                heads = N / 2;
                tails = N / 2 + 1;
            }
        }

        if (Q == 1) {
            cout << heads << "\n";
        } else {
            cout << tails << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```