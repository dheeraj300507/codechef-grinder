# [Podium Finish (PODIUM)](https://www.codechef.com/problems/PODIUM)

- **Difficulty Rating**: 341
- **Solved in**: 1 attempt(s)

## Problem Summary
In a race, Chef finishes in 3rd place. We are given two values:
*   **A**: The time gap between Chef (3rd) and the runner-up (2nd).
*   **B**: The time gap between the runner-up (2nd) and the winner (1st).

The objective is to calculate the total time gap between Chef (3rd) and the winner (1st).

## Intuition & Mathematical Observation
The problem describes a simple additive relationship. If the gap between 3rd and 2nd is $A$, and the gap between 2nd and 1st is $B$, the total time difference between 3rd and 1st is the sum of these two intervals:
$$\text{Total Gap} = A + B$$

Since the constraints are very small ($1 \le A, B \le 10$), the sum will never exceed 20, making it perfectly safe to use standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time addition operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Podium Finish
 * The problem asks for the total time gap between the Chef (3rd place) and the winner (1st place).
 * We are given:
 * A = Time gap between Chef and runner up (2nd place)
 * B = Time gap between runner up and winner
 * 
 * The total time gap between Chef and the winner is simply the sum of the two gaps: A + B.
 * 
 * Constraints: 1 <= T <= 100, 1 <= A, B <= 10.
 * The sum will not exceed 20, so standard 'int' is sufficient.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        // Calculate the total time gap
        int total_gap = a + b;
        
        // Output the result followed by a newline
        cout << total_gap << "\n";
    }

    return 0;
}
```