# [Cooling Conundrum (COOLCON)](https://www.codechef.com/problems/COOLCON)

- **Difficulty Rating**: 608
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the total time required to cool a dessert from an initial temperature $X$ down to a target temperature $Y$. For every single degree reduction (from $K$ to $K-1$), the time taken is defined as $\lceil K / 10 \rceil$. We need to sum these values for all steps from $X$ down to $Y+1$.

## Intuition & Mathematical Observation
- The cooling process happens in discrete steps. To go from $X$ to $Y$, we perform $(X - Y)$ individual steps.
- For a specific temperature $K$, the time taken to reach $K-1$ is $\lceil K / 10 \rceil$.
- In integer arithmetic, the ceiling function $\lceil K / 10 \rceil$ can be efficiently calculated as `(K + 9) / 10`.
- Since the constraints are small ($X \le 100$), a simple `for` loop iterating from $X$ down to $Y+1$ is perfectly efficient and avoids the need for complex mathematical formulas.

## Complexity Analysis
- **Time Complexity**: $O(T \times (X - Y))$, where $T$ is the number of test cases. Given $X \le 100$, the maximum number of operations is roughly $500,000$, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the temperatures and the running total.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks us to calculate the total time taken to cool a dessert from X to Y.
 * For each degree reduction from K to K-1, the time taken is ceil(K / 10.0).
 * In integer arithmetic, ceil(K / 10.0) is equivalent to (K + 9) / 10.
 * 
 * Constraints:
 * 1 <= T <= 5000
 * 1 <= Y < X <= 100
 * 
 * Since X is at most 100, a simple loop for each test case is highly efficient.
 * Total complexity per test case: O(X - Y), which is at most O(100).
 * Total complexity for T test cases: O(T * (X - Y)), which is at most 500,000 operations.
 * This easily fits within the 1s time limit.
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;

    long long total_time = 0;
    
    // Iterate from current temperature X down to Y+1
    // In each step, calculate the time to go from current_temp to current_temp - 1
    for (int current_temp = X; current_temp > Y; --current_temp) {
        // ceil(current_temp / 10.0)
        int time_for_step = (current_temp + 9) / 10;
        total_time += time_for_step;
    }
    
    cout << total_time << "\n";
}

int main() {
    // Fast I/O setup
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