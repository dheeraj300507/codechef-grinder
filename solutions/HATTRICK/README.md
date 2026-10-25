# [Hattrick (HATTRICK)](https://www.codechef.com/problems/HATTRICK)

- **Difficulty Rating**: 853
- **Solved in**: 1 attempt(s)

## Problem Summary
In a cricket match, a "hattrick" is defined as taking three wickets in three consecutive balls. Given a sequence of 6 balls, where each ball is represented by a string (either "W" for a wicket or another character for a different outcome), determine if a hattrick occurred. Specifically, we need to check if the string "W" appears three times consecutively in the given sequence of 6 inputs.

## Intuition & Mathematical Observation
The problem asks us to detect a specific pattern of length 3 within a sequence of length 6. 
- Since the sequence length is very small (fixed at 6), we can iterate through all possible starting positions where a sequence of 3 consecutive wickets could begin.
- A sequence of 3 consecutive elements in an array of size 6 can start at index 0, 1, 2, or 3.
- By checking the condition `s[i] == "W" && s[i+1] == "W" && s[i+2] == "W"` for each valid starting index `i`, we can determine if a hattrick exists. If any of these conditions evaluate to true, we output "YES"; otherwise, we output "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the number of balls is fixed at 6, the loop runs a constant number of times (4 iterations), making the execution time independent of input size.
- **Space Complexity**: $O(1)$. We only store 6 strings in an array, which requires a constant amount of memory regardless of the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HATTRICK
 * A hattrick occurs if there are three consecutive 'W's in the sequence of 6 balls.
 * We read the 6 inputs as strings and check for the patterns:
 * (W, W, W, x, x, x), (x, W, W, W, x, x), (x, x, W, W, W, x), or (x, x, x, W, W, W)
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string s[6];
        for (int i = 0; i < 6; ++i) {
            cin >> s[i];
        }

        bool hattrick = false;
        // Check for 3 consecutive Ws
        // Possible starting indices for a sequence of 3 are 0, 1, 2, 3
        for (int i = 0; i <= 3; ++i) {
            if (s[i] == "W" && s[i + 1] == "W" && s[i + 2] == "W") {
                hattrick = true;
                break;
            }
        }

        if (hattrick) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```