# [Work Smarter, Not Harder (SMARTER)](https://www.codechef.com/problems/SMARTER)

- **Difficulty Rating**: 924
- **Solved in**: 1 attempt(s)

## Problem Summary
The tortoise and the hare are racing over a distance $L$. The tortoise moves at a constant speed $V_1$, and the hare moves at a constant speed $V_2$. The tortoise starts immediately. The hare can choose to wait for $w$ seconds before starting. We need to find the maximum integer $w$ such that the hare finishes the race strictly before the tortoise. If it is impossible for the hare to win, output -1.

## Intuition & Mathematical Observation

1.  **Tortoise Time ($T_t$):** Since the tortoise travels distance $L$ at speed $V_1$, the time taken is $L/V_1$. Because the problem implies discrete time steps or ceiling-based completion, we calculate this as $\lceil L/V_1 \rceil$. Using integer arithmetic, this is `(L + V_1 - 1) / V_1`.
2.  **Hare Time ($T_h$):** If the hare waits $w$ seconds, the hare starts at time $w$ and travels for $L/V_2$ seconds. The total time taken is $w + \lceil L/V_2 \rceil$. Let $T_{h\_base} = \lceil L/V_2 \rceil$, calculated as `(L + V_2 - 1) / V_2`.
3.  **Winning Condition:** The hare wins if their total time is strictly less than the tortoise's time:
    $$w + T_{h\_base} < T_t$$
4.  **Solving for $w$:**
    $$w < T_t - T_{h\_base}$$
    Since $w$ must be an integer, the maximum value is:
    $$w_{max} = T_t - T_{h\_base} - 1$$
5.  **Edge Case:** If $w_{max} < 0$, it means even with zero waiting time, the hare cannot finish strictly before the tortoise. In this case, we output -1.

## Complexity Analysis

- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and calculated times.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time: T_tortoise = ceil(L / V1)
 * Hare time: T_hare = w + ceil(L / V2)
 * Condition: w + ceil(L / V2) < ceil(L / V1)
 * w < ceil(L / V1) - ceil(L / V2)
 */

void solve() {
    long long L, V1, V2;
    cin >> L >> V1 >> V2;

    // Calculate tortoise time (rounded up)
    long long t_tortoise = (L + V1 - 1) / V1;
    
    // Calculate hare base time (rounded up)
    long long t_hare_base = (L + V2 - 1) / V2;

    // We need: w + t_hare_base < t_tortoise
    // Which is: w <= t_tortoise - t_hare_base - 1
    long long max_w = t_tortoise - t_hare_base - 1;

    if (max_w < 0) {
        cout << -1 << "\n";
    } else {
        cout << max_w << "\n";
    }
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