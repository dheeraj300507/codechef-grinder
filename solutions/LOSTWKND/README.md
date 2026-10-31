# [Lost Weekends (LOSTWKND)](https://www.codechef.com/problems/LOSTWKND)

- **Difficulty Rating**: 1063
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef works for 5 days a week. For each day $i$, he has $A_i$ hours of work to complete. Each hour of office work requires $P$ hours of effort at home. We need to determine if the total effort required for the week exceeds the total available hours in the 5 weekdays (which is $5 \times 24 = 120$ hours). If the total effort exceeds 120 hours, Chef must work on the weekend; otherwise, he does not.

## Intuition & Mathematical Observation
1. **Calculate Total Effort**: The total work in terms of office hours is the sum of hours spent each day: $S = A_1 + A_2 + A_3 + A_4 + A_5$.
2. **Convert to Home Effort**: Since each office hour equals $P$ home hours, the total effort required is $Total = S \times P$.
3. **Compare with Capacity**: The total time available during the 5 weekdays is $5 \times 24 = 120$ hours.
4. **Decision Logic**:
   - If $Total > 120$, Chef cannot finish within the weekdays, so output `"Yes"`.
   - If $Total \le 120$, Chef can finish within the weekdays, so output `"No"`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 5 weekdays. For each day i, he has A_i hours of work to do at the office.
 * 1 hour of office work = P hours of work at home.
 * Total work required at home for the week = (A1 + A2 + A3 + A4 + A5) * P.
 * There are 5 weekdays, and each day has 24 hours.
 * Total available hours in 5 weekdays = 5 * 24 = 120 hours.
 * 
 * If the total work required at home exceeds 120 hours, Chef must work on the weekend.
 * Otherwise, he can complete the work within the 5 weekdays.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a1, a2, a3, a4, a5, p;
        cin >> a1 >> a2 >> a3 >> a4 >> a5 >> p;
        
        long long total_work_hours = (a1 + a2 + a3 + a4 + a5) * p;
        long long total_available_hours = 5 * 24;
        
        // If total work required is greater than available hours, he must work on weekends.
        if (total_work_hours > total_available_hours) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```