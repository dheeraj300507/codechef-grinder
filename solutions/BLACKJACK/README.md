# [Blackjack (BLACKJACK)](https://www.codechef.com/problems/BLACKJACK)

- **Difficulty Rating**: 681
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is playing a game where he has two cards with values $A$ and $B$. To win, the sum of his cards must be exactly 21. We need to determine if there exists a third card $X$ (where $1 \le X \le 10$) such that $A + B + X = 21$. If such an $X$ exists, output it; otherwise, output $-1$.

## Intuition & Mathematical Observation
The problem asks us to satisfy the equation:
$$A + B + X = 21$$

By rearranging the equation to solve for $X$, we get:
$$X = 21 - (A + B)$$

Since the rules of the game specify that the third card $X$ must be between 1 and 10 inclusive ($1 \le X \le 10$), we simply need to calculate $X$ and verify if it falls within this range. If it does, $X$ is our answer. If the calculated $X$ is less than 1 or greater than 10, it is impossible to reach exactly 21 with a single card, so we output $-1$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two numbers A and B.
 * We need to find a third number X such that A + B + X = 21.
 * This implies X = 21 - (A + B).
 * The constraint on X is 1 <= X <= 10.
 * If the calculated X satisfies this constraint, we output X.
 * Otherwise, we output -1.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int sum_ab = a + b;
        int x = 21 - sum_ab;
        
        // Check if the required third number is within the valid range [1, 10]
        if (x >= 1 && x <= 10) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}
```