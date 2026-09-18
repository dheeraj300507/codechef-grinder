# [Pending Assignments (ASSIGNMNT)](https://www.codechef.com/problems/ASSIGNMNT)

- **Difficulty Rating**: 468
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $X$ assignments, each taking $Y$ minutes to complete. Chef has $Z$ days to finish all of them. Given that there are 24 hours in a day and 60 minutes in an hour, determine if Chef can complete all assignments within the given time limit.

## Intuition & Mathematical Observation
To solve this problem, we need to compare the total time required to complete the assignments with the total time available:

1.  **Total Time Required**: Chef has $X$ assignments, and each takes $Y$ minutes. Therefore, the total time needed is $X \times Y$ minutes.
2.  **Total Time Available**: Chef has $Z$ days. Since each day has 24 hours and each hour has 60 minutes, the total time available in minutes is $Z \times 24 \times 60$.
3.  **Condition**: Chef can complete the assignments if the total time required is less than or equal to the total time available:
    $$(X \times Y) \le (Z \times 24 \times 60)$$

Given the constraints ($X, Y \le 100$ and $Z \le 10$), the maximum required time is $10,000$ minutes and the maximum available time is $14,400$ minutes. These values fit comfortably within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total time required to complete assignments = X * Y (in minutes).
 * Total time available in Z days = Z * 24 * 60 (in minutes).
 * Chef can complete the assignments if (X * Y) <= (Z * 24 * 60).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        long long total_required_minutes = x * y;
        long long total_available_minutes = z * 24 * 60;
        
        if (total_required_minutes <= total_available_minutes) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```