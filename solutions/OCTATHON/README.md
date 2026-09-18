# [October Marathon (OCTATHON)](https://www.codechef.com/problems/OCTATHON)

- **Difficulty Rating**: 319
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to categorize a runner based on their finishing time $X$ (in hours) in the October Marathon:
- If the time $X$ is strictly less than 3 hours, the runner receives **GOLD**.
- If the time $X$ is at least 3 hours but strictly less than 6 hours, the runner receives **SILVER**.
- If the time $X$ is 6 hours or more, the runner receives **BRONZE**.

## Intuition & Mathematical Observation
The problem is a straightforward conditional logic task. We can map the given ranges directly to `if-else` statements:
1. **Condition 1**: $X < 3 \implies$ "GOLD"
2. **Condition 2**: $3 \le X < 6 \implies$ "SILVER"
3. **Condition 3**: $X \ge 6 \implies$ "BRONZE"

Since the conditions are mutually exclusive and cover all possible values of $X$, we can simplify the logic by checking the conditions sequentially. If $X < 3$ is false, we know $X \ge 3$, so we only need to check if $X < 6$ to determine if it is "SILVER". If both are false, it defaults to "BRONZE".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution performs a constant number of comparisons regardless of the input value.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: October Marathon
 * Logic:
 * - If X < 3: GOLD
 * - If 3 <= X < 6: SILVER
 * - If X >= 6: BRONZE
 * 
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    if (X < 3) {
        cout << "GOLD" << "\n";
    } else if (X < 6) {
        cout << "SILVER" << "\n";
    } else {
        cout << "BRONZE" << "\n";
    }

    return 0;
}
```