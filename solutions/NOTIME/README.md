# [No Time to Wait (NOTIME)](https://www.codechef.com/problems/NOTIME)

- **Difficulty Rating**: 932
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef needs a total of $H$ hours to solve a problem. He currently has $x$ hours remaining before the deadline. There are $N$ different time zones, and choosing the $i$-th time zone provides an additional $T_i$ hours. We need to determine if there exists at least one time zone $i$ such that the total time available ($x + T_i$) is greater than or equal to $H$.

## Intuition & Mathematical Observation
The problem asks whether there is any $T_i$ in the given set such that:
$$x + T_i \ge H$$

By rearranging the inequality, we can also look for:
$$T_i \ge H - x$$

Since we only need to find if *at least one* such time zone exists, we can iterate through all $N$ time zones. If we find any $T_i$ that satisfies the condition, we can immediately conclude that it is possible to solve the problem. If we check all $N$ time zones and none satisfy the condition, it is impossible.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of time zones. We perform a single pass through the input array.
- **Space Complexity**: $O(1)$, as we only store a few integer variables and do not need to store the entire array of time zones.

## Solution Code

```cpp
#include <iostream>
#include <vector>

/**
 * Problem Analysis:
 * Chef needs H hours. He has x hours.
 * He can choose one time zone T_i to gain T_i extra hours.
 * Total time available = x + T_i.
 * Condition to solve: x + T_i >= H.
 * 
 * Complexity:
 * Time: O(N) - We iterate through the N time zones once.
 * Space: O(1) - We only store the current T_i value.
 */

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H, x;
    if (!(cin >> N >> H >> x)) return 0;

    bool possible = false;
    for (int i = 0; i < N; ++i) {
        int T;
        cin >> T;
        // Check if this specific time zone allows Chef to meet the requirement
        if (x + T >= H) {
            possible = true;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
```