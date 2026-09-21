# [Different Consecutive Characters (DIFFCONSEC)](https://www.codechef.com/problems/DIFFCONSEC)

- **Difficulty Rating**: 879
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to ensure that no two consecutive characters in the string are the same. We are allowed to insert either '0' or '1' at any position in the string. The goal is to find the minimum number of insertions required to satisfy the condition.

## Intuition & Mathematical Observation
The problem asks us to eliminate all instances where $S[i] == S[i+1]$. 

Consider a block of identical characters, for example, "000". 
- To fix the first pair, we insert a '1' between the first and second '0', resulting in "0100".
- Now, we still have a pair of '0's at the end. We insert another '1' to get "01010".
- In total, for a sequence of $K$ identical characters, we need $K-1$ insertions to separate them all.

Mathematically, every time we encounter a pair of adjacent identical characters ($S[i] == S[i+1]$), we are forced to perform exactly one insertion to break that specific adjacency. Since each insertion can resolve exactly one such conflict, the total number of operations required is simply the count of all indices $i$ where $S[i] == S[i+1]$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string to compare adjacent characters.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if we process the string character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S and we want to ensure no two consecutive characters are the same.
 * We can insert characters to break sequences of identical characters.
 * 
 * If we have a sequence of identical characters like "00", we must insert a character
 * between them to make it "010". This takes 1 operation.
 * If we have "000", we need to break the first pair (0100) and then the second pair (01010).
 * Essentially, for every index i from 0 to N-2, if S[i] == S[i+1], we must perform 
 * an insertion to separate them.
 * 
 * Each time we find S[i] == S[i+1], we increment our operation count.
 * This is optimal because each insertion can fix exactly one pair of identical 
 * consecutive characters.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int operations = 0;
    // Iterate through the string and check adjacent characters
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == S[i + 1]) {
            operations++;
        }
    }
    cout << operations << "\n";
}

int main() {
    // Fast I/O setup
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