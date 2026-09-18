# [Qualify the round (QUALIFY)](https://www.codechef.com/problems/QUALIFY)

- **Difficulty Rating**: 594
- **Solved in**: 1 attempt(s)

## Problem Summary
In a coding contest, there are two types of problems:
*   **Easy problems**: Worth 1 point each.
*   **Hard problems**: Worth 2 points each.

Given the number of easy problems solved ($A$), the number of hard problems solved ($B$), and the minimum score required to qualify ($X$), determine if the participant qualifies for the next round. A participant qualifies if their total score is greater than or equal to $X$.

## Intuition & Mathematical Observation
The total score is calculated by summing the points from easy and hard problems:
$$\text{Total Score} = (A \times 1) + (B \times 2)$$

To determine if the participant qualifies, we simply compare the calculated `Total Score` against the threshold $X$:
*   If `Total Score` $\ge X$, output **"Qualify"**.
*   Otherwise, output **"NotQualify"**.

Since the constraints for $A, B,$ and $X$ are small ($\le 100$), the maximum possible score is $300$, which easily fits within standard integer data types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated score, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Easy problems = 1 point each
 * Hard problems = 2 points each
 * Total score = (A * 1) + (B * 2)
 * Qualification condition: Total score >= X
 * 
 * Constraints:
 * T <= 100
 * X, A, B <= 100
 * The maximum possible score is 100*1 + 100*2 = 300, which fits in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long x, a, b;
        cin >> x >> a >> b;

        // Calculate total score
        long long total_score = (a * 1) + (b * 2);

        // Check qualification condition
        if (total_score >= x) {
            cout << "Qualify" << "\n";
        } else {
            cout << "NotQualify" << "\n";
        }
    }

    return 0;
}
```