# [Jumping in the hills (HILLS)](https://www.codechef.com/problems/HILLS)

- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is traveling across a series of $N$ hills with heights $H_1, H_2, \dots, H_N$. Starting at the first hill, he moves sequentially to the next hill ($i \to i+1$) based on specific rules:
1. **Equal height**: Always possible to move.
2. **Ascending**: Possible if the height difference $(H_{i+1} - H_i)$ is at most $U$.
3. **Descending**: 
    - Possible if the height difference $(H_i - H_{i+1})$ is at most $D$.
    - If the difference is greater than $D$, he can use a parachute **exactly once** to descend to any height.
    
The goal is to find the index (1-based) of the rightmost hill Chef can reach.

## Intuition & Mathematical Observation
Since the movement is strictly sequential ($i \to i+1$), this problem can be solved using a **Greedy approach**. We iterate through the hills and attempt to move to the next one as long as the conditions are met.

- We maintain a boolean flag `parachute_used` to track if the parachute has been utilized.
- For every step $i \to i+1$:
    - If $H_{i+1} == H_i$: Move forward.
    - If $H_{i+1} > H_i$: Check if the climb is within the limit $U$. If yes, move; otherwise, stop.
    - If $H_{i+1} < H_i$: 
        - If the drop is within limit $D$, move.
        - If the drop exceeds $D$, check if the parachute is available. If yes, use it and move; otherwise, stop.

Because we want to reach the furthest index, and there is no benefit to "saving" the parachute for later (as the constraints are local to the current jump), the greedy strategy is optimal.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of hills. We iterate through the array of hills exactly once.
- **Space Complexity**: $O(N)$ to store the heights of the hills. This can be optimized to $O(1)$ if we process the input on the fly, but $O(N)$ is well within limits for the given constraints.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts at index 1. He moves from i to i+1.
 * Conditions for moving from H[i] to H[i+1]:
 * 1. If H[i+1] == H[i]: Always possible.
 * 2. If H[i+1] > H[i]: Possible if H[i+1] - H[i] <= U.
 * 3. If H[i+1] < H[i]: 
 *    a. Possible if H[i] - H[i+1] <= D.
 *    b. If H[i] - H[i+1] > D, he can use a parachute (only once).
 */

void solve() {
    int N;
    long long U, D;
    cin >> N >> U >> D;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    bool parachute_used = false;
    int current_hill = 0; // 0-indexed

    for (int i = 0; i < N - 1; ++i) {
        if (H[i+1] == H[i]) {
            current_hill = i + 1;
        } else if (H[i+1] > H[i]) {
            if (H[i+1] - H[i] <= U) {
                current_hill = i + 1;
            } else {
                break;
            }
        } else { // H[i+1] < H[i]
            if (H[i] - H[i+1] <= D) {
                current_hill = i + 1;
            } else if (!parachute_used) {
                parachute_used = true;
                current_hill = i + 1;
            } else {
                break;
            }
        }
    }

    cout << current_hill + 1 << "\n";
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