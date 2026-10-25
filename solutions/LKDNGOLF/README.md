# [Golf (LKDNGOLF)](https://www.codechef.com/problems/LKDNGOLF)

- **Difficulty Rating**: 1256
- **Solved in**: 1 attempt(s)

## Problem Summary
The golf course consists of tiles numbered from $0$ to $N+1$. A ball is hit forward, landing on tiles $0, k, 2k, \dots$ until it reaches or exceeds $N+1$. Then, it is hit backward from $N+1$, landing on tiles $(N+1), (N+1)-k, (N+1)-2k, \dots$ until it reaches or goes below $0$. Given the target tile $x$, determine if the ball lands on it during either the forward or backward journey.

## Intuition & Mathematical Observation
The problem can be broken down into two independent conditions based on the direction of the ball:

1.  **Forward Journey**: The ball lands on tiles $x$ such that $x$ is a multiple of $k$. Mathematically, this is true if:
    $$x \pmod k = 0$$

2.  **Backward Journey**: The ball starts at $N+1$ and moves in steps of $k$ backwards. The ball lands on tile $x$ if the distance between $N+1$ and $x$ is a multiple of $k$. Mathematically, this is true if:
    $$(N + 1 - x) \pmod k = 0$$

If either of these conditions is satisfied, the ball lands on tile $x$. Since the constraints for $N, x,$ and $k$ go up to $10^9$, we use `long long` to ensure no overflow occurs during calculations, although standard 32-bit integers would technically suffice for these specific operations.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The hallway has tiles 0 to N+1.
 * Forward journey: The ball lands on tiles 0, k, 2k, ..., mk such that mk <= N+1.
 * This means the ball lands on tile x if x % k == 0.
 * 
 * Backward journey: The ball starts at N+1 and lands on (N+1), (N+1)-k, (N+1)-2k, ...
 * This means the ball lands on tile x if (N+1 - x) % k == 0.
 * 
 * We need to check if (x % k == 0) OR ((N + 1 - x) % k == 0).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        // Check forward journey: x is a multiple of k
        bool forward = (x % k == 0);
        
        // Check backward journey: (N + 1 - x) is a multiple of k
        bool backward = ((n + 1 - x) % k == 0);

        if (forward || backward) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```