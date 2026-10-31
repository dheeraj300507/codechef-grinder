# [Chef and String (RECNDSTR)](https://www.codechef.com/problems/RECNDSTR)

- **Difficulty Rating**: 1206
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, we need to determine if there exists a string $V$ such that shifting $V$ to the left by one position results in $S$ (denoted as $L(V) = S$) and shifting $V$ to the right by one position also results in $S$ (denoted as $R(V) = S$).

## Intuition & Mathematical Observation
The problem asks if a string $V$ exists such that:
1. $L(V) = S$
2. $R(V) = S$

If we perform a left shift on $S$ itself, we get $L(S)$, and if we perform a right shift on $S$, we get $R(S)$. 
- If $L(V) = S$, then $V$ is essentially $S$ shifted to the right by 1.
- If $R(V) = S$, then $V$ is essentially $S$ shifted to the left by 1.

Therefore, the condition $L(V) = S$ and $R(V) = S$ is satisfied if and only if the **left shift of $S$ is equal to the right shift of $S$**.

**Edge Case:**
For strings of length 1 or 2, the left shift and right shift operations result in the same string (e.g., "a" $\rightarrow$ "a", "ab" $\rightarrow$ "ba"). Thus, all strings with length $\le 2$ automatically satisfy the condition.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform string slicing and concatenation, which takes linear time relative to the length of the string.
- **Space Complexity**: $O(N)$ to store the shifted versions of the string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition L(V) = S and R(V) = S is equivalent to checking if 
 * the left shift of S is equal to the right shift of S.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // Strings of length 1 or 2 always satisfy the condition
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Left shift of S: s[1...n-1] + s[0]
    string left_shifted = s.substr(1) + s[0];
    
    // Right shift of S: s[n-1] + s[0...n-2]
    string right_shifted = s.back() + s.substr(0, n - 1);
    
    if (left_shifted == right_shifted) {
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```