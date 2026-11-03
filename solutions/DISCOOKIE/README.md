# [Distribute Cookies (DISCOOKIE)](https://www.codechef.com/problems/DISCOOKIE)

- **Difficulty Rating**: 932
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ kids and $M$ cookies. We need to reach a total number of cookies $K$ such that $K$ is a multiple of $N$ and $K \ge N$ (since every kid must receive at least one cookie). We want to find the minimum number of operations (adding or removing cookies) to reach such a $K$.

## Intuition & Mathematical Observation
The problem asks us to find a multiple of $N$ that is closest to $M$, with the constraint that the multiple must be at least $N$.

1.  **Case 1: $M < N$**
    Since we must have at least $N$ cookies, we cannot decrease the number of cookies. The closest valid multiple of $N$ is $N$ itself. Therefore, the cost is simply $N - M$.

2.  **Case 2: $M \ge N$**
    We have two potential candidates for the target $K$:
    *   **Rounding Down:** The largest multiple of $N$ less than or equal to $M$ is $K_1 = (M / N) \times N$. The cost to reach this is $M \pmod N$. Since $M \ge N$, $K_1$ will always be $\ge N$ (unless $M < N$, which is handled in Case 1).
    *   **Rounding Up:** The smallest multiple of $N$ greater than or equal to $M$ is $K_2 = \lceil M/N \rceil \times N$. The cost to reach this is $N - (M \pmod N)$.
    
    We compare these two costs and take the minimum: `min(M % N, N - (M % N))`. Note that if $M$ is already a multiple of $N$, $M \pmod N$ is $0$, and the cost is $0$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N kids and M cookies. We need to reach a total number of cookies K
 * such that K is a multiple of N (K % N == 0) and K >= N.
 * 
 * 1. If M < N:
 *    We must increase cookies to N. Cost = N - M.
 * 2. If M >= N:
 *    We can either decrease to the nearest multiple (M % N) or increase to the 
 *    next multiple (N - (M % N)). We take the minimum of these two.
 */

void solve() {
    long long N, M;
    cin >> N >> M;

    if (M < N) {
        // Must reach at least N cookies
        cout << (N - M) << "\n";
    } else {
        long long rem = M % N;
        if (rem == 0) {
            // Already a multiple of N
            cout << 0 << "\n";
        } else {
            // Option 1: Destroy 'rem' cookies to reach (M/N)*N
            // Option 2: Create 'N - rem' cookies to reach ((M/N)+1)*N
            cout << min(rem, N - rem) << "\n";
        }
    }
}

int main() {
    // Fast I/O
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