# [Monster Monster (KO_MON)](https://www.codechef.com/problems/KO_MON)

- **Difficulty Rating**: 1184
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ monsters, each with an initial health point (HP) $H_i$. Every day, we can choose one monster to attack. If our attack stat $A$ is greater than or equal to the current HP of the monster, we defeat it. However, after each day, the HP of all remaining monsters increases by $X$. We need to find the minimum attack stat $A$ required to defeat all $N$ monsters.

## Intuition & Mathematical Observation
To minimize the required attack stat $A$, we must consider the order in which we defeat the monsters. 

1. **Greedy Strategy**: If we leave a monster alive for more days, its HP increases by $X$ each day. Therefore, it is optimal to defeat the monsters with the highest HP first. If we sort the monsters in descending order of their initial HP ($H_1 \ge H_2 \ge \dots \ge H_N$), we ensure that the monsters that would have become the most difficult to kill later are removed as early as possible.
2. **Calculating Requirements**:
   - On day 0 (the first day), we kill the monster with the highest HP ($H_1$). We need $A \ge H_1$.
   - On day 1, we kill the second monster ($H_2$). It has been alive for 1 day, so its HP is now $H_2 + X$. We need $A \ge H_2 + X$.
   - On day $i$ (0-indexed), we kill the monster $H_{i+1}$. It has been alive for $i$ days, so its HP is $H_{i+1} + i \cdot X$. We need $A \ge H_{i+1} + i \cdot X$.
3. **Final Result**: The minimum attack stat $A$ must be sufficient to cover the "worst-case" requirement among all days. Thus, $A = \max_{0 \le i < N} (H_i + i \cdot X)$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. The subsequent linear scan takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the HP values of the monsters.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Strategy:
 * Sort monsters in descending order of HP. By killing the strongest monsters 
 * first, we prevent them from accumulating too much HP due to the daily 
 * increase X. The required attack stat A is the maximum of (H[i] + i * X) 
 * for all i from 0 to N-1.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // Sort in descending order to kill the strongest monsters first
    sort(H.begin(), H.end(), greater<long long>());

    long long max_A = 0;
    for (int i = 0; i < N; ++i) {
        // The i-th monster (0-indexed) will be killed on day i.
        // Its HP will be H[i] + i * X.
        long long required_A = H[i] + (long long)i * X;
        if (required_A > max_A) {
            max_A = required_A;
        }
    }

    cout << max_A << "\n";
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