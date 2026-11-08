# [Spell Shortening (SHORTSPELL)](https://www.codechef.com/problems/SHORTSPELL)

- **Difficulty Rating**: 1192
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$, we are required to delete exactly one character such that the resulting string of length $N-1$ is lexicographically as small as possible.

## Intuition & Mathematical Observation
To make a string lexicographically smallest, we want the first character that differs from the original sequence to be as small as possible. 

Consider the string as a sequence of characters. If we compare adjacent characters $S[i]$ and $S[i+1]$:
1. If $S[i] > S[i+1]$, removing $S[i]$ causes $S[i+1]$ to shift into the $i$-th position. Since $S[i+1] < S[i]$, the resulting string will be lexicographically smaller than the original string at index $i$. This is the optimal move because it improves the string at the earliest possible position.
2. If no such index $i$ exists (i.e., the string is non-decreasing, like "aabbc"), the best strategy is to remove the very last character. Removing any character before the end would result in a larger character shifting into a position previously occupied by a smaller or equal character.

**Strategy:**
- Iterate through the string and find the first index $i$ where $S[i] > S[i+1]$.
- If found, delete $S[i]$.
- If the loop finishes without finding such an index, delete the last character ($S[N-1]$).

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass to find the index and another pass to print the result.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to delete exactly one character from a string S of length N to make the 
 * resulting string of length N-1 lexicographically as small as possible.
 * 
 * To make a string lexicographically smallest, we want the first character that 
 * differs from the original sequence to be as small as possible.
 * Comparing S[i] and S[i+1]:
 * If S[i] > S[i+1], deleting S[i] will result in S[i+1] moving into the i-th position.
 * Since S[i+1] < S[i], this will make the resulting string lexicographically smaller 
 * than any string formed by deleting a character at an index j > i.
 * 
 * Therefore, the optimal strategy is to find the first index i such that S[i] > S[i+1] 
 * and delete S[i]. If no such index exists (the string is non-decreasing), 
 * we should delete the last character to keep the prefix as small as possible.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int delete_idx = n - 1; // Default to deleting the last character
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            delete_idx = i;
            break;
        }
    }

    // Print the string excluding the character at delete_idx
    for (int i = 0; i < n; ++i) {
        if (i == delete_idx) continue;
        cout << s[i];
    }
    cout << "\n";
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