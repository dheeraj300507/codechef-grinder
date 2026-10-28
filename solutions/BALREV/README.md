# [Balanced Reversals (BALREV)](https://www.codechef.com/problems/BALREV)

- **Difficulty Rating**: 1165
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we are allowed to reverse any substring that contains an equal number of '0's and '1's. The goal is to find the lexicographically smallest string possible after performing any number of such operations.

## Intuition & Mathematical Observation
The key observation is that the allowed operation (reversing a balanced substring) is powerful enough to rearrange the characters of the string into any order that preserves the total count of '0's and '1's. 

Specifically, if a substring has an equal number of '0's and '1's, reversing it allows us to change the relative positions of these characters. By repeatedly applying this operation, we can effectively bubble all '0's to the front of the string and all '1's to the back. 

Since the lexicographically smallest binary string is always the one where all '0's appear before all '1's (e.g., `000111`), the problem reduces to simply counting the total number of '0's and '1's in the input string and reconstructing the string in the format:
`[count0 times '0']` + `[count1 times '1']`.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count the characters and then construct the result string.
- **Space Complexity**: $O(N)$ to store the input string and the resulting output string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to reverse any substring that has an equal number of 0s and 1s.
 * This implies we can effectively sort the string such that all 0s come before all 1s.
 * The lexicographically smallest string for a binary string is simply the string 
 * with all its 0s followed by all its 1s.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int count0 = 0;
    int count1 = 0;

    // Count the occurrences of '0' and '1'
    for (char c : A) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    // The lexicographically smallest string is all 0s followed by all 1s.
    string result = "";
    for (int i = 0; i < count0; ++i) {
        result += '0';
    }
    for (int i = 0; i < count1; ++i) {
        result += '1';
    }

    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```