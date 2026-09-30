# [2 Boxes (BOX2)](https://www.codechef.com/problems/BOX2)

- **Difficulty Rating**: 832
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given two boxes containing $X$ and $Y$ stones respectively. In one move, you can move one stone from one box to the other. Your goal is to reach a state where the absolute difference between the number of stones in the two boxes is exactly $K$. Determine the minimum number of moves required to achieve this, or output -1 if it is impossible.

## Intuition & Mathematical Observation
Let $S = X + Y$ be the total number of stones, which remains constant throughout the process. Let $X'$ and $Y'$ be the number of stones in the boxes after some moves. We have:
1. $X' + Y' = S$
2. $|X' - Y'| = K$

From these, we can derive two possible target values for $X'$:
- If $X' - Y' = K$, then $X' - (S - X') = K \implies 2X' = S + K \implies X' = \frac{S + K}{2}$
- If $X' - Y' = -K$, then $X' - (S - X') = -K \implies 2X' = S - K \implies X' = \frac{S - K}{2}$

**Conditions for a valid solution:**
1. **Parity:** Since $X'$ must be an integer, $(S + K)$ must be even. This is equivalent to saying $S$ and $K$ must have the same parity (both even or both odd).
2. **Feasibility:** Since the number of stones cannot be negative, we must have $S \ge K$.

If these conditions are met, the number of moves required to reach a target $X'$ from the initial $X$ is simply $|X - X'|$. We calculate the moves for both possible targets and take the minimum.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate results.

## Solution Code

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

/**
 * Problem: BOX2
 * Approach:
 * Let S = X + Y. We want to reach a state where |X' - Y'| = K.
 * Since X' + Y' = S, we have:
 * X' - Y' = K  => 2X' = S + K => X' = (S + K) / 2
 * X' - Y' = -K => 2X' = S - K => X' = (S - K) / 2
 * 
 * For a solution to exist:
 * 1. (S + K) must be even (i.e., S and K have the same parity).
 * 2. S >= K (since stones cannot be negative).
 */

void solve() {
    long long X, Y, K;
    if (!(cin >> X >> Y >> K)) return;

    long long S = X + Y;

    // Check parity and feasibility
    if ((S + K) % 2 != 0 || S < K) {
        cout << -1 << endl;
        return;
    }

    // Target X' can be (S + K) / 2 or (S - K) / 2
    // We want to minimize |X - X'|
    long long target1 = (S + K) / 2;
    long long target2 = (S - K) / 2;

    long long ans = min(abs(X - target1), abs(X - target2));
    cout << ans << endl;
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