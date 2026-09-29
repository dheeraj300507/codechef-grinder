# [Access Code Equality (WECNITK)](https://www.codechef.com/problems/WECNITK)

- **Difficulty Rating**: 355
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to verify if a given input string $S$ is exactly equal to the string `"WECNITK"`. If the input matches the target string exactly (case-sensitive), the program should output `"Welcome to Web Club!"`. Otherwise, it should output `"Access denied"`.

## Intuition & Mathematical Observation
The problem is a straightforward string comparison task. Since the target string `"WECNITK"` has a fixed length of 7 characters, the comparison operation is constant time $O(1)$. 

1. Read the input string from standard input.
2. Compare the input string with the literal `"WECNITK"`.
3. Use conditional logic (`if-else`) to print the required success or failure message based on the comparison result.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the string length is fixed and small (7 characters).
- **Space Complexity**: $O(1)$, as we only store a single string of fixed length.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: WECNITK - Access Code Equality
 * The task is to check if the input string S is exactly "WECNITK".
 * The problem specifies that the comparison is case-sensitive.
 * Time Complexity: O(1) per test case (string length is fixed at 7).
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the input string S
    string s;
    if (cin >> s) {
        // Perform case-sensitive comparison
        if (s == "WECNITK") {
            cout << "Welcome to Web Club!" << "\n";
        } else {
            cout << "Access denied" << "\n";
        }
    }

    return 0;
}
```