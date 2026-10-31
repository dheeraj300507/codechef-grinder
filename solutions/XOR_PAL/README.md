# [Xor Palindrome (XOR_PAL)](https://www.codechef.com/problems/XOR_PAL)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we want to determine the minimum number of operations required to make the string a palindrome. In one operation, we can choose any index $i$ and flip the bit $A[i]$ (change $0$ to $1$ or $1$ to $0$). However, the problem implies we want to reach a state where the string is a palindrome using the minimum number of bit flips.

## Intuition & Mathematical Observation
1. **Identify Mismatches**: A string is a palindrome if $A[i] == A[N-1-i]$ for all $0 \le i < N/2$. We iterate through the first half of the string and count the number of pairs $(i, N-1-i)$ where $A[i] \neq A[N-1-i]$. Let this count be `diff`.
2. **The Core Logic**:
   - Each mismatched pair $(A[i], A[N-1-i])$ must be addressed. To make them equal, we must flip at least one of the two bits.
   - If we have `diff` mismatched pairs, we need to perform operations to resolve these differences.
   - One operation can resolve exactly two mismatched pairs if we flip one bit in each of the two pairs (e.g., changing a $0$ to $1$ in one pair and a $1$ to $0$ in another).
   - If `diff` is even, we can pair up the mismatches and resolve them in `diff / 2` operations.
   - If `diff` is odd, we resolve `diff - 1` mismatches in `(diff - 1) / 2` operations, and the final remaining mismatch requires $1$ additional operation.
   - Mathematically, both cases are covered by the formula: `(diff + 1) / 2`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the first half of the string exactly once.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string a palindrome. A string is a palindrome if A[i] == A[N-1-i] for all i.
 * Let 'diff' be the number of indices i < N/2 such that A[i] != A[N-1-i].
 * 
 * Each operation can fix at most two mismatched pairs by flipping one bit in each.
 * If we have 'diff' mismatches, the minimum number of operations required is ceil(diff / 2).
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int diff = 0;
    // Count how many pairs are currently not equal
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            diff++;
        }
    }

    // Each operation can fix 2 mismatched pairs.
    // If diff is odd, we need (diff/2) + 1 operations.
    // If diff is even, we need (diff/2) operations.
    // This is equivalent to (diff + 1) / 2.
    cout << (diff + 1) / 2 << "\n";
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