# [Healthy Sleep (HEALSE)](https://www.codechef.com/problems/HEALSE)

- **Difficulty Rating**: 250
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine the quality of sleep based on the number of hours ($H$) a person sleeps. The criteria are:
- If $H < 8$, the sleep is considered "LESS".
- If $H = 8$, the sleep is considered "PERFECT".
- If $H > 8$, the sleep is considered "MORE".

## Intuition & Mathematical Observation
This is a straightforward conditional logic problem. Since the input $H$ is a single integer, we can use simple `if-else` statements to compare $H$ against the threshold value of 8. 

- **Case 1 ($H < 8$):** The condition is strictly less than 8.
- **Case 2 ($H = 8$):** The condition is exactly equal to 8.
- **Case 3 ($H > 8$):** The condition is strictly greater than 8.

No complex mathematical formulas or data structures are required.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input value.
- **Space Complexity**: $O(1)$ — The solution uses a single integer variable to store the input, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Healthy Sleep
 * Logic:
 * - If H < 8, output LESS
 * - If H == 8, output PERFECT
 * - If H > 8, output MORE
 * 
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H;
    if (!(cin >> H)) return 0;

    if (H < 8) {
        cout << "LESS" << "\n";
    } else if (H == 8) {
        cout << "PERFECT" << "\n";
    } else {
        cout << "MORE" << "\n";
    }

    return 0;
}
```