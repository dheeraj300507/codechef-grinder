# [Prime Reversal (PRIMEREVERSE)](https://www.codechef.com/problems/PRIMEREVERSE)

- **Difficulty Rating**: 1053
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two binary strings $A$ and $B$ of length $N$, we are allowed to perform an operation: choose a substring of length $X$ (where $X$ is a prime number) and reverse it. We need to determine if string $A$ can be transformed into string $B$ using any number of these operations.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the flexibility provided by the prime-length reversal operation:

1.  **Adjacent Swaps**: Since $2$ is a prime number, we can reverse any substring of length $2$. Reversing a substring of length $2$ is equivalent to swapping two adjacent elements.
2.  **Permutation Capability**: If we can swap any two adjacent elements, we can generate any possible permutation of the string. This means that if we have enough '0's and '1's, we can rearrange them into any order we desire.
3.  **Sufficiency**: Because we can perform these operations any number of times, the specific positions of the '0's and '1's in the original string $A$ do not matter. The only constraint is the total count of '0's and '1's.
4.  **Conclusion**: String $A$ can be transformed into string $B$ if and only if the number of '1's in $A$ equals the number of '1's in $B$ (which automatically implies the number of '0's are also equal, given the strings are of the same length $N$).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the strings. We iterate through each string exactly once to count the occurrences of '0's and '1's.
- **Space Complexity**: $O(N)$ to store the input strings. If we processed the strings character by character without storing them, it could be reduced to $O(1)$ auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Since we can reverse substrings of prime length, specifically length 2,
 * we can swap any two adjacent elements. This allows us to reorder the 
 * string into any permutation. Thus, the problem reduces to checking 
 * if both strings have the same count of '1's and '0's.
 */

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int countA1 = 0;
    int countB1 = 0;

    // Count '1's in both strings
    for (char c : a) {
        if (c == '1') countA1++;
    }

    for (char c : b) {
        if (c == '1') countB1++;
    }

    // If counts of '1's are equal, the counts of '0's must also be equal
    if (countA1 == countB1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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