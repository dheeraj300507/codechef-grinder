# [Chef and digits of a number (LONGSEQ)](https://www.codechef.com/problems/LONGSEQ)

- **Difficulty Rating**: 1209
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $D$ consisting only of '0's and '1's, determine if it is possible to make all digits in the string identical by flipping exactly one digit. A flip changes a '0' to a '1' or a '1' to a '0'.

## Intuition & Mathematical Observation
To make all digits in a string identical by flipping exactly one digit, the string must already be "almost" uniform. Specifically:

1.  **Case 1: Target all '1's.** If we want to reach a state where every digit is '1', the string must currently contain exactly one '0' and the rest must be '1's. Flipping that single '0' will result in a string of all '1's.
2.  **Case 2: Target all '0's.** If we want to reach a state where every digit is '0', the string must currently contain exactly one '1' and the rest must be '0's. Flipping that single '1' will result in a string of all '0's.

If the string contains more than one '0' and more than one '1', flipping a single digit will never result in a uniform string. Therefore, the condition is satisfied if and only if:
- `count0 == 1` AND `count1 == (total_length - 1)`
- OR `count1 == 1` AND `count0 == (total_length - 1)`

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once to count the occurrences of '0' and '1'.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if processed character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string D consisting of only '0's and '1's.
 * We want to make all digits the same by flipping exactly one digit.
 * 
 * The condition is satisfied if:
 * (count0 == 1 and count1 == total_length - 1) 
 * OR (count1 == 1 and count0 == total_length - 1).
 */

void solve() {
    string s;
    cin >> s;
    int count0 = 0;
    int count1 = 0;
    
    // Count occurrences of '0' and '1'
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }

    // Check if exactly one flip can make all digits equal
    if ((count0 == 1 && count1 == (int)s.length() - 1) || 
        (count1 == 1 && count0 == (int)s.length() - 1)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
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