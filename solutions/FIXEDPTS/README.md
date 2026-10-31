# [Fixed Points (FIXEDPTS)](https://www.codechef.com/problems/FIXEDPTS)

- **Difficulty Rating**: 884
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $N$ (the length of a permutation) and an integer $K$, determine if it is possible to construct a permutation $P$ of length $N$ such that there are exactly $K$ fixed points. A fixed point is defined as an index $i$ such that $P[i] = i$.

## Intuition & Mathematical Observation
To have exactly $K$ fixed points in a permutation of length $N$:
1. We must select $K$ indices to be fixed points ($P[i] = i$).
2. The remaining $M = N - K$ elements must be arranged such that **none** of them are fixed points. This is known as a **derangement**.

We analyze the feasibility of the remaining $M$ elements:
- If $M = 0$: We have 0 elements left to arrange. This is valid (0 fixed points added).
- If $M = 1$: We have 1 element left. Since there is only one position available for it, it **must** be a fixed point. This would result in $K+1$ fixed points instead of $K$. Thus, $M=1$ is impossible.
- If $M \ge 2$: A derangement always exists for any set of 2 or more elements (e.g., swapping two elements).

**Conclusion:** The only impossible case is when $N - K = 1$, which simplifies to $K = N - 1$. For all other values of $K$ (where $0 \le K \le N$), it is possible to construct the permutation.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * To have exactly K fixed points:
 * 1. We choose K indices to be fixed (P[i] = i).
 * 2. The remaining (N - K) elements must form a derangement (no element i is at position i).
 * 
 * A derangement of size M exists if and only if M != 1.
 * - If M = 0: A derangement exists (the empty set).
 * - If M = 1: No derangement exists (the single element must be at its own position).
 * - If M >= 2: A derangement always exists.
 * 
 * Therefore, the condition is simply N - K != 1, which is equivalent to K != N - 1.
 */

int main() {
    // Optimize standard I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0;
    while (t--) {
        int n, k;
        std::cin >> n >> k;

        // If N - K == 1, we are forced to have one extra fixed point.
        // Otherwise, it is always possible.
        if (k == n - 1) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }

    return 0;
}
```