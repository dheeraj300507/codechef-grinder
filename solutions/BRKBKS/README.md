# [Breaking Bricks (BRKBKS)](https://www.codechef.com/problems/BRKBKS)

- **Difficulty Rating**: 1247
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a stack of three bricks with widths $W_1, W_2, W_3$ and a strength $S$. In one hit, you can break any number of consecutive bricks from the top of the stack, provided their total width does not exceed $S$. You are allowed to reverse the stack once at any time. The goal is to find the minimum number of hits required to break all three bricks.

## Intuition & Mathematical Observation
Since there are only three bricks, the number of possible configurations is very small. We can either break the bricks in the original order $(W_1, W_2, W_3)$ or the reversed order $(W_3, W_2, W_1)$.

For any given sequence $(a, b, c)$, we can determine the minimum hits using a greedy approach:
1. **One hit**: If $a + b + c \le S$, we can break all three at once.
2. **Two hits**: 
   - If $a + b \le S$, we break $(a, b)$ in the first hit and $(c)$ in the second.
   - If $b + c \le S$, we break $(a)$ in the first hit and $(b, c)$ in the second.
3. **Three hits**: If neither of the above conditions is met, we must break each brick individually.

By calculating the hits for both the original order and the reversed order and taking the minimum, we ensure the optimal strategy is found.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations and comparisons regardless of the input values, the complexity is constant.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and intermediate results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 3 bricks with widths W1, W2, W3 and strength S.
 * We can reverse the stack at any time.
 * We want to minimize the number of hits.
 * 
 * Since there are only 3 bricks, we can either:
 * 1. Try to break them in the order W1, W2, W3.
 * 2. Try to break them in the reversed order W3, W2, W1.
 */

int solve_hits(int S, int w1, int w2, int w3) {
    // Try to take all in one hit
    if (w1 + w2 + w3 <= S) {
        return 1;
    }
    // Try to take two in the first hit or two in the second hit
    if (w1 + w2 <= S || w2 + w3 <= S) {
        return 2;
    }
    // Worst case: 3 hits
    return 3;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int S, W1, W2, W3;
        cin >> S >> W1 >> W2 >> W3;

        // Option 1: Order W1, W2, W3
        int hits1 = solve_hits(S, W1, W2, W3);
        
        // Option 2: Order W3, W2, W1 (Reversed)
        int hits2 = solve_hits(S, W3, W2, W1);

        cout << min(hits1, hits2) << "\n";
    }

    return 0;
}
```