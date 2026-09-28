# [Encoding Message (ENCMSG)](https://www.codechef.com/problems/ENCMSG)

- **Difficulty Rating**: 1027
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to encode a string of length $N$ using two specific transformations:
1. **Pairwise Swap**: Swap adjacent characters in pairs (index 0 with 1, 2 with 3, etc.). If the string length $N$ is odd, the last character remains in its original position.
2. **Alphabet Mirroring**: Replace each character with its "mirror" in the alphabet (e.g., 'a' becomes 'z', 'b' becomes 'y', ..., 'z' becomes 'a').

## Intuition & Mathematical Observation
- **Step 1 (Swapping)**: We can iterate through the string with a step of 2. For each index $i$, we swap `S[i]` and `S[i+1]` as long as $i+1 < N$. This handles both even and odd lengths correctly.
- **Step 2 (Mirroring)**: The alphabet consists of 26 letters. The mirror of a character $c$ can be calculated using the ASCII values. Since 'a' has an ASCII value of 97 and 'z' has 122, the distance of a character from 'a' is `S[i] - 'a'`. Subtracting this distance from 'z' gives the mirrored character:
  $$\text{new\_char} = 'z' - (S[i] - 'a')$$
  This formula effectively maps $0 \to 25, 1 \to 24, \dots, 25 \to 0$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We perform two linear passes over the string of length $N$. With $T$ test cases, the total time complexity is $O(T \times N)$, which easily fits within the 1-second limit given $N \le 100$ and $T \le 1000$.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Step 1: Swap adjacent characters in pairs (0,1), (2,3), etc.
 *    If N is odd, the last character remains unchanged.
 * 2. Step 2: Replace each character 'c' with its mirror in the alphabet.
 *    'a' (0) -> 'z' (25), 'b' (1) -> 'y' (24), ..., 'z' (25) -> 'a' (0).
 *    Formula: new_char = 'z' - (old_char - 'a')
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Step 1: Swap pairs
    for (int i = 0; i + 1 < N; i += 2) {
        swap(S[i], S[i + 1]);
    }

    // Step 2: Replace characters
    for (int i = 0; i < N; ++i) {
        // 'a' is 97, 'z' is 122
        // The mapping is: char -> 'z' - (char - 'a')
        S[i] = 'z' - (S[i] - 'a');
    }

    cout << S << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```