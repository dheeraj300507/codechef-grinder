# [Thala For A Reason (THALA7)](https://www.codechef.com/problems/THALA7)

- **Difficulty Rating**: 235
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $N$ is equal to 7. If the input number is exactly 7, we must output "THALA". Otherwise, we must output "SADGE".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Since the condition is binary (either the number is 7 or it is not), we simply need to read the input integer and use an `if-else` statement to compare the value against 7. 

- If $N = 7$, print `THALA`.
- If $N \neq 7$, print `SADGE`.

No complex algorithms or data structures are required for this task.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and output operation, which takes constant time regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single variable to store the input, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: THALA7
 * Logic: Check if the input integer N is equal to 7.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        if (n == 7) {
            cout << "THALA" << "\n";
        } else {
            cout << "SADGE" << "\n";
        }
    }

    return 0;
}
```