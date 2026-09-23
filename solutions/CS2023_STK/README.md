# [CodeChef Streak (CS2023_STK)](https://www.codechef.com/problems/CS2023_STK)

- **Difficulty Rating**: 1009
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to compare the "streaks" of two users, Om and Addy, over a period of $N$ days. A streak is defined as the maximum number of consecutive days a user has solved more than 0 problems. We are given the number of problems solved by each user for each of the $N$ days. We need to determine if Om has a longer streak, Addy has a longer streak, or if it is a draw.

## Intuition & Mathematical Observation
To solve this, we need to calculate the longest consecutive sequence of positive integers for both arrays independently. 

1. **Streak Calculation**: We can iterate through the array of problems. If the current day's count is greater than 0, we increment a `current_streak` counter. If the count is 0, the streak is broken; we update our `max_streak` if the `current_streak` is larger, and then reset `current_streak` to 0.
2. **Final Check**: After the loop finishes, it is crucial to perform one final `max` comparison, as the longest streak might end on the very last day of the period.
3. **Comparison**: Once we have `om_max` and `addy_max`, a simple conditional check determines the winner:
   - If `om_max > addy_max`, output "Om".
   - If `addy_max > om_max`, output "Addy".
   - Otherwise, output "Draw".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of days. We iterate through the input arrays exactly once for each user.
- **Space Complexity**: $O(N)$ to store the problem counts for both users. This could be optimized to $O(1)$ by processing the input on the fly, but $O(N)$ is well within the memory limits for this problem.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Function to calculate the maximum streak of days with > 0 problems solved.
 */
long long getMaxStreak(int n, const vector<long long>& problems) {
    long long max_streak = 0;
    long long current_streak = 0;
    for (int i = 0; i < n; ++i) {
        if (problems[i] > 0) {
            current_streak++;
        } else {
            max_streak = max(max_streak, current_streak);
            current_streak = 0;
        }
    }
    // Final check to account for a streak ending on the last day
    max_streak = max(max_streak, current_streak);
    return max_streak;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> om(n), addy(n);
    for (int i = 0; i < n; ++i) cin >> om[i];
    for (int i = 0; i < n; ++i) cin >> addy[i];

    long long om_max = getMaxStreak(n, om);
    long long addy_max = getMaxStreak(n, addy);

    if (om_max > addy_max) {
        cout << "Om" << endl;
    } else if (addy_max > om_max) {
        cout << "Addy" << endl;
    } else {
        cout << "Draw" << endl;
    }
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