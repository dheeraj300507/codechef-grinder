# [Winter is Coming (LMP2E)](https://www.codechef.com/problems/LMP2E)

- **Difficulty Rating**: 723
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to manage his jacket based on the daily temperature $T_i$. 
- Without a jacket, Chef is comfortable if $T_i \ge A$.
- With a jacket, Chef is comfortable if $T_i \le B$.
- If $T_i < A$, Chef **must** wear a jacket.
- If $T_i > B$, Chef **must** remove the jacket.
- If $A \le T_i \le B$, Chef can maintain their current state (either wearing or not wearing).

The goal is to calculate the minimum number of times Chef needs to put on a jacket throughout the $N$ days, starting from a state where he is not wearing one.

## Intuition & Mathematical Observation
This problem can be modeled as a state-machine problem. We track the state `wearing` (a boolean). 
1. **Forced State Changes**: 
   - If $T_i < A$, the temperature is too cold. If Chef is not wearing a jacket, he must put one on (`wear_count++`, `wearing = true`).
   - If $T_i > B$, the temperature is too hot. Chef must remove the jacket (`wearing = false`).
2. **Neutral State**: 
   - If $A \le T_i \le B$, the temperature is within the "buffer zone." Chef can stay in his current state, so no action is required.
3. **Greedy Approach**: Since we only care about the number of times he *puts on* a jacket, we only increment the counter when he transitions from `false` to `true`. Removing the jacket is free and mandatory when $T_i > B$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of days. We iterate through the temperature array exactly once.
- **Space Complexity**: $O(N)$ to store the temperatures (can be optimized to $O(1)$ by processing temperatures on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Chef is initially without a jacket.
 * - Without jacket: comfortable if T >= A.
 * - With jacket: comfortable if T <= B.
 * - If T < A, Chef MUST wear a jacket.
 * - If T > B, Chef MUST remove the jacket.
 * - If A <= T <= B, Chef can be either with or without a jacket.
 */

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    int wear_count = 0;
    bool wearing = false;

    for (int i = 0; i < N; ++i) {
        if (T[i] < A) {
            // Must wear jacket
            if (!wearing) {
                wear_count++;
                wearing = true;
            }
        } else if (T[i] > B) {
            // Must remove jacket
            wearing = false;
        } else {
            // A <= T[i] <= B
            // Chef can stay in current state, no action needed.
            continue;
        }
    }
    cout << wear_count << "\n";
}

int main() {
    // Fast I/O
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