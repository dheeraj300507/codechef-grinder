# [Rearranging digits to get a multiple of 5 (DIGARR)](https://www.codechef.com/problems/DIGARR)

- **Difficulty Rating**: 949
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a number $N$ represented as a string of $D$ digits, determine if it is possible to rearrange the digits of $N$ to form a number that is a multiple of 5.

## Intuition & Mathematical Observation
A fundamental property of arithmetic is that any integer is a multiple of 5 if and only if its last digit is either **0** or **5**. 

Since we are allowed to rearrange the digits of the given number $N$ in any order we choose, we do not need to perform complex permutations. We simply need to check if the set of digits provided contains at least one '0' or at least one '5'. If such a digit exists, we can move it to the last position, thereby ensuring the resulting number is divisible by 5. If neither digit exists, it is mathematically impossible to form a multiple of 5.

## Complexity Analysis
- **Time Complexity**: $O(D)$ per test case, where $D$ is the number of digits in the string. We iterate through the string exactly once.
- **Space Complexity**: $O(D)$ to store the input string $N$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * A number is a multiple of 5 if and only if its last digit is 0 or 5.
 * By rearranging the digits of N, we can place any digit at the end.
 * Therefore, if the string N contains at least one '0' or at least one '5',
 * we can always form a multiple of 5.
 */

void solve() {
    int D;
    if (!(cin >> D)) return;
    string N;
    cin >> N;

    bool found = false;
    // Check if any digit in the string is '0' or '5'
    for (char c : N) {
        if (c == '0' || c == '5') {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```