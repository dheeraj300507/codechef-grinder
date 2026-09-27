# [Chef and Lockout Draws (LOCKDRAW)](https://www.codechef.com/problems/LOCKDRAW)

- **Difficulty Rating**: 982
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and his opponent are competing in a contest with three problems worth $A$, $B$, and $C$ points respectively. For a "draw" to occur, the total points must be split such that both players receive an equal sum of points. Given the three point values, determine if it is possible for the two players to end in a draw.

## Intuition & Mathematical Observation
To achieve a draw, the total sum of points $S = A + B + C$ must be divisible by 2. If $S$ is odd, a draw is impossible. If $S$ is even, each player must receive exactly $S/2$ points.

Since there are only three problems, a player can receive points by solving one problem or two problems (solving all three is impossible for a draw unless one player gets zero, which isn't the case here). 

If a player solves a subset of problems that sums to $S/2$, the remaining problems will automatically sum to $S/2$ for the other player. This happens if:
1. One problem equals the sum of the other two (e.g., $A + B = C$).
2. This condition covers all scenarios where a subset sums to exactly half the total.

**Mathematical Logic:**
If $A + B = C$, then $A + B + C = 2C$, so $C = (A + B + C) / 2$. Thus, checking if any one value is the sum of the other two is sufficient to determine if a draw is possible.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three problems with points A, B, and C.
 * A draw occurs if the sum of points for one player equals the sum of points for the other.
 * Let the total sum be S = A + B + C.
 * For a draw to occur, one player must have S/2 points.
 * This is possible if any one of the problems is equal to the sum of the other two.
 */

void solve() {
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return;

    // Check if any single problem is equal to the sum of the other two.
    // This effectively checks if the total sum is even and can be split into two equal halves.
    if ((a + b == c) || (a + c == b) || (b + c == a)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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