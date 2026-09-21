# [Advitiya (ADVITIYA1)](https://www.codechef.com/problems/ADVITIYA1)

- **Difficulty Rating**: 243
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $N$ (representing a date in February) falls within the range of the college fest, which occurs on the 16th, 17th, and 18th of February. If $N$ is 16, 17, or 18, we must output "ADVITIYA"; otherwise, we output "WAITING FOR ADVITIYA".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Since the fest dates are inclusive of 16, 17, and 18, we simply need to verify if the input $N$ satisfies the inequality:
$$16 \le N \le 18$$

If the condition is true, the fest is happening, and we print the required success message. If the condition is false, we print the waiting message.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of comparisons regardless of the input value.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: ADVITIYA1
 * The fest runs on the 16th, 17th, and 18th of February.
 * Given N (1 <= N <= 18), we need to check if N is 16, 17, or 18.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Check if the date is within the range [16, 18]
    if (n >= 16 && n <= 18) {
        cout << "ADVITIYA" << "\n";
    } else {
        cout << "WAITING FOR ADVITIYA" << "\n";
    }

    return 0;
}
```