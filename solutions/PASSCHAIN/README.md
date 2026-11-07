# [Passing Chain (PASSCHAIN)](https://www.codechef.com/problems/PASSCHAIN)

- **Difficulty Rating**: 570
- **Solved in**: 2 attempt(s)

## Problem Summary
In this problem, we have $N$ players standing in a line, numbered from $1$ to $N$. A ball starts at player $1$. In each step, the ball is passed from the current player to the player $K$ positions ahead. This process continues as long as the next player's index does not exceed $N$. We need to determine the index of the player who holds the ball at the end of this process.

## Intuition & Mathematical Observation
The problem describes a simple iterative process. Since we start at $1$ and add $K$ repeatedly, the position of the ball after $m$ passes is $1 + (m \times K)$. 

We want to find the largest integer $m$ such that:
$$1 + (m \times K) \le N$$

While this can be solved using the formula $1 + \lfloor \frac{N-1}{K} \rfloor \times K$, the constraints ($N, K \le 50$) are small enough that a direct simulation using a `while` loop is highly efficient and less prone to off-by-one errors. We simply keep adding $K$ to our current position until adding $K$ one more time would exceed $N$.

## Complexity Analysis
- **Time Complexity**: $O(\frac{N}{K})$ per test case. Given $T$ test cases, the total time complexity is $O(T \times \frac{N}{K})$. With $N, K \le 50$ and $T = 2500$, the total operations are well within the $10^8$ operations per second limit.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the current position and input values.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We start at player 1.
 * While current_player + K <= N:
 *     current_player = current_player + K
 * The final value of current_player is the answer.
 * 
 * Constraints: N, K <= 50. The simulation will run at most 50 times,
 * which is O(N/K) per test case. With T=2500, this is well within limits.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    int current_player = 1;
    
    // Simulate the passing chain
    // Keep passing the ball as long as the next player is within range N
    while (current_player + K <= N) {
        current_player += K;
    }
    
    cout << current_player << endl;
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```