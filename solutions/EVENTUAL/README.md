# [Even-tual Reduction (EVENTUAL)](https://www.codechef.com/problems/EVENTUAL)

- **Difficulty Rating**: 1040
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether it is possible to reduce a given string of length $N$ to an empty string by repeatedly removing substrings where every character within the chosen substring appears an even number of times.

## Intuition & Mathematical Observation
The core of the problem lies in the parity of character frequencies:

1.  **The Invariant**: Each operation removes a substring where every character appears an even number of times. This means that for any character $c$, the number of occurrences of $c$ removed in one operation is even.
2.  **Parity Preservation**: If we start with a string where a character $c$ appears an odd number of times, removing an even number of $c$'s will always leave an odd number of $c$'s remaining. Since an empty string has 0 occurrences of every character (which is even), it is impossible to reach an empty string if any character starts with an odd frequency.
3.  **Sufficiency**: If every character in the string appears an even number of times, we can simply choose the entire string as our substring. Since all frequencies are even, the condition is satisfied, and the entire string is removed in one operation.

**Conclusion**: The string can be reduced to an empty string if and only if every character in the string appears an even number of times.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies and then iterate through a fixed-size array of 26 characters.
- **Space Complexity**: $O(1)$, as we use a fixed-size frequency array of size 26 regardless of the input string length.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to remove a substring if every character in that substring 
 * appears an even number of times. 
 * 
 * If we can remove the entire string, it implies that every character in the 
 * original string must appear an even number of times. 
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Frequency array for lowercase English letters
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Check if all frequencies are even
    bool possible = true;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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