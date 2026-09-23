# [Minimum Wage (MINWAGE)](https://www.codechef.com/problems/MINWAGE)

- **Difficulty Rating**: 247
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a given daily wage $X$ is sufficient to be considered a "minimum wage" according to Chef's criteria. Specifically, the condition for a wage to be acceptable is that it must be **strictly greater than 11**. If $X > 11$, we output "YES"; otherwise, we output "NO".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. 
- The threshold is defined as 11.
- The condition is strictly greater than ($>$), not greater than or equal to ($\ge$).
- Therefore, if the input $X$ is 11 or less, the condition fails. If $X$ is 12 or more, the condition passes.

This can be solved using a simple `if-else` statement in any programming language.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and a constant number of operations, regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the input wage
    if (!(cin >> X)) return 0;

    // The problem states the minimum wage is 11.
    // We need to check if X is strictly greater than 11.
    if (X > 11) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
```