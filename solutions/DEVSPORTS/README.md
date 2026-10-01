# [Devendra and Water Sports (DEVSPORTS)](https://www.codechef.com/problems/DEVSPORTS)

- **Difficulty Rating**: 859
- **Solved in**: 2 attempt(s)

## Problem Summary
Devendra starts with an initial amount of money $Z$. He has already spent $Y$ amount on other activities. He wants to participate in three specific water sports that cost $A$, $B$, and $C$ respectively. We need to determine if he has enough remaining money to afford all three sports.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic comparison:
1. **Calculate Remaining Budget**: After spending $Y$ from his initial $Z$, Devendra has $Z - Y$ remaining.
2. **Calculate Total Cost**: The total cost for the three sports is the sum of their individual costs: $A + B + C$.
3. **Comparison**: Devendra can afford the sports if and only if his remaining budget is greater than or equal to the total cost of the sports.
   - Condition: $(Z - Y) \ge (A + B + C)$

If the condition holds, output `YES`; otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Devendra has Z total money and has already spent Y.
 * Remaining money = Z - Y.
 * He needs to spend A + B + C on sports.
 * Condition: (Z - Y) >= (A + B + C).
 * 
 * Constraints:
 * Z, Y, A, B, C fit within standard integer types (max 10^5).
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

void solve() {
    int Z, Y, A, B, C;
    if (!(cin >> Z >> Y >> A >> B >> C)) return;

    int remaining = Z - Y;
    int total_cost = A + B + C;

    if (remaining >= total_cost) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }

    return 0;
}
```