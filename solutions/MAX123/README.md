# [Triplet Maximization (MAX123)](https://www.codechef.com/problems/MAX123)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ ones and $Y$ twos, we need to partition all $N = X + Y$ elements into $N/3$ groups of 3 elements each. For each group, the score is defined as the maximum element in that group. The goal is to maximize the total score of all groups combined.

## Intuition & Mathematical Observation
To maximize the total score, we want as many groups as possible to have a maximum value of $2$. 

1. **Group Capacity**: We have a total of $N = X + Y$ elements, which allows us to form $G = \lfloor (X + Y) / 3 \rfloor$ groups.
2. **Maximizing Score**: 
   - A group has a maximum of $2$ if it contains at least one $2$.
   - A group has a maximum of $1$ only if it contains three $1$s.
3. **Strategy**: Since each $2$ can "anchor" a group to have a maximum of $2$, we should use our $Y$ twos to form as many such groups as possible. 
   - We can form at most $Y$ groups that result in a score of $2$.
   - However, we are also constrained by the total number of groups available ($G$).
   - Therefore, the number of groups with a maximum of $2$ is $\min(Y, G)$.
   - The remaining groups, $G - \min(Y, G)$, will necessarily consist of $1$s and contribute $1$ to the score each.
4. **Calculation**: The total score is simply $(groups\_with\_2 \times 2) + (groups\_with\_1 \times 1)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the counts and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X ones and Y twos. Total elements N = X + Y.
 * We need to form N/3 groups of 3 elements each.
 * Each group contributes max(A_i, A_j, A_k) to the score.
 * 
 * Strategy:
 * 1. Total groups = (X + Y) / 3.
 * 2. Each '2' can make a group have a max of 2.
 * 3. Number of groups with max 2 = min(Y, total_groups).
 * 4. Remaining groups will have max 1.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    
    long long total_elements = X + Y;
    long long total_groups = total_elements / 3;
    
    // We want to maximize the number of groups that contain at least one '2'.
    long long groups_with_2 = min(Y, total_groups);
    long long groups_with_1 = total_groups - groups_with_2;
    
    long long score = (groups_with_2 * 2) + (groups_with_1 * 1);
    cout << score << "\n";
}

int main() {
    // Optimize I/O operations
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