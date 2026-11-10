# [Early Certificates (EARLYWIN)](https://www.codechef.com/problems/EARLYWIN)

- **Difficulty Rating**: 595
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings $A$ and $B$ of lengths $N$ and $M$ respectively, the task is to find their **Longest Common Prefix (LCP)**. The problem guarantees that the first characters of both strings are identical, ensuring that the LCP will have a length of at least 1.

## Intuition & Mathematical Observation
The Longest Common Prefix is the sequence of characters starting from the beginning of both strings that are identical. To find this:
1. We compare the characters of string $A$ and string $B$ at each index $i$, starting from $0$.
2. We continue this comparison as long as $A[i] == B[i]$ and $i$ is within the bounds of both strings (i.e., $i < \min(N, M)$).
3. As soon as we encounter a mismatch ($A[i] \neq B[i]$) or reach the end of the shorter string, we stop.
4. The characters collected up to that point form the longest common prefix.

## Complexity Analysis
- **Time Complexity**: $O(\min(N, M))$ per test case, where $N$ and $M$ are the lengths of the two strings. We perform a single pass through the strings up to the length of the shorter one.
- **Space Complexity**: $O(N + M)$ to store the input strings. If we were to print characters directly instead of building a result string, the auxiliary space could be reduced to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two strings A and B. We need to find the longest common prefix.
 * Since the problem guarantees that the first characters are the same, 
 * the length of the common prefix will be at least 1.
 * We iterate through the indices from 0 up to min(N, M) - 1 and compare 
 * characters at each position. As soon as we find a mismatch, we stop.
 * 
 * Time Complexity: O(min(N, M)) per test case.
 * Space Complexity: O(N + M) to store the strings.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string A, B;
    cin >> A >> B;

    string result = "";
    int limit = min(N, M);

    for (int i = 0; i < limit; ++i) {
        if (A[i] == B[i]) {
            result += A[i];
        } else {
            break;
        }
    }

    cout << result << "\n";
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