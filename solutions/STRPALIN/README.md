# [Palindromic substrings (STRPALIN)](https://www.codechef.com/problems/STRPALIN)

- **Difficulty Rating**: 1238
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings $A$ and $B$, determine if there exists a non-empty substring $s_1$ of $A$ and a non-empty substring $s_2$ of $B$ such that the concatenation $s_1 + s_2$ is a palindrome.

## Intuition & Mathematical Observation
The problem asks for the existence of any palindromic concatenation $s_1 + s_2$. 

1.  **The Minimal Case**: The simplest palindrome we can form is a string of length 2, such as "aa", "bb", etc. If strings $A$ and $B$ share at least one common character $c$, we can choose $s_1 = "c"$ and $s_2 = "c"$. The resulting string $s_1 + s_2 = "cc"$ is a palindrome.
2.  **The Impossibility Case**: If $A$ and $B$ share no common characters, then any character chosen from $A$ cannot be matched by a character from $B$. Since a palindrome must read the same forwards and backwards, the first character of the concatenated string must match the last character. If $s_1$ comes from $A$ and $s_2$ comes from $B$, the first character of $s_1$ must be equal to the last character of $s_2$. If the sets of characters in $A$ and $B$ are disjoint, this is impossible.
3.  **Conclusion**: The problem reduces to checking if the intersection of the set of characters in $A$ and the set of characters in $B$ is non-empty.

## Complexity Analysis
- **Time Complexity**: $O(|A| + |B|)$, where $|A|$ and $|B|$ are the lengths of the strings. We iterate through string $A$ once to mark its characters in a boolean array (or hash set) and then iterate through string $B$ to check for a match.
- **Space Complexity**: $O(1)$ (or $O(\Sigma)$ where $\Sigma$ is the alphabet size), as we only use a fixed-size array of 26 booleans to track the presence of characters.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are looking for a substring s1 of A and s2 of B such that s1 + s2 is a palindrome.
 * If A and B share a common character 'c', we can pick s1 = "c" and s2 = "c".
 * Then s1 + s2 = "cc", which is a palindrome.
 * If they share no characters, no such palindrome can be formed.
 */

void solve() {
    string A, B;
    cin >> A >> B;

    // Use a boolean array to track characters present in string A
    vector<bool> existsInA(26, false);
    for (char c : A) {
        existsInA[c - 'a'] = true;
    }

    // Check if any character in B exists in A
    bool found = false;
    for (char c : B) {
        if (existsInA[c - 'a']) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
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