# [Permutation Construct (PERMCON)](https://www.codechef.com/problems/PERMCON)

- **Difficulty Rating**: 1166
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $K$, we need to construct a permutation $P$ of the set $\{1, 2, \dots, N\}$ such that:
1. $P[i] \neq i$ for all $1 \le i \le N$.
2. $P[i] \equiv i \pmod K$ for all $1 \le i \le N$.

If no such permutation exists, output $-1$.

## Intuition & Mathematical Observation
The condition $P[i] \equiv i \pmod K$ implies that each element $i$ must be mapped to another element $j$ that shares the same remainder when divided by $K$. 

1. **Grouping**: We can partition the set $\{1, 2, \dots, N\}$ into $K$ groups based on their values modulo $K$. Let $S_r = \{i \mid 1 \le i \le N, i \equiv r \pmod K\}$ for $r \in \{0, 1, \dots, K-1\}$.
2. **Constraint Analysis**: Within each group $S_r$, we must perform a permutation such that no element maps to itself. This is only possible if the size of the group $|S_r| \ge 2$. 
   - If any group has size 1, it is impossible to satisfy $P[i] \neq i$ because the only available element in that residue class is $i$ itself. In this case, we output $-1$.
3. **Construction**: If all non-empty groups have a size of at least 2, we can perform a simple cyclic shift within each group. If a group $S_r$ contains elements $\{a_1, a_2, \dots, a_m\}$, we set $P[a_1] = a_2, P[a_2] = a_3, \dots, P[a_m] = a_1$. This ensures that every element maps to a different element within the same residue class.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the size of the permutation. We iterate through the numbers from $1$ to $N$ once to group them and once more to construct the permutation.
- **Space Complexity**: $O(N)$ to store the groups and the resulting permutation array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation P of length N such that:
 * 1. P[i] != i (1-indexed)
 * 2. P[i] % K == i % K
 * 
 * The condition P[i] % K == i % K implies that P[i] must belong to the same 
 * residue class modulo K as i.
 */

void solve() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> groups(K);
    for (int i = 1; i <= N; ++i) {
        groups[i % K].push_back(i);
    }

    // Check if any group has size 1
    for (int i = 0; i < K; ++i) {
        if (groups[i].size() == 1) {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> P(N + 1);
    for (int i = 0; i < K; ++i) {
        int sz = groups[i].size();
        if (sz == 0) continue;
        
        // Cyclic shift: P[groups[i][j]] = groups[i][(j + 1) % sz]
        for (int j = 0; j < sz; ++j) {
            P[groups[i][j]] = groups[i][(j + 1) % sz];
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << P[i] << (i == N ? "" : " ");
    }
    cout << "\n";
}

int main() {
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