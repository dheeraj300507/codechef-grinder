# [Restrict Palindromes (RESPAL)](https://www.codechef.com/problems/RESPAL)

- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to construct a string of length $N$ such that the total number of **distinct** palindromic substrings within the string is at most 5.

## Intuition & Mathematical Observation
To minimize the number of distinct palindromic substrings, we should avoid creating palindromes of length 2 or greater. 

If we use a repeating pattern of three characters, such as `"abc"`, the string becomes `"abcabcabc..."`. Let's analyze the palindromic substrings in this construction:
1. **Length 1**: The characters 'a', 'b', and 'c' are all palindromes. This gives us 3 distinct palindromes.
2. **Length 2+**: For any substring of length 2 or more (e.g., "ab", "bc", "ca", "abca"), the characters are arranged such that no two adjacent characters are the same, and the sequence does not mirror itself. For example, in "abc", "ab" is not a palindrome, "bc" is not a palindrome, and "abc" is not a palindrome.

Since the string is constructed by repeating "abc", any substring of length $\ge 2$ will never be a palindrome because the pattern ensures that no character is adjacent to an identical character, and the cyclic nature prevents the formation of longer palindromic structures.

Thus, the total number of distinct palindromic substrings is exactly 3 (the characters 'a', 'b', and 'c'), which satisfies the condition of being $\le 5$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate $N$ times to build the string.
- **Space Complexity**: $O(N)$ to store the resulting string before printing.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a string of length N such that the number of distinct 
 * palindromic substrings is at most 5.
 * 
 * Consider the string consisting of repeating characters 'abc'.
 * If we use a pattern like "abcabcabc...", the distinct palindromic 
 * substrings are just the individual characters 'a', 'b', and 'c'.
 * Total distinct palindromes = 3.
 */

void solve() {
    int N;
    cin >> N;
    string s = "";
    string pattern = "abc";
    for (int i = 0; i < N; ++i) {
        s += pattern[i % 3];
    }
    cout << s << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```