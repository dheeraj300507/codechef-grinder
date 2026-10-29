# [Encoded String (DECODEIT)](https://www.codechef.com/problems/DECODEIT)

- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to decode a string of length $N$ (where $N$ is a multiple of 4) consisting of '0's and '1's. The string is composed of 4-bit blocks, where each block represents a character from the first 16 letters of the English alphabet ('a' through 'p'). Specifically, 'a' corresponds to binary `0000` (0), 'b' to `0001` (1), and so on, up to 'p' which corresponds to `1111` (15). We need to output the decoded string.

## Intuition & Mathematical Observation
Since each character is represented by exactly 4 bits, we can process the input string in chunks of 4. 
1. For every 4-bit segment, we treat it as a binary number.
2. Converting a binary string to its decimal equivalent is straightforward:
   - We can iterate through the 4 bits and use the formula: `val = (val * 2) + bit`.
   - Alternatively, using bitwise operations: `val = (val << 1) | bit`.
3. Once we have the integer value (ranging from 0 to 15), we map it to the corresponding character by adding the value to the ASCII code of 'a'.
   - `char c = 'a' + val;`

This approach is efficient and avoids the need for complex lookup tables or conditional branching.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once, performing constant-time operations for each 4-bit block.
- **Space Complexity**: $O(N)$ to store the input string and the resulting decoded string. If we were to print characters individually, the auxiliary space could be reduced to $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Each 4-bit block represents a character from 'a' to 'p'.
 * 'a' is 0000 (0), 'b' is 0001 (1), ..., 'p' is 1111 (15).
 * We convert each 4-bit substring to an integer and map it to the alphabet.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    string result = "";
    // Process the string in chunks of 4
    for (int i = 0; i < N; i += 4) {
        int val = 0;
        // Convert 4-bit substring to integer
        for (int j = 0; j < 4; ++j) {
            val = (val << 1) + (S[i + j] - '0');
        }
        // Map integer to character ('a' + 0 = 'a', 'a' + 15 = 'p')
        result += (char)('a' + val);
    }
    cout << result << endl;
}

int main() {
    // Optimize I/O operations for faster execution
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