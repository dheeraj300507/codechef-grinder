# [Chef And Salary Pay (HCAGMAM1)](https://www.codechef.com/problems/HCAGMAM1)

- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef works for 30 days. We are given a binary string $S$ of length 30, where '1' represents a working day and '0' represents a leave day. The salary is calculated as:
$$\text{Salary} = (\text{Total number of '1's} \times X) + (\text{Length of the longest consecutive streak of '1's} \times Y)$$
Given $X$ (pay per working day) and $Y$ (bonus per longest streak), we need to calculate the total salary.

## Intuition & Mathematical Observation
Since the string length is fixed at 30, we can process the string in a single linear pass:
1. **Total Working Days**: Simply count the total occurrences of '1' in the string.
2. **Longest Streak**: Maintain a `current_streak` counter that increments when we encounter a '1' and resets to 0 when we encounter a '0'. We keep track of the maximum value this counter reaches throughout the iteration.
3. **Edge Case**: Ensure that if the string ends with a streak of '1's, the final `current_streak` is compared against the `max_streak` after the loop finishes.

The constraints are small ($T \le 10^4$, $|S| = 30$), making this $O(N)$ approach highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(T \times |S|)$, where $T$ is the number of test cases and $|S|$ is the length of the string (30). This results in approximately $3 \times 10^5$ operations, well within the 0.5s time limit.
- **Space Complexity**: $O(|S|)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We are given a binary string of length 30.
 * - '1' represents a working day, '0' represents a leave day.
 * - Salary = (Total number of '1's * X) + (Length of longest consecutive '1's * Y).
 * - Constraints: T <= 10^4, X, Y <= 999, |S| = 30.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    string s;
    cin >> s;

    long long total_working_days = 0;
    long long max_streak = 0;
    long long current_streak = 0;

    for (char c : s) {
        if (c == '1') {
            total_working_days++;
            current_streak++;
        } else {
            // Update max_streak when a streak of '1's is broken
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 0;
        }
    }
    // Final check in case the string ends with a streak
    if (current_streak > max_streak) {
        max_streak = current_streak;
    }

    long long salary = (total_working_days * X) + (max_streak * Y);
    cout << salary << "\n";
}

int main() {
    // Fast I/O setup
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