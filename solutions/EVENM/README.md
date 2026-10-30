# [Even Matrix (EVENM)](https://www.codechef.com/problems/EVENM)

- **Difficulty Rating**: 1376
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct an $N \times N$ matrix containing all integers from $1$ to $N^2$ exactly once. The condition to satisfy is that for any square submatrix, the sum of its four corners must be even.

## Intuition & Mathematical Observation
The condition that the sum of the four corners of any square submatrix is even implies that the parity of the numbers must follow a specific pattern. Specifically, if we denote the parity of a cell at $(r, c)$ as $P(r, c)$, the condition $P(r, c) + P(r+a, c+a) \equiv 0 \pmod 2$ implies that cells separated by an even distance must have the same parity.

A **checkerboard pattern** of parities (Odd, Even, Odd, Even...) satisfies this condition perfectly. By filling the matrix row by row with numbers $1$ to $N^2$, we naturally alternate parities. However, a standard row-major fill would result in rows like:
- Row 0: O, E, O, E...
- Row 1: O, E, O, E... (This breaks the checkerboard pattern)

To fix this, we reverse the order of filling for every odd-indexed row (0-indexed). This ensures that the parity of the first element of an odd row is the opposite of the parity of the first element of the even row above it, maintaining the checkerboard parity throughout the entire matrix.

**Example for $N=3$:**
- Row 0: `1 2 3` (Parity: O, E, O)
- Row 1: `6 5 4` (Parity: E, O, E)
- Row 2: `7 8 9` (Parity: O, E, O)

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, as we iterate through each of the $N^2$ cells exactly once to fill and print the matrix.
- **Space Complexity**: $O(N)$, as we only store a single row of the matrix at a time before printing it.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct an N x N matrix with numbers 1 to N^2 such that for any square submatrix,
 * the sum of the corners is even.
 * 
 * Strategy:
 * Fill the matrix row by row with numbers 1 to N^2.
 * By reversing the order of elements in every odd-indexed row (0-indexed),
 * we maintain a checkerboard parity pattern which satisfies the corner-sum condition.
 */

void solve() {
    int N;
    cin >> N;
    
    int current = 1;
    for (int i = 0; i < N; ++i) {
        vector<int> row(N);
        if (i % 2 == 0) {
            // Fill left to right for even rows
            for (int j = 0; j < N; ++j) {
                row[j] = current++;
            }
        } else {
            // Fill right to left for odd rows
            for (int j = N - 1; j >= 0; --j) {
                row[j] = current++;
            }
        }
        
        // Print the row
        for (int j = 0; j < N; ++j) {
            cout << row[j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
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