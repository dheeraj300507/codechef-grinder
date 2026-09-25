# [Break the Stick (BREAKSTICK)](https://www.codechef.com/problems/BREAKSTICK)

- **Difficulty Rating**: 1026
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a stick of length $N$ and we want to determine if it is possible to obtain a stick of length $X$ by repeatedly breaking sticks. The rule for breaking a stick of length $L$ is that it must be broken into $k$ parts ($k \ge 2$) such that all parts have the same parity (all odd or all even).

## Intuition & Mathematical Observation
To solve this, we analyze the parity of $N$ and $X$:

1.  **Case 1: $X$ is odd**
    *   If $N$ is odd, we can break $N$ into $X$ and $(N-X)$. Since $N$ and $X$ are both odd, $(N-X)$ is even. This doesn't immediately work, but we can break $N$ into $N$ parts of length $1$. Since $1$ is odd, we can obtain any odd length $X \le N$.
    *   If $N$ is even, we can break $N$ into $X$ and $(N-X)$. Since $N$ is even and $X$ is odd, $(N-X)$ is odd. Now we have two parts of odd length ($X$ and $N-X$), which satisfies the condition.
    *   **Conclusion**: If $X$ is odd, the answer is always **YES**.

2.  **Case 2: $X$ is even**
    *   If $N$ is odd, any partition of $N$ into parts of the same parity must consist of odd parts (because if the parts were even, their sum would be even, contradicting that $N$ is odd). Thus, we can never obtain an even length $X$ from an odd $N$.
    *   If $N$ is even, we can break $N$ into $X$ and $(N-X)$. Since $N$ and $X$ are both even, $(N-X)$ is also even. This satisfies the condition.
    *   **Conclusion**: If $X$ is even, the answer is **YES** if $N$ is even, and **NO** if $N$ is odd.

**Simplified Logic**: The answer is "YES" if $X$ is odd OR $N$ is even. Otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ time using simple arithmetic checks.
- **Space Complexity**: $O(1)$, as we only use a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * If X is odd: YES
 * If X is even: YES if N is even, NO if N is odd.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (x % 2 != 0) {
            // If X is odd, we can always achieve it
            cout << "YES" << "\n";
        } else {
            // If X is even, we can only achieve it if N is even
            if (n % 2 == 0) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}
```