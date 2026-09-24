# [Grade The Steel (FLOW014)](https://www.codechef.com/problems/FLOW014)

- **Difficulty Rating**: 838
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to grade a piece of steel based on three specific physical properties:
1. **Hardness** ($H$) must be greater than 50.
2. **Carbon content** ($C$) must be less than 0.7.
3. **Tensile strength** ($TS$) must be greater than 5600.

The grading system is determined by how many of these conditions are met:
- **Grade 10**: All three conditions are met.
- **Grade 9**: Conditions 1 and 2 are met.
- **Grade 8**: Conditions 2 and 3 are met.
- **Grade 7**: Conditions 1 and 3 are met.
- **Grade 6**: Only one of the conditions is met.
- **Grade 5**: None of the conditions are met.

## Intuition & Mathematical Observation
The problem can be solved using simple boolean logic. We define three boolean variables representing the truth value of each condition:
- `cond1 = (h > 50)`
- `cond2 = (c < 0.7)`
- `cond3 = (ts > 5600)`

By checking these conditions in a specific order (prioritizing the most restrictive grades first), we can determine the correct output. Since the problem specifies exact combinations for grades 10, 9, 8, and 7, we check those first. If none of those match, we check if exactly one condition is true (Grade 6) or if none are true (Grade 5).

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and boolean flags, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Grade The Steel
 * Logic:
 * Condition 1: Hardness > 50
 * Condition 2: Carbon < 0.7
 * Condition 3: Tensile > 5600
 * 
 * Grade 10: All 3 met
 * Grade 9: (1) and (2) met
 * Grade 8: (2) and (3) met
 * Grade 7: (1) and (3) met
 * Grade 6: Only 1 met
 * Grade 5: None met
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double h, c, ts;
        cin >> h >> c >> ts;

        bool cond1 = (h > 50);
        bool cond2 = (c < 0.7);
        bool cond3 = (ts > 5600);

        int count = (cond1 ? 1 : 0) + (cond2 ? 1 : 0) + (cond3 ? 1 : 0);

        if (cond1 && cond2 && cond3) {
            cout << 10 << "\n";
        } else if (cond1 && cond2) {
            cout << 9 << "\n";
        } else if (cond2 && cond3) {
            cout << 8 << "\n";
        } else if (cond1 && cond3) {
            cout << 7 << "\n";
        } else if (count == 1) {
            cout << 6 << "\n";
        } else {
            cout << 5 << "\n";
        }
    }

    return 0;
}
```