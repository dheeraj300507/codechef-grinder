# [Mean and Median (MEANMEDIAN)](https://www.codechef.com/problems/MEANMEDIAN)

- **Difficulty Rating**: 1371
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$, we need to find three integers $A, B,$ and $C$ such that:
1. The mean of $A, B,$ and $C$ is $X$. That is, $\frac{A+B+C}{3} = X$, or $A+B+C = 3X$.
2. The median of $A, B,$ and $C$ is $Y$.

## Intuition & Mathematical Observation
To satisfy the mean condition, the sum of the three numbers must be $3X$. To satisfy the median condition, we can fix the median to be $Y$. 

Let's set $A = Y$ and $B = Y$. 
Substituting these into the mean equation:
$Y + Y + C = 3X$
$2Y + C = 3X$
$C = 3X - 2Y$

Now, we verify if $Y$ is indeed the median of $\{Y, Y, 3X - 2Y\}$:
- If $3X - 2Y \ge Y$, the sorted order is $Y, Y, 3X - 2Y$. The median is $Y$.
- If $3X - 2Y < Y$, the sorted order is $3X - 2Y, Y, Y$. The median is $Y$.

In both cases, the median is $Y$ and the mean is $X$. This construction is valid for any $X$ and $Y$ provided by the problem constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only store a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find A, B, C such that:
 * 1. (A + B + C) / 3 = X  => A + B + C = 3 * X
 * 2. Median(A, B, C) = Y
 * 
 * By setting A = Y and B = Y, the equation becomes:
 * Y + Y + C = 3 * X
 * C = 3 * X - 2 * Y
 * 
 * The set {Y, Y, 3*X - 2*Y} will always have Y as the median.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    
    // We set two numbers to Y, and the third to satisfy the mean condition.
    long long A = Y;
    long long B = Y;
    long long C = 3 * X - 2 * Y;
    
    cout << A << " " << B << " " << C << "\n";
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