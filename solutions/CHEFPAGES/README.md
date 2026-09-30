# [Important Pages on CodeChef (CHEFPAGES)](https://www.codechef.com/problems/CHEFPAGES)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to direct a user to a specific CodeChef URL based on their activity status represented by two binary variables, $A$ and $B$:
- If $A = 0$, the user has not submitted on the practice page.
- If $A = 1$, the user has submitted on the practice page.
- If $B = 0$, the user has not submitted in a contest.
- If $B = 1$, the user has submitted in a contest.

The mapping is as follows:
1. If $A = 0$, output `https://www.codechef.com/practice`.
2. If $A = 1$ and $B = 0$, output `https://www.codechef.com/contests`.
3. If $A = 1$ and $B = 1$, output `https://discuss.codechef.com`.

## Intuition & Mathematical Observation
This is a straightforward conditional logic problem. Since the input space is very small ($A, B \in \{0, 1\}$), we can use simple `if-else` statements to map the input pairs $(A, B)$ to their corresponding URLs. 

- The condition $A=0$ is the highest priority (or the first check), as it covers all cases where the user hasn't practiced.
- If $A=1$, we then check $B$ to distinguish between the contest page and the discussion forum.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of comparisons.
- **Space Complexity**: $O(1)$, as we only store two integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A = 0: User has never submitted on the practice page. Output: https://www.codechef.com/practice
 * A = 1, B = 0: User has submitted on practice, but not in a contest. Output: https://www.codechef.com/contests
 * A = 1, B = 1: User has submitted on practice and in a contest. Output: https://discuss.codechef.com
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    // Read A and B from standard input
    if (cin >> A >> B) {
        if (A == 0) {
            cout << "https://www.codechef.com/practice" << "\n";
        } else if (A == 1 && B == 0) {
            cout << "https://www.codechef.com/contests" << "\n";
        } else if (A == 1 && B == 1) {
            cout << "https://discuss.codechef.com" << "\n";
        }
    }

    return 0;
}
```