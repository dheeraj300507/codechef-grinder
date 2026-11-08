# [Single Operation Part 1 (SINGLEOP1)](https://www.codechef.com/problems/SINGLEOP1)

- **Difficulty Rating**: 1217
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ representing an integer $X$, we need to choose an integer $Y$ ($1 \le Y \le N$) such that the value of $X \oplus (X \gg Y)$ is maximized. We are required to output the value of $Y$ that achieves this maximum.

## Intuition & Mathematical Observation
Let $X$ be represented by the binary string $S = s_0s_1...s_{N-1}$. 
When we perform $X \oplus (X \gg Y)$, we are essentially XORing the original number with a version of itself shifted right by $Y$ positions.

1. **MSB Preservation**: Since $s_0$ is the most significant bit (always '1' for a valid binary representation), and $(X \gg Y)$ will have a '0' at the $0^{th}$ position for any $Y \ge 1$, the $0^{th}$ bit of the result will always be $1 \oplus 0 = 1$.
2. **Maximizing the Result**: To maximize the result, we want the bits at the most significant positions to be '1'. 
3. **The Strategy**: Consider the prefix of consecutive '1's starting from the left. If we choose $Y$ equal to the number of consecutive '1's, the XOR operation will effectively turn the first '0' encountered into a '1' (or maintain the '1's in a way that maximizes the magnitude).
   - Example: If $S = 11101$, the prefix of '1's has length 3. Choosing $Y=3$ results in $11101 \oplus 00111 = 11010$.
   - By choosing $Y$ equal to the count of the leading '1's, we ensure that the bits that were originally '1' are XORed with '1's from the shifted version, effectively clearing them, while the first '0' is XORed with a '1', turning it into a '1'. This creates the largest possible value by maximizing the most significant bits.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we iterate through the string once to count the leading '1's.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize X ^ (X >> Y), we want to flip the most significant '0' bit 
 * to a '1'. This is achieved by setting Y equal to the number of 
 * consecutive '1's starting from the most significant bit.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int y = 0;
    // Count the number of consecutive '1's from the start
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            y++;
        } else {
            // Stop at the first '0'
            break;
        }
    }
    
    cout << y << "\n";
}

int main() {
    // Optimize I/O operations
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