# [Minimum number of coins (MINCOINS)](https://www.codechef.com/problems/MINCOINS)

- **Difficulty Rating**: 711
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, determine the minimum number of coins required to form the sum $X$ using only 5-rupee and 10-rupee coins. If it is impossible to form the sum $X$ with these denominations, output -1.

## Intuition & Mathematical Observation
To minimize the total number of coins, we must prioritize using the largest denomination (10-rupee coins) as much as possible.

1.  **Divisibility Check**: Since both available coins (5 and 10) are multiples of 5, any sum $X$ that is not divisible by 5 cannot be formed. In such cases, we output -1.
2.  **Greedy Strategy**:
    *   If $X$ is divisible by 10, we can represent it entirely using 10-rupee coins. The number of coins is simply $X / 10$.
    *   If $X$ is not divisible by 10 but is divisible by 5 (i.e., $X \pmod{10} = 5$), we use as many 10-rupee coins as possible, leaving a remainder of 5. We then use exactly one 5-rupee coin to complete the sum. The number of coins is $(X / 10) + 1$.
3.  **Unified Logic**: The logic can be simplified: if $X \% 5 \neq 0$, return -1. Otherwise, the answer is $\lceil X / 10 \rceil$, which is equivalent to `(x / 10) + (x % 10 != 0)`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have coins of denominations 5 and 10.
 * To minimize the number of coins, we should use as many 10-rupee coins as possible.
 * 
 * Logic:
 * 1. If X is not divisible by 5, it is impossible to form the sum using only 5 and 10. Output -1.
 * 2. If X is divisible by 5:
 *    - We want to maximize the number of 10-rupee coins.
 *    - If X % 10 == 0: coins = X / 10
 *    - If X % 10 != 0: coins = (X / 10) + 1
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // If X is not divisible by 5, it's impossible
        if (x % 5 != 0) {
            cout << -1 << "\n";
        } else {
            // Calculate minimum coins
            // If X is a multiple of 10, we use only 10-rupee coins.
            // If X ends in 5, we use (X-5)/10 coins of 10 and one 5-rupee coin.
            int coins = x / 10;
            if (x % 10 != 0) {
                coins += 1;
            }
            cout << coins << "\n";
        }
    }

    return 0;
}
```