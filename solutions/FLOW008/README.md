# [Helping Chef (FLOW008)](https://www.codechef.com/problems/FLOW008)

- **Difficulty Rating**: 776
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to write a program that takes an integer $N$ as input. If the value of $N$ is strictly less than 10, the program should output the message "Thanks for helping Chef!". Otherwise, if $N$ is greater than or equal to 10, the program should output "-1". This process must be repeated for $T$ test cases.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Since the constraints on $N$ are small ($-20 \le N \le 20$), a simple `if-else` statement is sufficient to handle the logic:

1.  **Condition**: Check if $N < 10$.
2.  **True Case**: Print the required string: `"Thanks for helping Chef!"`.
3.  **False Case**: Print `-1`.

Using `long long` for $N$ is safe, though `int` would also suffice given the constraints. Fast I/O (`ios_base::sync_with_stdio(false); cin.tie(NULL);`) is used as a best practice to ensure the solution handles large numbers of test cases efficiently.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant time $O(1)$ operation for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not allocate any extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: FLOW008 - Helping Chef
 * Logic: If N < 10, print "Thanks for helping Chef!", else print "-1".
 * Constraints: -20 <= N <= 20. 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long n;
        cin >> n;

        if (n < 10) {
            cout << "Thanks for helping Chef!" << "\n";
        } else {
            cout << "-1" << "\n";
        }
    }

    return 0;
}
```