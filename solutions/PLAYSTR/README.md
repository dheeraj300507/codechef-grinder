# [Playing with Strings (PLAYSTR)](https://www.codechef.com/problems/PLAYSTR)

- **Difficulty Rating**: 1108
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two binary strings $S$ and $R$ of length $N$, determine if it is possible to transform string $S$ into string $R$ by performing any number of swaps between any two characters in $S$.

## Intuition & Mathematical Observation
The key observation is that the operation allowed is swapping **any** two characters in the string. Swapping allows us to rearrange the characters of $S$ into any possible permutation. 

Because the strings consist only of '0's and '1's, if we can rearrange $S$ into any order, $S$ can be transformed into $R$ if and only if both strings contain the exact same number of '0's and '1's. Since the strings are of the same length $N$, checking if the count of '1's is equal in both strings is sufficient to guarantee that the count of '0's is also equal.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the strings, as we iterate through each string exactly once to count the characters.
- **Space Complexity**: $O(N)$ to store the input strings $S$ and $R$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allowed is swapping any two characters in string S.
 * Swapping characters allows us to rearrange the characters of S in any order.
 * Therefore, string S can be transformed into string R if and only if 
 * S and R contain the same number of '0's and the same number of '1's.
 * Since the strings are binary and have the same length N, we only need to 
 * check if the count of '1's in S is equal to the count of '1's in R.
 */

void solve() {
    int N;
    cin >> N;
    string S, R;
    cin >> S >> R;

    int countS1 = 0;
    int countR1 = 0;

    // Count '1's in string S
    for (char c : S) {
        if (c == '1') countS1++;
    }

    // Count '1's in string R
    for (char c : R) {
        if (c == '1') countR1++;
    }

    // If counts match, transformation is possible
    if (countS1 == countR1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```