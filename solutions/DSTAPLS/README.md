# [Distribute Apples (DSTAPLS)](https://www.codechef.com/problems/DSTAPLS)

- **Difficulty Rating**: 1374
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ apples and $K$ boxes. Two candidates distribute the apples:
1. **Candidate 1:** Distributes apples one by one into each box in a round-robin fashion. This results in every box receiving exactly $N/K$ apples.
2. **Candidate 2:** Distributes apples in batches of $K$ into boxes. Specifically, they fill one box with $K$ apples, then move to the next, and so on.

We need to determine if the final distribution of apples in the boxes is identical for both candidates.

## Intuition & Mathematical Observation
Let $M = N/K$ be the number of apples each box receives under Candidate 1.

For Candidate 2, the apples are distributed in batches of $K$. Since there are $K$ boxes, the candidate completes a full cycle of filling every box once every $K$ batches.
- If $M$ (the total number of batches) is a multiple of $K$, then every box will have been filled exactly $M/K$ times. Since each fill adds $K$ apples, each box ends up with $(M/K) \times K = M$ apples. In this case, the distributions are identical.
- If $M$ is **not** a multiple of $K$, then some boxes will receive more batches than others, leading to an uneven distribution where some boxes have more apples than others.

Thus, the distributions are the same if and only if $(N/K)$ is divisible by $K$.
Mathematically, the condition for "YES" (distributions are different) is:
$$(N/K) \pmod K \neq 0$$
Conversely, if $(N/K) \pmod K == 0$, the distributions are the same ("NO").

**Note on Constraints:** Since $N$ and $K$ can be up to $10^{18}$, we use `long long` in C++. We avoid calculating $K^2$ directly to prevent potential overflow, instead calculating $M = N/K$ and checking $M \% K$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

/**
 * Problem Analysis:
 * Total apples = N, Total boxes = K.
 * Candidate 1: Puts 1 apple in each of the K boxes, repeating this N/K times.
 * Result 1: Every box gets exactly (N/K) apples.
 * 
 * Candidate 2: Puts K apples into a single box at a time.
 * Total rounds = N/K. In each round, the candidate picks a box with the minimum number of apples.
 * Let M = N/K be the number of rounds.
 * If M is a multiple of K, then in each round, the candidate will eventually fill each box 
 * exactly (M/K) times. Since each time they add K apples, each box will end up with 
 * (M/K) * K = M = N/K apples. This matches Candidate 1.
 * 
 * If M is NOT a multiple of K, the distribution will be uneven. 
 * Therefore, the distributions are the same if and only if (N/K) is divisible by K.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate apples per box for Candidate 1
        long long m = n / k;
        
        // If m is divisible by k, distributions are the same (NO)
        // Otherwise, they are different (YES)
        if (m % k == 0) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }

    return 0;
}
```