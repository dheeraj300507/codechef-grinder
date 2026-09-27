# [Football (MSNSADM1)](https://www.codechef.com/problems/MSNSADM1)

- **Difficulty Rating**: 1102
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are given the statistics of $N$ football players. For each player, we are provided with two values: the number of goals scored ($A_i$) and the number of fouls committed ($B_i$). The points for each player are calculated using the formula:
$$\text{Points} = (\text{Goals} \times 20) - (\text{Fouls} \times 10)$$
If the calculated points are negative, the player's score is considered to be $0$. The objective is to find the maximum score achieved by any player in the list.

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. Since we need to find the maximum score among $N$ players, we can iterate through each player, calculate their individual score based on the provided formula, and keep track of the highest score encountered so far.

**Key points:**
1. **Formula Application**: For each player $i$, calculate $P_i = (A_i \times 20) - (B_i \times 10)$.
2. **Constraint Handling**: Apply the condition $\max(0, P_i)$ to ensure no negative scores are considered.
3. **Global Maximum**: Maintain a variable `max_points` initialized to $0$ and update it whenever a higher score is calculated.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of players. We iterate through the list of goals and fouls exactly once. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the input arrays for goals and fouls. This can be further optimized to $O(1)$ if we process the input values on the fly without storing them in vectors.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each player i:
 * Points = (A[i] * 20) - (B[i] * 10)
 * If Points < 0, then Points = 0.
 * We need to find the maximum points among all players.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    vector<int> B(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    int max_points = 0;
    for (int i = 0; i < N; ++i) {
        int current_points = (A[i] * 20) - (B[i] * 10);
        // If points are negative, treat as 0
        if (current_points < 0) {
            current_points = 0;
        }
        // Update the maximum points found so far
        if (current_points > max_points) {
            max_points = current_points;
        }
    }
    
    cout << max_points << "\n";
}

int main() {
    // Fast I/O setup
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