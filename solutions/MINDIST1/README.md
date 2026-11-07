# [Minimum distance between 1s (MINDIST1)](https://www.codechef.com/problems/MINDIST1)

- **Difficulty Rating**: 1335
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$, you are allowed to perform an operation: choose any substring of length 3 and reverse it. The goal is to find the minimum possible distance between any two '1's in the string after performing any number of operations. The distance between two '1's at indices $i$ and $j$ is defined as $|i - j|$.

## Intuition & Mathematical Observation
The key to this problem lies in the invariant property of the operation. Reversing a substring of length 3 (e.g., indices $i, i+1, i+2$) swaps the elements at $i$ and $i+2$, while the element at $i+1$ remains in its position. 

1. **Parity Invariant**: Notice that an element at an even index can only move to another even index, and an element at an odd index can only move to another odd index. The parity of the index of any '1' is invariant under this operation.
2. **Case 1: Mixed Parity**: If the string contains at least one '1' at an even index and at least one '1' at an odd index, we can use the operations to move these '1's closer until they are adjacent. Since one is at an even position and one is at an odd position, their distance will eventually be $|even - odd| = 1$.
3. **Case 2: Same Parity**: If all '1's are at even indices (or all are at odd indices), the distance between any two '1's will always be $|even_1 - even_2| = even$ (or $|odd_1 - odd_2| = even$). Since the distance must be at least 2 (as they cannot occupy the same index), the minimum distance is 2.

**Conclusion**: If there is at least one '1' at an even index and one '1' at an odd index, the answer is **1**. Otherwise, the answer is **2**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string exactly once to check the parity of the positions of all '1's.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if processed character by character.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows reversing any substring of length 3.
 * Reversing a substring of length 3 (e.g., abc -> cba) preserves the parity of the indices 
 * of the 1s. Specifically, if we have a 1 at index i, after reversing a substring 
 * containing i, the new index i' will satisfy i' % 2 == i % 2.
 * 
 * If there exists at least one pair of 1s such that their indices have different parity 
 * (i.e., one is at an even index and one is at an odd index), we can always bring them 
 * to be adjacent (distance 1).
 * 
 * If all 1s are at indices of the same parity, the distance between any two 1s 
 * will always be even. The minimum distance will be 2.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool has_even = false;
    bool has_odd = false;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (i % 2 == 0) {
                has_even = true;
            } else {
                has_odd = true;
            }
        }
    }

    // If we have 1s at both even and odd positions, we can achieve distance 1.
    // Otherwise, the minimum distance is 2.
    if (has_even && has_odd) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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