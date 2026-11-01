# [Origin (OG)](https://www.codechef.com/problems/OG)

- **Difficulty Rating**: 1309
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the sum of the "origins" of all integers from $1$ to $N$. The "origin" of a number is defined as the result of repeatedly summing its digits until a single-digit number is obtained. This is mathematically known as the **digital root**.

## Intuition & Mathematical Observation
The digital root of a positive integer $n$ follows a repeating pattern of length 9:
- $1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, \dots$

Because the sequence is periodic with a period of 9, we can calculate the sum efficiently without iterating through every number:
1. **Full Periods**: Every block of 9 consecutive numbers sums to $1+2+3+4+5+6+7+8+9 = 45$. If $N$ is the upper bound, there are $q = \lfloor N / 9 \rfloor$ full periods.
2. **Remainder**: After accounting for the full periods, there are $r = N \pmod 9$ remaining numbers. These numbers will be $1, 2, \dots, r$. The sum of these numbers is the sum of the first $r$ natural numbers, given by the formula $\frac{r(r+1)}{2}$.
3. **Total Sum**: The final result is $(q \times 45) + \frac{r(r+1)}{2}$.

Given that $N$ can be as large as $10^{18}$, using this $O(1)$ mathematical approach is necessary to avoid Time Limit Exceeded (TLE) errors.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations regardless of the size of $N$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "origin" of a number is equivalent to its digital root.
 * The digital root of a positive integer n is given by:
 * dr(n) = 1 + ((n - 1) % 9)
 * 
 * The sequence of origins for n = 1, 2, 3, ... is:
 * 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, ...
 * This is a periodic sequence with period 9.
 * 
 * To find the sum of origins from 1 to N:
 * 1. The number of full periods of (1, 2, ..., 9) is q = N / 9.
 * 2. The sum of one full period is 1+2+3+4+5+6+7+8+9 = 45.
 * 3. The remainder is r = N % 9.
 * 4. The sum of the first r elements is r * (r + 1) / 2.
 * 
 * Total sum = (q * 45) + (r * (r + 1) / 2).
 * 
 * Constraints: N up to 10^18, so we must use long long.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;

        long long q = n / 9;
        long long r = n % 9;

        // Sum of full periods (each sum is 45)
        long long total_sum = q * 45;

        // Sum of the remaining r elements (1, 2, ..., r)
        // Sum = r * (r + 1) / 2
        total_sum += (r * (r + 1)) / 2;

        cout << total_sum << "\n";
    }

    return 0;
}
```