# [Palindromes Not Allowed (NOPAL)](https://www.codechef.com/problems/NOPAL)

- **Difficulty Rating**: 1360
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to construct a string of length $N$ such that it contains no palindromic substrings of length 2 or greater. A string is a palindrome if it reads the same forwards and backwards.

## Intuition & Mathematical Observation
To ensure no substring of length $\ge 2$ is a palindrome, we must satisfy two primary conditions:
1. **No length-2 palindromes**: This means no two adjacent characters can be the same ($S[i] \neq S[i-1]$).
2. **No length-3 palindromes**: This means no two characters separated by one character can be the same ($S[i] \neq S[i-2]$).

If we satisfy these two conditions, it is mathematically impossible to have a palindrome of length $\ge 4$. Any palindrome of length 4 or greater would inherently contain a smaller palindrome of length 2 or 3 at its center.

By using a repeating pattern of three characters (e.g., `'a'`, `'b'`, `'c'`), we can easily satisfy these constraints:
- The sequence `abcabc...` ensures that $S[i]$ is never equal to $S[i-1]$ or $S[i-2]$.
- For any index $i$, the character is determined by $(i \pmod 3)$. Since the cycle length is 3, the character at $i$ will only repeat at $i+3$, $i+6$, etc., which is far enough to avoid any palindromic structure.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate exactly $N$ times to construct the string.
- **Space Complexity**: $O(N)$ to store the resulting string before printing.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a string of length N such that no substring of length >= 2 is a palindrome.
 * A substring of length 2 is a palindrome if S[i] == S[i+1].
 * A substring of length 3 is a palindrome if S[i] == S[i+2].
 * If we ensure that S[i] != S[i-1] and S[i] != S[i-2] for all i,
 * then no substring of length 2 or 3 can be a palindrome.
 * If no substring of length 2 or 3 is a palindrome, then no substring of length > 3
 * can be a palindrome either (because any palindrome of length > 3 would contain
 * a smaller palindrome of length 2 or 3 as a core).
 * 
 * We can achieve this by cycling through the first 3 letters of the alphabet ('a', 'b', 'c').
 * Pattern: "abcabcabc..."
 * - S[i] != S[i-1] is satisfied (e.g., 'a' != 'b', 'b' != 'c', 'c' != 'a').
 * - S[i] != S[i-2] is satisfied (e.g., 'a' != 'c', 'b' != 'a', 'c' != 'b').
 */

void solve() {
    int N;
    cin >> N;
    string result = "";
    for (int i = 0; i < N; ++i) {
        // Use modulo 3 to cycle through 'a', 'b', 'c'
        result += (char)('a' + (i % 3));
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