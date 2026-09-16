# [Minimum Coins (MINCOINSREQ)](https://www.codechef.com/problems/MINCOINSREQ)

- **Difficulty Rating**: 390
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to pay exactly $X$ rupees. He has an unlimited supply of 10-rupee notes and 1-rupee coins. The goal is to determine the **minimum number of 1-rupee coins** required to make the payment.

## Intuition & Mathematical Observation
To minimize the number of coins used, we must maximize the use of the higher-denomination currency (the 10-rupee notes). 

1. Any amount $X$ can be represented as: $X = (10 \times A) + (1 \times B)$, where $A$ is the number of 10-rupee notes and $B$ is the number of 1-rupee coins.
2. To minimize $B$, we should make $A$ as large as possible.
3. By dividing $X$ by 10, the quotient represents the maximum number of 10-rupee notes we can use.
4. The remainder of this division ($X \pmod{10}$) represents the amount that cannot be covered by 10-rupee notes and must therefore be paid using 1-rupee coins.
5. Thus, the minimum number of 1-rupee coins required is simply $X \pmod{10}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the modulo operation is a constant-time arithmetic operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has coins of value 1 and notes of value 10.
 * We want to pay exactly X rupees using the minimum number of coins.
 * To minimize the number of coins, we should maximize the use of 10-rupee notes.
 * The number of 10-rupee notes used will be floor(X / 10).
 * The remaining amount, which must be paid in 1-rupee coins, is X % 10.
 * Therefore, the minimum number of coins is simply X % 10.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        // The number of 1-rupee coins needed is the remainder when X is divided by 10.
        // Since 10-rupee notes cover the maximum possible value without using coins,
        // the remainder is the minimum number of coins required.
        long long min_coins = x % 10;
        
        cout << min_coins << "\n";
    }
    
    return 0;
}
```