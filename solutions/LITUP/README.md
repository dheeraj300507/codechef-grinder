# [Lit Up (LITUP)](https://www.codechef.com/problems/LITUP)

- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ stalls arranged in a line, each with an associated cost $C_i$ to place a floodlight there. A floodlight placed at position $p$ illuminates all stalls in the range $[\max(1, p-K), \min(N, p+K)]$. We need to select exactly two distinct positions $i$ and $j$ to place floodlights such that every stall from $1$ to $N$ is illuminated. The goal is to minimize the total cost $C_i + C_j$. If it is impossible to cover all stalls, we output -1.

## Intuition & Mathematical Observation
Since the number of stalls $N$ is small ($N \le 100$), we can use a brute-force approach to check every possible pair of positions $(i, j)$.

1. **Range Calculation**: For any position $p$, the range covered is $[L_p, R_p] = [\max(1, p-K), \min(N, p+K)]$.
2. **Union Condition**: Two intervals $[s_1, e_1]$ and $[s_2, e_2]$ (where $s_1 \le s_2$) cover the entire range $[1, N]$ if and only if:
   - The start of the first interval is $1$ ($s_1 = 1$).
   - The end of the second interval is $N$ ($e_2 = N$).
   - The intervals overlap or touch, meaning the start of the second interval is at most one greater than the end of the first ($s_2 \le e_1 + 1$).
3. **Optimization**: By iterating through all pairs $(i, j)$ where $1 \le i < j \le N$, we calculate the cost for every valid configuration and track the minimum.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the number of stalls. Given $N \le 100$, $N^2 = 10,000$, which easily fits within the time limit for typical competitive programming constraints.
- **Space Complexity**: $O(N)$ to store the costs of the stalls.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N stalls and need to place exactly two floodlights at distinct positions i and j.
 * A light at position p covers stalls [max(1, p-K), min(N, p+K)].
 * Since N is small (up to 100), we iterate over all pairs (i, j) with 1 <= i < j <= N.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> C(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> C[i];
    }

    long long min_cost = -1;

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            // Calculate ranges for both lights
            int start1 = max(1, i - K);
            int end1 = min(N, i + K);
            int start2 = max(1, j - K);
            int end2 = min(N, j + K);
            
            int s1 = start1, e1 = end1;
            int s2 = start2, e2 = end2;
            
            // Ensure s1 <= s2 for easier interval comparison
            if (s1 > s2) {
                swap(s1, s2);
                swap(e1, e2);
            }
            
            // Condition: 
            // 1. The union starts at 1 (s1 == 1)
            // 2. The union ends at N (e2 == N)
            // 3. The intervals are connected (s2 <= e1 + 1)
            if (s1 == 1 && e2 == N && s2 <= e1 + 1) {
                long long current_cost = (long long)C[i] + C[j];
                if (min_cost == -1 || current_cost < min_cost) {
                    min_cost = current_cost;
                }
            }
        }
    }

    cout << min_cost << "\n";
}

int main() {
    // Optimize I/O operations
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