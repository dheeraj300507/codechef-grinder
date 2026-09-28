# [Chef and Strings (CHEFSTR1)](https://www.codechef.com/problems/CHEFSTR1)

- **Difficulty Rating**: 1094
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ strings, where the $i$-th string has a length of $S_i$. Chef moves from string $i$ to string $i+1$. When moving between two strings of lengths $S_i$ and $S_{i+1}$, Chef skips all strings that have lengths strictly between $S_i$ and $S_{i+1}$. We need to calculate the total number of strings skipped across all $N-1$ transitions.

## Intuition & Mathematical Observation
To move from a string of length $S_i$ to $S_{i+1}$, the number of integers strictly between these two values is given by the formula:
$$\text{skipped} = |S_{i+1} - S_i| - 1$$

*   If $|S_{i+1} - S_i| \le 1$, the number of skipped strings is 0 (e.g., moving from length 5 to 6 skips nothing).
*   Since $N$ can be up to $10^5$ and the values of $S_i$ up to $10^6$, the total sum of skipped strings can exceed the capacity of a 32-bit integer. Therefore, we must use a `long long` data type in C++ to store the cumulative sum to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of strings exactly once. With $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the input array. This can be further optimized to $O(1)$ by processing the input values on the fly without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To move from string S_i to S_{i+1}, the number of strings skipped is:
 * |S_{i+1} - S_i| - 1.
 * 
 * We need to sum this value for all i from 0 to N-2.
 * Total = sum_{i=0}^{N-2} (|S_{i+1} - S_i| - 1)
 * 
 * Constraints:
 * T <= 10
 * N <= 10^5
 * S_i <= 10^6
 * The total sum can exceed the range of a 32-bit integer, so we use long long.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    
    long long total_skipped = 0;
    for (int i = 0; i < N - 1; ++i) {
        long long diff = abs(S[i+1] - S[i]);
        if (diff > 0) {
            total_skipped += (diff - 1);
        }
    }
    
    cout << total_skipped << "\n";
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