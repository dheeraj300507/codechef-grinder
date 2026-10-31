# [Chef and String (RECNDSTR)](https://www.codechef.com/problems/RECNDSTR)

- **Difficulty Rating**: 1206
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, we define two operations:
1. **Left Shift ($L$):** Move the first character of the string to the end. (e.g., "abc" becomes "bca").
2. **Right Shift ($R$):** Move the last character of the string to the beginning. (e.g., "abc" becomes "cab").

The task is to determine if there exists a string $V$ such that shifting $V$ to the left results in $S$ AND shifting $V$ to the right results in $S$. In simpler terms, we need to check if the left shift of $S$ is equal to the right shift of $S$.

## Intuition & Mathematical Observation
Let $S$ be a string of length $n$.
- The **Left Shift** of $S$ is formed by taking the substring from index $1$ to $n-1$ and appending the character at index $0$ to the end: $L(S) = S[1 \dots n-1] + S[0]$.
- The **Right Shift** of $S$ is formed by taking the last character and prepending it to the substring from index $0$ to $n-2$: $R(S) = S[n-1] + S[0 \dots n-2]$.

The problem asks if there exists a $V$ such that $L(V) = S$ and $R(V) = S$. By definition, if we perform a left shift on $S$ and a right shift on $S$, we are essentially checking if the resulting strings are identical. If the length of the string is $\le 2$, any shift results in the same string or a trivial permutation, so the answer is always "YES". For longer strings, we simply construct both shifted versions and compare them.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform string slicing and concatenation, which takes linear time relative to the string length.
- **Space Complexity**: $O(N)$ to store the shifted versions of the string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to check if the left shift of S is equal to the right shift of S.
 * L(S) = S[1...n-1] + S[0]
 * R(S) = S[n-1] + S[0...n-2]
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // Strings of length 1 or 2 will always satisfy the condition
    // because the left shift and right shift result in the same string.
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Construct L(S)
    string l_s = s.substr(1) + s[0];
    
    // Construct R(S)
    string r_s = s.back() + s.substr(0, n - 1);
    
    if (l_s == r_s) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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