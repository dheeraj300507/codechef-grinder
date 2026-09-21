# [Complementary Strand in a DNA (DNASTRAND)](https://www.codechef.com/problems/DNASTRAND)

- **Difficulty Rating**: 660
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a DNA sequence represented as a string of characters ('A', 'T', 'C', 'G'), we need to find its complementary strand. The rules for DNA base pairing are:
- 'A' pairs with 'T'
- 'T' pairs with 'A'
- 'C' pairs with 'G'
- 'G' pairs with 'C'

We are given the length of the string $N$ and the string itself, and we must output the resulting complementary sequence.

## Intuition & Mathematical Observation
The problem is a direct mapping task. Since each character in the input string has exactly one corresponding complement, we can iterate through the string character by character and replace each base with its pair. 

Using a simple `if-else` structure or a `switch` statement allows us to transform the string in a single pass. Because the transformation is local to each character, the order is preserved, and the output string will have the same length as the input string.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We visit each character exactly once to determine its complement.
- **Space Complexity**: $O(N)$ to store the input string and the resulting complementary string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Complementary Strand in a DNA
 * Approach: Iterate through the string and map each character to its complement.
 * A -> T, T -> A, C -> G, G -> C.
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    string result = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            result += 'T';
        } else if (s[i] == 'T') {
            result += 'A';
        } else if (s[i] == 'C') {
            result += 'G';
        } else if (s[i] == 'G') {
            result += 'C';
        }
    }
    cout << result << "\n";
}

int main() {
    // Fast I/O setup
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