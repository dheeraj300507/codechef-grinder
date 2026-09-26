# [Approximate Answer (P1149)](https://www.codechef.com/problems/P1149)

- **Difficulty Rating**: 291
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $X$, $Y$, and $K$, determine if the absolute difference between $X$ and $Y$ is less than or equal to $K$. In mathematical terms, we need to check if $|X - Y| \le K$.

## Intuition & Mathematical Observation
The problem is a direct implementation of the absolute difference inequality. 
1. We are given $X$, $Y$, and $K$.
2. We calculate the difference $D = X - Y$.
3. We take the absolute value of $D$ (i.e., $|X - Y|$) to ensure the distance between the two numbers is positive, regardless of which one is larger.
4. We compare this value against $K$. If the condition holds, output "Yes"; otherwise, output "No".

Given the constraints ($1 \le X, Y, K \le 20$), standard integer types are more than sufficient to handle the calculations without overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations and a single comparison.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Approximate Answer
 * The problem asks to check if |X - Y| <= K.
 * Given constraints are small (1 <= X, Y, K <= 20), so standard integer types are sufficient.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y, K;
    // Read X, Y, and K from standard input
    if (cin >> X >> Y >> K) {
        // Calculate absolute difference
        long long diff = abs(X - Y);
        
        // Check condition |X - Y| <= K
        if (diff <= K) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```