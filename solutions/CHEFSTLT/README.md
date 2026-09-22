# [Chef and Two Strings (CHEFSTLT)](https://www.codechef.com/problems/CHEFSTLT)

- **Difficulty Rating**: 1036
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings $S_1$ and $S_2$ of equal length consisting of lowercase English letters and the character `'?'`, we need to find the minimum and maximum possible number of positions where the characters differ. The `'?'` character acts as a wildcard that can be replaced by any lowercase letter ('a'-'z').

## Intuition & Mathematical Observation

To determine the minimum and maximum differences, we analyze the strings character by character at each index $i$:

1.  **Case 1: Both characters are known letters ($S_1[i] \neq '?'$ and $S_2[i] \neq '?'$)**
    *   If $S_1[i] == S_2[i]$, they are identical. They contribute **0** to both the minimum and maximum difference.
    *   If $S_1[i] \neq S_2[i]$, they are inherently different. They contribute **1** to both the minimum and maximum difference.

2.  **Case 2: At least one character is a wildcard ('?')**
    *   **Minimum Difference:** We can always choose the wildcard to match the other character (or choose 'a' for both if both are '?'). Thus, they contribute **0** to the minimum difference.
    *   **Maximum Difference:** We can always choose the wildcard to be different from the other character (e.g., if $S_1[i] = '?'$ and $S_2[i] = 'a'$, we can set $S_1[i] = 'b'$). Thus, they contribute **1** to the maximum difference.

By iterating through the strings once and applying these rules, we can calculate the total minimum and maximum differences.

## Complexity Analysis

- **Time Complexity**: $O(N)$, where $N$ is the length of the strings. We perform a single pass through the strings to compute the counts.
- **Space Complexity**: $O(N)$ to store the input strings. If we processed the strings character by character from the input stream, this could be reduced to $O(1)$ auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two strings S1 and S2 of equal length containing lowercase letters and '?'.
 * '?' can be replaced by any lowercase letter.
 * 
 * Minimal difference:
 * For each position i:
 * - If S1[i] == '?' or S2[i] == '?', we can always make them equal.
 * - If both are letters and S1[i] != S2[i], they contribute 1 to the difference.
 * 
 * Maximal difference:
 * For each position i:
 * - If S1[i] == '?' or S2[i] == '?', we can always make them different.
 * - If both are letters and S1[i] != S2[i], they contribute 1.
 */

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int min_diff = 0;
    int max_diff = 0;
    int n = s1.length();
    
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '?' || s2[i] == '?') {
            // For min: we can make them equal, so no difference added.
            // For max: we can make them different, so 1 difference added.
            max_diff++;
        } else {
            // Both are letters.
            if (s1[i] != s2[i]) {
                min_diff++;
                max_diff++;
            }
        }
    }
    
    cout << min_diff << " " << max_diff << "\n";
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