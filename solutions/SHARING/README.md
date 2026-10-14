# [Sharing Cookies (SHARING)](https://www.codechef.com/problems/SHARING)

- **Difficulty Rating**: 232
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has $A$ cookies and Bob has $B$ cookies, where $A > B$. Alice wants to give $x$ cookies to Bob such that they both end up with the same number of cookies. We need to find the value of $x$ if it is possible, or output -1 if it is not.

## Intuition & Mathematical Observation
To make the number of cookies equal, we set up the following equation:
$$A - x = B + x$$

Rearranging the terms to solve for $x$:
$$A - B = 2x$$
$$x = \frac{A - B}{2}$$

From this equation, we can derive two conditions for a valid solution:
1. **Integer Constraint**: Since $x$ must be a whole number of cookies, $(A - B)$ must be divisible by 2. In other words, $(A - B) \pmod 2$ must be $0$.
2. **Positivity**: Since the problem states $A > B$, $A - B$ will always be positive, ensuring $x > 0$.

If $(A - B)$ is odd, it is impossible to distribute the cookies equally, so we output `-1`. Otherwise, we output the result of $(A - B) / 2$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A cookies, Bob has B cookies. A > B.
 * Let x be the number of cookies Alice gives to Bob.
 * After the transfer:
 * Alice has A - x cookies.
 * Bob has B + x cookies.
 * For them to be equal: A - x = B + x
 * A - B = 2x
 * x = (A - B) / 2
 * 
 * For x to be a valid number of cookies (an integer), (A - B) must be even.
 * Given A > B, A - B is always > 0.
 * Thus, the condition is simply: (A - B) % 2 == 0.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    if (!(cin >> A >> B)) return 0;

    // Check if the difference is even
    if ((A - B) % 2 == 0) {
        cout << (A - B) / 2 << "\n";
    } else {
        // If odd, it's impossible to split equally
        cout << -1 << "\n";
    }

    return 0;
}
```