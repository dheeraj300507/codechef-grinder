# [Blobby Volley Scores (BLOBBYVOLLEY)](https://www.codechef.com/problems/BLOBBYVOLLEY)

- **Difficulty Rating**: 962
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of Blobby Volley, Alice and Bob play a series of points. The rules for scoring and serving are as follows:
1. Alice starts as the initial server.
2. If the current server wins the point, they earn a point and remain the server for the next round.
3. If the current server loses the point, the winner of that point becomes the new server, and no score is awarded to anyone.

Given the sequence of point winners, we need to determine the final scores of Alice and Bob.

## Intuition & Mathematical Observation
The problem can be simulated directly by maintaining the state of the `current_server` and the scores of both players.

*   **State Tracking**: We initialize `current_server` to 'A' (Alice).
*   **Logic**:
    *   Iterate through the string $S$ where $S[i]$ represents the winner of the $i$-th point.
    *   If $S[i]$ matches the `current_server`, the server earns a point. We increment the score of the player corresponding to the `current_server`.
    *   If $S[i]$ does not match the `current_server`, the receiver has won the point. The receiver becomes the new `current_server`, and no scores are incremented.
*   **Efficiency**: Since we only need to iterate through the string once, this approach is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string $S$. We traverse the string exactly once.
- **Space Complexity**: $O(N)$ to store the input string. If the input were processed as a stream, this could be reduced to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Alice starts as the server.
 * - If the current server wins the point, their score increases by 1, and they remain the server.
 * - If the receiver wins the point, their score does not increase, but they become the server.
 * 
 * We can maintain a variable `current_server` ('A' or 'B') and update it based on the rules.
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long alice_score = 0;
    long long bob_score = 0;
    char current_server = 'A';

    for (int i = 0; i < N; ++i) {
        char winner = S[i];
        
        if (winner == current_server) {
            // Server wins the point
            if (winner == 'A') {
                alice_score++;
            } else {
                bob_score++;
            }
        } else {
            // Receiver wins the point, they become the new server
            current_server = winner;
        }
    }

    cout << alice_score << " " << bob_score << "\n";
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