# [Delete Not Equal (DELNQ)](https://www.codechef.com/problems/DELNQ)

- **Difficulty Rating**: 1118
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a binary string of length $N$. You can perform an operation where you choose two adjacent characters that are different (i.e., '0' and '1' or '1' and '0') and delete one of them. The goal is to find the minimum possible length of the string after performing any number of operations.

## Intuition & Mathematical Observation
The core of the problem lies in the condition required to perform an operation: the existence of adjacent different characters.

1.  **Case 1: The string contains both '0's and '1's.**
    If the string contains at least one '0' and at least one '1', there must exist at least one index $i$ such that $S[i] \neq S[i+1]$. By performing the operation on this pair, we reduce the string length by 1. Because we can always find an adjacent pair of different characters as long as both types exist, we can continue this process until only one character remains. Thus, the minimum length is **1**.

2.  **Case 2: The string contains only '0's or only '1's.**
    If the string consists entirely of the same character, there are no adjacent pairs that are different. Therefore, no operations can be performed. The string remains in its original state, and the minimum length is **$N$**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string exactly once to check for the presence of '0's and '1's.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to delete one of two adjacent characters if they are different.
 * This means if there is at least one '0' and at least one '1' in the string, 
 * we can always reduce the string length to 1.
 * 
 * If the string consists of only '0's or only '1's, no operation can ever be 
 * performed, so the length remains N.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool hasZero = false;
    bool hasOne = false;

    // Check for the presence of both characters
    for (char c : s) {
        if (c == '0') hasZero = true;
        if (c == '1') hasOne = true;
    }

    // If both exist, we can reduce the string to length 1
    if (hasZero && hasOne) {
        cout << 1 << "\n";
    } else {
        // Otherwise, no operations are possible
        cout << n << "\n";
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