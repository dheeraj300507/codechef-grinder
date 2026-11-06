# [Rock Paper Scissor (PASCRO)](https://www.codechef.com/problems/PASCRO)

- **Difficulty Rating**: 1226
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Chefina play a game of Rock, Paper, Scissors for $N$ rounds. We are given the moves made by both players. Chef wins if their move beats Chefina's move. We need to find the minimum number of rounds Chef needs to change their move so that their total score becomes strictly greater than Chefina's total score.

## Intuition & Mathematical Observation
Let $W$ be the number of rounds Chef wins, $L$ be the number of rounds Chefina wins, and $D$ be the number of draws. Chef's current score is $W$ and Chefina's score is $L$. We want to reach a state where $W_{new} > L_{new}$.

The current difference is $diff = W - L$. We need $diff > 0$.
1. **Changing a Loss ($L$):** If we change a round where Chefina won into a round where Chef wins, Chef's score increases by 1 and Chefina's score decreases by 1. The net change to the difference is $+2$.
2. **Changing a Draw ($D$):** If we change a round that was a draw into a round where Chef wins, Chef's score increases by 1. The net change to the difference is $+1$.

**Greedy Strategy:**
Since we want to minimize the number of changes, we should prioritize changing losses into wins because it provides a larger increase ($+2$) to the difference compared to changing draws ($+1$). We continue applying these changes until $W > L$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of rounds. We iterate through the strings once to count $W, L,$ and $D$, and the `while` loop runs at most $N$ times.
- **Space Complexity**: $O(N)$ to store the input strings $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has score C_score, Chefina has score B_score.
 * We want to find the minimum number of rounds to change such that C_score > B_score.
 * 
 * Strategy:
 * 1. Calculate initial W (Chef wins), L (Chefina wins), D (Draws).
 * 2. Current difference diff = W - L.
 * 3. While diff <= 0:
 *    - If L > 0, changing a loss to a win gives +2 to diff.
 *    - Else if D > 0, changing a draw to a win gives +1 to diff.
 *    - Increment count of changes.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int W = 0, L = 0, D = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == B[i]) {
            D++;
        } else if ((A[i] == 'R' && B[i] == 'S') || 
                   (A[i] == 'S' && B[i] == 'P') || 
                   (A[i] == 'P' && B[i] == 'R')) {
            W++;
        } else {
            L++;
        }
    }

    int diff = W - L;
    int changes = 0;

    while (diff <= 0) {
        if (L > 0) {
            diff += 2;
            L--;
            changes++;
        } else if (D > 0) {
            diff += 1;
            D--;
            changes++;
        } else {
            break;
        }
    }

    cout << changes << "\n";
}

int main() {
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