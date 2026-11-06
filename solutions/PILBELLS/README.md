# [Bells of Pilgrimage (PILBELLS)](https://www.codechef.com/problems/PILBELLS)

- **Difficulty Rating**: 885
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a scenario where a traveler rings $K$ bells out of a total of $N$ bells. The traveler starts with an initial mana of $P$. The rules for gaining mana are as follows:
1. The first $X$ bells ring provide **10 mana** each.
2. Any bells rung after the first $X$ (i.e., from $X+1$ to $K$) provide **5 mana** each.
3. If the traveler rings all $N$ bells (i.e., $K = N$), they receive a **bonus of 20 mana**.

The goal is to calculate the final mana after ringing $K$ bells.

## Intuition & Mathematical Observation
The problem can be broken down into three distinct parts:
1. **Initial Mana**: Start with the base value $P$.
2. **Incremental Mana**:
   - If $K \le X$, the traveler only rings bells that grant 10 mana. Total added: $K \times 10$.
   - If $K > X$, the traveler rings all $X$ bells (granting $X \times 10$) plus the remaining $(K - X)$ bells (granting $(K - X) \times 5$).
3. **Bonus**: A simple conditional check: if $K == N$, add 20 to the total.

Since the constraints for $N, X, P$ are up to $10^5$, the maximum possible mana will not exceed $10^5 + (10^5 \times 10) + 20 \approx 1.1 \times 10^6$. While this fits in a standard 32-bit `int`, using `long long` is a good practice to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations regardless of the input size, the complexity is constant.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input and the result, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial mana: P
 * First X bells: +10 each
 * Remaining bells: +5 each
 * If K == N: +20 bonus
 */

void solve() {
    long long N, X, K, P;
    cin >> N >> X >> K >> P;

    long long current_mana = P;

    if (K <= X) {
        // Only bells with 10 mana were rung
        current_mana += (K * 10);
    } else {
        // First X bells give 10 each, remaining (K - X) give 5 each
        current_mana += (X * 10);
        current_mana += ((K - X) * 5);
    }

    // Bonus for ringing all bells
    if (K == N) {
        current_mana += 20;
    }

    cout << current_mana << "\n";
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