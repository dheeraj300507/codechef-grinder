# [Donation Rewards (DOREWARD)](https://www.codechef.com/problems/DOREWARD)

- **Difficulty Rating**: 395
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to categorize a donation amount $X$ into one of three reward tiers based on the following criteria:
- If the donation is 3 or less, the reward is **BRONZE**.
- If the donation is greater than 3 but 6 or less, the reward is **SILVER**.
- If the donation is greater than 6, the reward is **GOLD**.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. By observing the thresholds provided:
1. **BRONZE**: $X \le 3$
2. **SILVER**: $3 < X \le 6$
3. **GOLD**: $X > 6$

Since the conditions are mutually exclusive and cover all possible positive integers for $X$, we can use a simple `if-else if-else` ladder to determine the output for each test case.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input $X$ and do not allocate any additional data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: DOREWARD - Donation Rewards
 * Logic:
 * - If X <= 3: BRONZE
 * - If 3 < X <= 6: SILVER
 * - If X > 6: GOLD
 * 
 * Complexity:
 * - Time: O(T), where T is the number of test cases.
 * - Space: O(1), as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int x;
        cin >> x;

        if (x <= 3) {
            cout << "BRONZE" << "\n";
        } else if (x <= 6) {
            cout << "SILVER" << "\n";
        } else {
            cout << "GOLD" << "\n";
        }
    }

    return 0;
}
```