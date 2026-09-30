# [Judged (ADVITIYA2)](https://www.codechef.com/problems/ADVITIYA2)

- **Difficulty Rating**: 453
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a participant qualifies for the next round based on the feedback from 5 judges. Each judge provides a score of either `0` (dislike) or `1` (like). A participant qualifies if they receive a "like" from at least 4 out of the 5 judges.

## Intuition & Mathematical Observation
The condition for qualification is straightforward: the sum of the scores given by the 5 judges must be greater than or equal to 4. 
- Let $S$ be the sum of the 5 judge responses $r_1, r_2, r_3, r_4, r_5$, where $r_i \in \{0, 1\}$.
- The participant qualifies if $S \ge 4$.
- If $S < 4$, the participant does not qualify.

Since the input size is fixed at 5 integers per test case, we can simply iterate through the inputs, maintain a running sum, and perform a conditional check.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of operations (5 additions and 1 comparison).
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the current sum and the input values, regardless of the number of test cases.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: ADVITIYA2
 * Logic: The participant qualifies if the sum of the 5 judge responses (0 or 1) 
 * is greater than or equal to 4.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only store a few integer variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            int r;
            cin >> r;
            sum += r;
        }

        // Check if at least 4 judges liked the performance
        if (sum >= 4) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```