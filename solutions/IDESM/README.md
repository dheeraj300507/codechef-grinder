# [The Ides of March (IDESM)](https://www.codechef.com/problems/IDESM)

- **Difficulty Rating**: 231
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $N$ (where $1 \le N \le 15$) is equal to 15. If $N$ is 15, we output "Yes"; otherwise, we output "No".

## Intuition & Mathematical Observation
The "Ides of March" historically refers to the 15th day of March. The problem is a straightforward conditional check. Since the input $N$ is constrained between 1 and 15, we simply need to verify if the input value matches the target constant 15. A simple `if-else` statement is sufficient to handle this logic.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a single constant-time comparison.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: The Ides of March
 * The problem asks to check if the given day N is 15.
 * Constraints: 1 <= N <= 15.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read the input N and compare it against 15
    if (cin >> N) {
        if (N == 15) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```