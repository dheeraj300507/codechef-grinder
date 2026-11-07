# [Alternating Binary String (ALBS)](https://www.codechef.com/problems/ALBS)

- **Difficulty Rating**: 1156
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to make it "alternating" (i.e., $S[i] \neq S[i-1]$ for all $2 \le i \le N$). We are allowed to perform an operation where we choose an index $i$ and flip all characters from $S[i]$ to $S[N]$ (0 becomes 1, 1 becomes 0). We need to find the minimum number of operations required to make the string alternating.

## Intuition & Mathematical Observation
The key observation is to look at the boundaries where the alternating property is violated. A violation occurs at index $i$ if $S[i] == S[i-1]$.

When we perform an operation at index $i$, we flip all characters from $i$ to $N$. This flip changes the relationship between $S[i-1]$ and $S[i]$. Specifically, if $S[i-1] == S[i]$ before the flip, after the flip, $S[i]$ becomes the opposite value, effectively making $S[i-1] \neq S[i]$.

Because an operation at index $i$ only affects the relationship between $S[i-1]$ and $S[i]$ (and potentially subsequent pairs), we can process the string greedily from left to right. Every time we encounter a violation $S[i] == S[i-1]$, we must perform an operation at index $i$ to fix it. Since each operation at index $i$ fixes the violation at $i$ without creating a new violation at $i-1$, the total number of operations required is simply the total count of indices $i$ where $S[i] == S[i-1]$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once to count the violations.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if we process the string character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string alternating (S[i] != S[i-1]).
 * An operation at index i flips all characters from i to N.
 * 
 * A violation occurs at index i (where 2 <= i <= N) if S[i] == S[i-1].
 * Each time we find such a violation, we perform an operation at index i.
 * This fixes the current violation and does not negatively impact 
 * previously fixed pairs.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N <= 1) {
        cout << 0 << "\n";
        return;
    }

    int operations = 0;
    // Count how many times the alternating condition is broken.
    // Each break requires exactly one operation to fix.
    for (int i = 1; i < N; ++i) {
        if (S[i] == S[i - 1]) {
            operations++;
        }
    }

    cout << operations << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```