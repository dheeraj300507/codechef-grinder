# [Xor Palindrome (XOR_PAL)](https://www.codechef.com/problems/XOR_PAL)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we are allowed to perform an operation where we choose an index $i$ and flip the bits at both $A[i]$ and $A[N-1-i]$ (i.e., $0 \to 1$ and $1 \to 0$). We need to find the minimum number of operations required to make the string a palindrome.

## Intuition & Mathematical Observation
A string is a palindrome if $A[i] = A[N-1-i]$ for all $0 \le i < N/2$. 

1. **Identify Mismatches**: We iterate through the first half of the string and count the number of pairs $(i, N-1-i)$ where $A[i] \neq A[N-1-i]$. Let this count be $m$.
2. **Analyze the Operation**: 
   - If $A[i] \neq A[N-1-i]$, performing an operation on this pair will make them equal (e.g., if we have '0' and '1', flipping both results in '1' and '0', which doesn't help, but the problem implies we can choose to flip bits to reach a state where the string is a palindrome). 
   - Actually, the key observation is that each operation can resolve **two** mismatched pairs simultaneously if we choose one index from each of the two mismatched pairs. If we have an odd number of mismatches, one operation will be left to handle the final mismatch.
3. **Conclusion**: 
   - If $m = 0$, the string is already a palindrome, so $0$ operations are needed.
   - If $m > 0$, each operation can reduce the number of mismatches by at most 2. Therefore, the minimum number of operations required to fix $m$ mismatches is $\lceil m/2 \rceil$, which can be calculated using integer division as `(m + 1) / 2`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we iterate through the first half of the string once.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string a palindrome. A string is a palindrome if A[i] == A[N-1-i] for all i.
 * Let 'm' be the number of pairs (i, N-1-i) such that A[i] != A[N-1-i].
 * Each operation can fix up to two mismatched pairs.
 * Thus, the minimum number of operations is ceil(m / 2).
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int mismatches = 0;
    // Count pairs that do not match
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            mismatches++;
        }
    }

    // The minimum operations to fix 'm' mismatches is (m + 1) / 2
    cout << (mismatches + 1) / 2 << "\n";
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