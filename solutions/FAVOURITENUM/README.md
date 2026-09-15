# [Favourite Numbers (FAVOURITENUM)](https://www.codechef.com/problems/FAVOURITENUM)

- **Difficulty Rating**: 477
- **Solved in**: 2 attempt(s)

## Problem Summary
Alice and Bob have specific preferences for numbers:
- **Alice** likes a number $A$ if it is both **even** and a **multiple of 7**.
- **Bob** likes a number $A$ if it is both **odd** and a **multiple of 9**.
- If neither Alice nor Bob likes the number, **Charlie** takes it.

Given an integer $A$, determine who likes the number.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. We can translate the requirements directly into programming logic using the modulo operator (`%`):

1.  **Alice's Condition**: A number is even if `A % 2 == 0` and a multiple of 7 if `A % 7 == 0`. Both must be true.
2.  **Bob's Condition**: A number is odd if `A % 2 != 0` (or `A % 2 == 1`) and a multiple of 9 if `A % 9 == 0`. Both must be true.
3.  **Charlie's Condition**: If the input $A$ fails both of the above conditions, the output is "Charlie".

Since the conditions are mutually exclusive (a number cannot be both even and odd), we can use an `if-else if-else` structure to handle the logic efficiently.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not allocate any extra data structures.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: FAVOURITENUM
 * Approach:
 * 1. Read the integer A.
 * 2. Check Alice's condition: (A % 2 == 0) && (A % 7 == 0).
 * 3. Check Bob's condition: (A % 2 != 0) && (A % 9 == 0).
 * 4. If neither, output "Charlie".
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

void solve() {
    int a;
    cin >> a;
    
    // Alice likes numbers which are even, and are a multiple of 7.
    if (a % 2 == 0 && a % 7 == 0) {
        cout << "Alice" << "\n";
    }
    // Bob likes numbers which are odd, and are a multiple of 9.
    else if (a % 2 != 0 && a % 9 == 0) {
        cout << "Bob" << "\n";
    }
    // Otherwise, Charlie takes it home.
    else {
        cout << "Charlie" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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