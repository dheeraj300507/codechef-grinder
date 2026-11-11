# [Special Missions (SPMISS)](https://www.codechef.com/problems/SPMISS)

- **Difficulty Rating**: 1026
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ missions, each providing $A_i$ coins. Missions are categorized as either "normal" ($S_i = '0'$) or "special" ($S_i = '1'$). Normal missions can be completed at any time. To complete any special missions, you must first pay a one-time fee of $C$ coins. This fee can only be paid if you have accumulated at least $C$ coins from missions completed *before* paying the fee. The goal is to maximize the total number of coins collected.

## Intuition & Mathematical Observation
The key constraint is that the fee $C$ must be paid using coins earned from missions completed *before* the special missions are unlocked. Since normal missions have no prerequisites, they are the only source of income available to reach the threshold $C$.

1.  **Normal Missions**: These are always available. Let `normal_sum` be the sum of $A_i$ for all $i$ where $S_i = '0'$.
2.  **Special Missions**: These are only available if we pay $C$. Let `special_sum` be the sum of $A_i$ for all $i$ where $S_i = '1'$.
3.  **Decision Logic**:
    *   If we do not unlock special missions, our total profit is simply `normal_sum`.
    *   If we choose to unlock special missions, we must have `normal_sum >= C`. If this condition is met, we can complete all normal missions, pay $C$, and then complete all special missions. The total profit becomes `normal_sum + special_sum - C`.
    *   If `normal_sum < C`, it is impossible to pay the fee, so we are restricted to only completing normal missions.

Thus, the maximum profit is `normal_sum + max(0, special_sum - C)` only if `normal_sum >= C`, otherwise it is just `normal_sum`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of missions. We iterate through the list of missions exactly once to calculate the sums.
- **Space Complexity**: $O(N)$ to store the mission values (or $O(1)$ if we process inputs on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We calculate the sum of all normal missions and all special missions.
 * To unlock special missions, we must have accumulated at least C coins 
 * from normal missions. If normal_sum >= C, we can unlock special missions 
 * and gain (normal_sum + special_sum - C). Otherwise, we only get normal_sum.
 */

void solve() {
    int N;
    long long C;
    cin >> N >> C;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    string S;
    cin >> S;

    long long normal_sum = 0;
    long long special_sum = 0;
    bool has_special = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            normal_sum += A[i];
        } else {
            special_sum += A[i];
            has_special = true;
        }
    }

    // If no special missions exist, profit is just normal_sum.
    // If they exist, check if we can afford the fee C using normal missions.
    if (!has_special) {
        cout << normal_sum << "\n";
    } else {
        if (normal_sum >= C) {
            // We can choose to unlock or not, but since special_sum could be 
            // negative or positive relative to C, we take the max.
            cout << max(normal_sum, normal_sum + special_sum - C) << "\n";
        } else {
            cout << normal_sum << "\n";
        }
    }
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