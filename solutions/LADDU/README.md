# [Laddu (LADDU)](https://www.codechef.com/problems/LADDU)

- **Difficulty Rating**: 1241
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the total number of "laddus" a user has earned based on their activity history on a platform. Depending on whether the user is from "INDIAN" or "NON_INDIAN", the redemption rate differs (200 laddus per month for Indians, 400 for non-Indians). We need to output the maximum number of months the user can redeem their laddus for.

## Intuition & Mathematical Observation
1. **Activity Parsing**: Each activity has a specific point value:
   - `CONTEST_WON`: 300 points + bonus (20 - rank) if rank < 20.
   - `TOP_CONTRIBUTOR`: 300 points.
   - `BUG_FOUND`: Points equal to the severity of the bug.
   - `CONTEST_HOSTED`: 50 points.
2. **Redemption Logic**: Since we want the total number of months, we simply perform integer division of the `total_laddus` by the `threshold` (200 or 400).
3. **Data Types**: While the constraints are small enough for `int`, using `long long` for the accumulator is a robust practice to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the total number of activities across all test cases. We iterate through each activity exactly once.
- **Space Complexity**: $O(1)$, as we only store a few variables to track the running total and current activity details, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LADDU
 * Approach:
 * 1. Calculate the total number of laddus earned by parsing each activity.
 * 2. Determine the redemption threshold based on the user's origin (INDIAN: 200, NON_INDIAN: 400).
 * 3. The number of months the user can redeem is total_laddus / threshold.
 */

void solve() {
    int activities;
    string origin;
    cin >> activities >> origin;

    long long total_laddus = 0;

    for (int i = 0; i < activities; ++i) {
        string type;
        cin >> type;
        if (type == "CONTEST_WON") {
            int rank;
            cin >> rank;
            total_laddus += 300;
            if (rank < 20) {
                total_laddus += (20 - rank);
            }
        } else if (type == "TOP_CONTRIBUTOR") {
            total_laddus += 300;
        } else if (type == "BUG_FOUND") {
            int severity;
            cin >> severity;
            total_laddus += severity;
        } else if (type == "CONTEST_HOSTED") {
            total_laddus += 50;
        }
    }

    int threshold = (origin == "INDIAN") ? 200 : 400;
    cout << total_laddus / threshold << "\n";
}

int main() {
    // Fast I/O
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