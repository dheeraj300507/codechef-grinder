# [Fan Poll (FIZZBUZZ2301)](https://www.codechef.com/problems/FIZZBUZZ2301)

- **Difficulty Rating**: 273
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if Dhoni (represented by vote count $A$) received more votes than both Rohit (represented by $B$) and Kohli (represented by $C$). We are given that all three players received a distinct number of votes. If $A$ is strictly greater than both $B$ and $C$, we output "Yes"; otherwise, we output "No".

## Intuition & Mathematical Observation
Since the problem guarantees that no two players received the same number of votes, we do not need to worry about tie-breaking scenarios. The condition for Dhoni to win is straightforward:
- Dhoni wins if $A > B$ **AND** $A > C$.

This can be implemented using a simple conditional `if` statement. Because the input constraints are small and the logic is a direct comparison, this approach is optimal.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the three integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Fan Poll
 * Dhoni (A), Rohit (B), Kohli (C)
 * Dhoni wins if A > B and A > C.
 * Since it is guaranteed that no two players received the same number of votes,
 * we only need to check if A is strictly greater than B and C.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    // Read the three vote counts
    if (cin >> A >> B >> C) {
        // Check if Dhoni's votes (A) are greater than both Rohit's (B) and Kohli's (C)
        if (A > B && A > C) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```