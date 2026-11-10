# [Min Max LCM (MINLCM1)](https://www.codechef.com/problems/MINLCM1)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $K$, we are asked to find the minimum and maximum possible values of $\text{LCM}(i, j)$ such that $X \le i < j \le X \cdot K$.

## Intuition & Mathematical Observation

### Minimum LCM
To minimize the Least Common Multiple of two numbers $i$ and $j$ in the range $[X, X \cdot K]$, we want $i$ and $j$ to be as small as possible and share a large common factor. 
- The smallest possible value for $i$ is $X$.
- The smallest possible value for $j$ is $X+1$. However, choosing $j = 2X$ allows for a very small LCM: $\text{LCM}(X, 2X) = 2X$.
- Since $K \ge 2$, the value $2X$ is always within the range $[X, X \cdot K]$. Any other pair $(i, j)$ would result in an LCM $\ge 2X$ (or would be equal to $2X$ if $i$ is a divisor of $j$). Thus, the minimum LCM is $2X$.

### Maximum LCM
To maximize the LCM, we want $i$ and $j$ to be as large as possible and share as few factors as possible (ideally, they should be coprime).
- Let $M = X \cdot K$ be the upper bound of our range.
- The two largest integers in the range are $M$ and $M-1$.
- Consecutive integers are always coprime, i.e., $\gcd(M, M-1) = 1$.
- The LCM of two coprime numbers is simply their product. Therefore, $\text{LCM}(M-1, M) = (M-1) \cdot M$.
- This is the largest possible product we can form using two numbers $\le M$, and since they are coprime, it is the maximum possible LCM.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X and K. The range is [X, X*K].
 * We need to find min and max LCM(i, j) where X <= i < j <= X*K.
 * 
 * Minimum LCM:
 * To minimize LCM(i, j), we want i and j to be as close as possible and share as many factors as possible.
 * The smallest possible LCM is obtained by picking i = X and j = 2*X.
 * LCM(X, 2*X) = 2*X. Since X >= 1, this is always valid as long as 2*X <= X*K (which is true since K >= 2).
 * 
 * Maximum LCM:
 * To maximize LCM(i, j), we want i and j to be as large as possible and share as few factors as possible (ideally coprime).
 * Let M = X * K. We want to pick two numbers close to M that are coprime.
 * The pair (M-1, M) are always coprime because gcd(M-1, M) = 1.
 * Thus, LCM(M-1, M) = (M-1) * M.
 * Since M = X * K, the maximum LCM is (X*K - 1) * (X*K).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, K;
        cin >> X >> K;

        // Minimum LCM:
        // Choosing i = X and j = 2*X gives LCM(X, 2*X) = 2*X.
        long long min_lcm = 2 * X;

        // Maximum LCM:
        // Let M = X * K. The largest possible values are M and M-1.
        // Since gcd(M, M-1) = 1, their LCM is M * (M-1).
        long long M = X * K;
        long long max_lcm = M * (M - 1);

        cout << min_lcm << " " << max_lcm << "\n";
    }

    return 0;
}
```