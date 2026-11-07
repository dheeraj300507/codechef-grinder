# [Invert And Equalize (INVEQ)](https://www.codechef.com/problems/INVEQ)

- **Difficulty Rating**: 1102
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to make all characters in the string equal (either all '0's or all '1's). In one operation, we can choose any contiguous substring and flip all its characters (change '0' to '1' and vice-versa). The goal is to find the minimum number of operations required.

## Intuition & Mathematical Observation
The key observation is to view the string as a sequence of **contiguous blocks** of identical characters. For example, in the string `11000110`, the blocks are `[11]`, `[000]`, `[11]`, and `[0]`.

- Let $C_0$ be the number of contiguous blocks of '0's.
- Let $C_1$ be the number of contiguous blocks of '1's.

If we want to turn the entire string into '0's, we must flip every block of '1's. This would take $C_1$ operations. Conversely, to turn the entire string into '1's, we must flip every block of '0's, taking $C_0$ operations. 

Since we want the minimum number of operations, the answer is simply $\min(C_0, C_1)$. 

**Algorithm:**
1. Traverse the string and count the number of times a block starts.
2. A new block starts at index $i$ if $S[i] \neq S[i-1]$ (for $i > 0$).
3. Increment the respective counter based on whether the new block consists of '0's or '1's.
4. Output the minimum of the two counters.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string to count the blocks.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if processing character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make all characters in a binary string equal using the minimum number of operations.
 * An operation consists of flipping a continuous block of identical characters.
 * 
 * The minimum number of operations will be min(count of '0' blocks, count of '1' blocks).
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    int zero_blocks = 0;
    int one_blocks = 0;

    // Count transitions to identify blocks
    // A new block starts if the current character is different from the previous one
    // or if it's the first character.
    if (s[0] == '0') zero_blocks++;
    else one_blocks++;

    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '0') zero_blocks++;
            else one_blocks++;
        }
    }

    cout << min(zero_blocks, one_blocks) << "\n";
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