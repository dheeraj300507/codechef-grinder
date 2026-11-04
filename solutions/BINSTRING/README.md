# [Distinct Binary Strings (BINSTRING)](https://www.codechef.com/problems/BINSTRING)

- **Difficulty Rating**: 1262
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we perform exactly one operation: delete one character $S[i]$ from the string. We need to determine the total number of **distinct** strings of length $N-1$ that can be formed by performing this operation for every possible index $i$ (from $0$ to $N-1$).

## Intuition & Mathematical Observation
The core of the problem lies in identifying when two different deletions result in the same string.

1.  **Observation**: If we have a sequence of identical consecutive characters (e.g., `111`), deleting the first `1` results in `11`, deleting the second `1` results in `11`, and deleting the third `1` also results in `11`. Thus, for any block of $k$ identical consecutive characters, all $k$ possible deletions result in the same string.
2.  **Transition**: If we have a boundary between two different characters (e.g., `...10...`), deleting the `1` results in a string with a `0` at that position, while deleting the `0` results in a string with a `1` at that position. These two resulting strings are guaranteed to be distinct.
3.  **Conclusion**: The number of distinct strings is equal to the number of contiguous "blocks" of identical characters. We can count these blocks by iterating through the string and incrementing a counter whenever $S[i] \neq S[i-1]$.

**Example**:
- String: `11001`
- Blocks: `[11]`, `[00]`, `[1]`
- Count: 3 distinct strings.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string to count the transitions between blocks.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if processed character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N. We delete exactly one character S[i].
 * We want to find the number of distinct strings of length N-1.
 * 
 * Key Insight:
 * Deleting S[i] results in the same string as deleting S[i+1] if and only if S[i] == S[i+1].
 * If S[i] != S[i+1], deleting S[i] results in a string where the character at index i 
 * is S[i+1], while deleting S[i+1] results in a string where the character at index i 
 * is S[i]. Since S[i] != S[i+1], these resulting strings are distinct.
 * 
 * The number of distinct strings is equal to the number of contiguous blocks of 
 * identical characters in the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    // Start with 1 because the first block always exists
    int blocks = 1;
    for (int i = 1; i < N; ++i) {
        // Every time the character changes, a new block starts
        if (S[i] != S[i - 1]) {
            blocks++;
        }
    }

    cout << blocks << "\n";
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