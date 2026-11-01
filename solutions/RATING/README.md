# [The Rating Dilemma (RATING)](https://www.codechef.com/problems/RATING)

- **Difficulty Rating**: 909
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an integer $S$, which represents the sum of two integers $X$ and $Y$ ($S = X + Y$). We are given the constraints that $X > 0$ and $Y < 0$. The goal is to find the values of $X$ and $Y$ that maximize the product $P = X \times Y$.

## Intuition & Mathematical Observation
To maximize the product $P = X \times Y$ given $X + Y = S$, we can substitute $Y = S - X$:
$$P = X(S - X) = SX - X^2$$

This is a downward-opening parabola. However, we are constrained by $Y < 0$. Since $Y = S - X$, the condition $Y < 0$ implies $S - X < 0$, or $X > S$.

To maximize the product $P = X \times Y$ where $Y$ is negative, we want the absolute value of $Y$ to be as small as possible (i.e., $Y$ should be as close to $0$ as possible). The largest possible negative integer for $Y$ is $-1$.

If we set $Y = -1$:
1. $X + (-1) = S \implies X = S + 1$.
2. Since $S$ is at least $-10^9$ (based on typical constraints for this problem type), $X = S + 1$ will always be greater than $0$, satisfying the constraint $X > 0$.
3. The product becomes $P = (S + 1) \times (-1) = -S - 1$.

Thus, for any given $S$, the maximum product is always $-S - 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given S = X + Y, where X > 0 and Y < 0.
 * We want to maximize the product P = X * Y.
 * To maximize the product where one factor is negative, we make the negative 
 * factor as close to 0 as possible. The largest negative integer is -1.
 * Setting Y = -1, we get X = S + 1.
 * Product = (S + 1) * (-1) = -S - 1.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long s;
        cin >> s;
        
        // The maximum product is achieved when Y = -1 and X = S + 1
        long long result = -s - 1;
        cout << result << "\n";
    }
    
    return 0;
}
```