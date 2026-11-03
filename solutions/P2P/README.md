# [Make Odd (P2P)](https://www.codechef.com/problems/P2P)

- **Difficulty Rating**: 1203
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two binary strings $A$ and $B$ of length $N$, we must construct a new binary string $C$ of length $N$ such that for each index $i$, $C[i]$ is either $A[i]$ or $B[i]$. The goal is to determine if it is possible to choose the elements such that the total number of $1$s in $C$ (the sum of its elements) is odd.

## Intuition & Mathematical Observation
To solve this, we categorize the indices into three types based on the values of $A[i]$ and $B[i]$:

1.  **Type 0 (Both are '0')**: We are forced to choose $0$. This contributes $0$ to the total sum.
2.  **Type 1 (Both are '1')**: We are forced to choose $1$. This contributes $1$ to the total sum.
3.  **Type Flexible (One is '0', one is '1')**: We have a choice. We can pick either $0$ or $1$.

**Logic:**
*   Let `fixed_ones` be the count of indices where both $A[i]$ and $B[i]$ are '1'.
*   Let `flexible` be the count of indices where $A[i] \neq B[i]$.
*   If `flexible > 0`, we have at least one position where we can choose to add either $0$ or $1$ to our total sum. This means we can adjust the parity of the total sum at will. Therefore, if there is at least one flexible position, we can always make the total sum odd.
*   If `flexible == 0`, we have no choice. The total sum is strictly equal to `fixed_ones`. In this case, the answer is "YES" only if `fixed_ones` is already odd.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the strings, as we iterate through the strings exactly once.
- **Space Complexity**: $O(N)$ to store the input strings (or $O(1)$ if processed character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each index i, we choose either A[i] or B[i].
 * Let x_i be the chosen value (0 or 1).
 * Score = sum(x_i) for i = 1 to N.
 * We want Score to be odd.
 * 
 * Let's categorize indices into three types:
 * 1. Both A[i] and B[i] are '0': We must choose '0'. Contribution to score is 0.
 * 2. Both A[i] and B[i] are '1': We must choose '1'. Contribution to score is 1.
 * 3. One is '0' and one is '1': We can choose either '0' or '1'.
 * 
 * Let 'fixed_ones' be the count of indices where both A[i] and B[i] are '1'.
 * Let 'flexible' be the count of indices where one is '0' and one is '1'.
 * 
 * If 'flexible' > 0, we can toggle the parity of the score by choosing '0' or '1' 
 * at any of these flexible positions. Thus, if 'flexible' > 0, we can always 
 * achieve an odd score.
 * 
 * If 'flexible' == 0, the score is fixed at 'fixed_ones'. We just check if 
 * 'fixed_ones' is odd.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int fixed_ones = 0;
    int flexible = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] == '1' && B[i] == '1') {
            fixed_ones++;
        } else if (A[i] != B[i]) {
            flexible++;
        }
    }

    if (flexible > 0) {
        cout << "YES" << "\n";
    } else {
        if (fixed_ones % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
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