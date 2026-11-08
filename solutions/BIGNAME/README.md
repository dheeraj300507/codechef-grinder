# [Bigger is Better (BIGNAME)](https://www.codechef.com/problems/BIGNAME)

- **Difficulty Rating**: 1227
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $A$ of length $N$, we need to find a string $S$ of the same length $N$ such that:
1. $S > A$ (lexicographically)
2. $\text{reverse}(S) > A$ (lexicographically)

If no such string exists, output -1.

## Intuition & Mathematical Observation
The lexicographical comparison of strings is determined by the first character where they differ. To make a string $S$ as large as possible, we should aim to make its characters 'z' as much as possible.

1. **The "All-Z" Case**: If the input string $A$ consists entirely of 'z's (e.g., "zzz"), it is impossible to find a string $S$ of the same length that is strictly greater than $A$. Therefore, if $A$ is all 'z's, the answer is -1.
2. **The General Case**: If $A$ is not all 'z's, we can construct $S$ by setting all its characters to 'z'. 
   - Since $A$ is not "zzz...z", the string $S = \text{"zzz...z"}$ is guaranteed to be strictly greater than $A$.
   - Similarly, $\text{reverse}(S)$ will also be "zzz...z". Since $A$ is not "zzz...z", $\text{reverse}(S) > A$ will also hold true.
   
Thus, the construction $S = \text{"z"}^N$ satisfies both conditions whenever $A$ is not already the lexicographically largest possible string of length $N$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string once to check if it consists of all 'z's and once to print the result.
- **Space Complexity**: $O(N)$ to store the input string $A$ and the output string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a string S of length N such that S > A and reverse(S) > A.
 * If A consists only of 'z's, no such string exists because 'z' is the 
 * largest character. Otherwise, the string consisting of N 'z's will 
 * be strictly greater than A and its reverse will also be greater than A.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    // Check if A is already the maximum possible string
    bool all_z = true;
    for (char c : A) {
        if (c != 'z') {
            all_z = false;
            break;
        }
    }

    if (all_z) {
        // If A is all 'z's, no string S can be strictly greater
        cout << -1 << "\n";
    } else {
        // Otherwise, a string of all 'z's is the optimal solution
        string S(N, 'z');
        cout << S << "\n";
    }
}

int main() {
    // Optimize I/O operations
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