# [Make Cat (INCAT)](https://www.codechef.com/problems/INCAT)

- **Difficulty Rating**: 210
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length 3, determine if it is possible to rearrange the characters of $S$ to form the word "cat".

## Intuition & Mathematical Observation
To form the word "cat" from a 3-character string, the string must contain exactly one 'c', one 'a', and one 't'. 

The most efficient way to check if two strings are anagrams (contain the same characters with the same frequencies) is to sort both strings and compare them. Since "cat" sorted alphabetically becomes "act", we simply need to:
1. Sort the input string $S$.
2. Compare the resulting string with "act".
3. If they match, the answer is "Yes"; otherwise, it is "No".

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$, where $N$ is the length of the string. Since $N=3$ is a constant, this effectively operates in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we are only storing a string of length 3 and performing an in-place sort.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length 3. We need to determine if it can be 
 * rearranged to form the word "cat".
 * 
 * A string of length 3 can be rearranged to form "cat" if and only if 
 * it contains exactly one 'c', one 'a', and one 't'.
 * 
 * Approach:
 * 1. Sort the input string S.
 * 2. Compare the sorted string with "act" (which is "cat" sorted).
 * 3. If they are equal, output "Yes", otherwise "No".
 */

void solve() {
    string s;
    if (!(cin >> s)) return;
    
    // Sort the string to bring characters into alphabetical order
    sort(s.begin(), s.end());
    
    // Compare with the sorted version of "cat"
    if (s == "act") {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem description states the input contains a single string S.
    solve();
    
    return 0;
}
```