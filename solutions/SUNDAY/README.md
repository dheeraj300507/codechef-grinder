# [Count the Holidays (SUNDAY)](https://www.codechef.com/problems/SUNDAY)

- **Difficulty Rating**: 907
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a month consisting of 30 days, where the 1st day is a Monday. We need to calculate the total number of holidays in the month. Holidays include:
1. All Saturdays and Sundays.
2. A given set of $N$ festival days.

Since some festival days might fall on a weekend, we must ensure we only count each unique holiday day once.

## Intuition & Mathematical Observation
- The month has 30 days.
- Since the 1st is a Monday, we can determine the day of the week for any day $d$ using modulo arithmetic:
    - A day $d$ is a **Saturday** if $d \pmod 7 = 6$.
    - A day $d$ is a **Sunday** if $d \pmod 7 = 0$.
- The weekend days are $\{6, 13, 20, 27\}$ (Saturdays) and $\{7, 14, 21, 28\}$ (Sundays).
- To handle the "unique" requirement efficiently, we can use a boolean array (or a frequency array) of size 31. By marking indices as `true` when a day is a holiday, we avoid double-counting festival days that coincide with weekends.

## Complexity Analysis
- **Time Complexity**: $O(T \times (N + D))$, where $T$ is the number of test cases, $N$ is the number of festival days, and $D$ is the number of days in the month (constant 30). Given the constraints, this is effectively $O(T \times N)$.
- **Space Complexity**: $O(D)$, where $D=31$. This is $O(1)$ constant space as the size of the array does not depend on the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The month has 30 days.
 * Day 1 is Monday.
 * Days are numbered 1 to 30.
 * A day 'd' is a Saturday if d % 7 == 6.
 * A day 'd' is a Sunday if d % 7 == 0.
 * Holidays are:
 * 1. All Saturdays (6, 13, 20, 27)
 * 2. All Sundays (7, 14, 21, 28)
 * 3. Given festival days A_i.
 * 
 * We need to count the number of unique days that are holidays.
 * Using a boolean array of size 31 to mark holidays is efficient.
 */

void solve() {
    int n;
    cin >> n;
    
    // Use a boolean array to track holidays. 
    // Index 1 to 30 represents the days of the month.
    vector<bool> is_holiday(31, false);
    
    // Mark all Saturdays and Sundays as holidays
    // Saturday: 6, 13, 20, 27
    // Sunday: 7, 14, 21, 28
    for (int i = 1; i <= 30; ++i) {
        if (i % 7 == 6 || i % 7 == 0) {
            is_holiday[i] = true;
        }
    }
    
    // Mark festival days as holidays
    for (int i = 0; i < n; ++i) {
        int day;
        cin >> day;
        is_holiday[day] = true;
    }
    
    // Count total true values in the array
    int count = 0;
    for (int i = 1; i <= 30; ++i) {
        if (is_holiday[i]) {
            count++;
        }
    }
    
    cout << count << "\n";
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