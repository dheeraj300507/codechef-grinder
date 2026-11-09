# [GAME 11 (GAME_XI)](https://www.codechef.com/problems/GAME_XI)

- **Difficulty Rating**: 1353
- **Solved in**: 2 attempt(s)

## Problem Summary
We are tasked with selecting a team of exactly 11 players from a pool of $N$ batsmen and $M$ bowlers. The selection must satisfy the following constraints:
1. At least 4 batsmen must be selected.
2. At least 4 bowlers must be selected.
3. The total number of players must be exactly 11.

Given the skill levels of all available batsmen and bowlers, the goal is to maximize the total skill sum of the selected 11 players. If it is impossible to form a valid team, output -1.

## Intuition & Mathematical Observation
Since we need exactly 11 players with at least 4 of each type, the possible distributions of (batsmen, bowlers) are:
- (4, 7)
- (5, 6)
- (6, 5)
- (7, 4)

To maximize the total skill for any fixed distribution $(b, w)$, we should always pick the $b$ batsmen with the highest skill levels and the $w$ bowlers with the highest skill levels.

**Approach:**
1. Sort both the batsmen array and the bowler array in descending order.
2. Precompute prefix sums for both arrays to allow $O(1)$ calculation of the sum of the top $k$ players.
3. Iterate through all valid combinations $(b, w)$ where $b \in [4, 7]$ and $w = 11 - b$.
4. Check if the current combination is feasible given the input sizes $N$ and $M$ (i.e., $b \le N$ and $w \le M$).
5. Track the maximum sum found across all valid combinations.

## Complexity Analysis
- **Time Complexity**: $O(N \log N + M \log M)$ per test case, primarily due to sorting the batsmen and bowler arrays. The iteration over the 4 possible combinations takes $O(1)$ time.
- **Space Complexity**: $O(N + M)$ to store the skill levels and the prefix sum arrays.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to select 11 players total.
 * Constraints:
 * - At least 4 batsmen (b)
 * - At least 4 bowlers (w)
 * - b + w = 11
 * 
 * Possible combinations (b, w):
 * (4, 7), (5, 6), (6, 5), (7, 4)
 * 
 * We must ensure b <= N and w <= M.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<long long> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];

    // Basic feasibility check
    if (N < 4 || M < 4 || (N + M) < 11) {
        cout << -1 << "\n";
        return;
    }

    // Sort descending to pick the best players
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    // Precompute prefix sums for O(1) range sum queries
    vector<long long> prefA(N + 1, 0), prefB(M + 1, 0);
    for (int i = 0; i < N; ++i) prefA[i + 1] = prefA[i] + A[i];
    for (int i = 0; i < M; ++i) prefB[i + 1] = prefB[i] + B[i];

    long long max_skill = -1;

    // Iterate through valid combinations (b, w)
    for (int b = 4; b <= 7; ++b) {
        int w = 11 - b;
        if (b <= N && w <= M) {
            long long current_skill = prefA[b] + prefB[w];
            if (max_skill == -1 || current_skill > max_skill) {
                max_skill = current_skill;
            }
        }
    }

    cout << max_skill << "\n";
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