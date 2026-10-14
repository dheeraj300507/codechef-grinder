# [Opposite Attract (P2169)](https://www.codechef.com/problems/P2169)

- **Difficulty Rating**: 671
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we need to construct a new string $T$ of the same length such that for every index $i$, the character $T[i]$ is different from $S[i]$. Since the string only contains '0's and '1's, this means we must flip every bit in the string.

## Intuition & Mathematical Observation
The problem states that $T[i] \neq S[i]$ for all $i$. In a binary system:
- If $S[i] = '0'$, then $T[i]$ must be '1'.
- If $S[i] = '1'$, then $T[i]$ must be '0'.

This is a simple bitwise inversion. We can iterate through the input string $S$, and for each character, append the opposite character to our result string $T$. Alternatively, one could modify the string in place or print the flipped characters directly to save space.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string exactly once. The total time complexity across all test cases is $O(\sum N)$.
- **Space Complexity**: $O(N)$ to store the input string $S$ and the resulting string $T$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * We need to construct a string T such that T[i] != S[i] for all i.
 * Since S consists only of '0' and '1':
 * - If S[i] == '0', then T[i] must be '1'.
 * - If S[i] == '1', then T[i] must be '0'.
 * 
 * This is equivalent to flipping each bit of the string S.
 * Time Complexity: O(N) per test case, O(Sum of N) total.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    string T = "";
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            T += '1';
        } else {
            T += '0';
        }
    }
    cout << T << "\n";
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