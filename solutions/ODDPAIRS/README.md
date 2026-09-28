# [Odd Pairs (ODDPAIRS)](https://www.codechef.com/problems/ODDPAIRS)

- **Difficulty Rating**: 1044
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find the number of pairs $(A, B)$ such that $1 \le A, B \le N$ and the sum $A + B$ is odd.

## Intuition & Mathematical Observation
For the sum of two integers $A$ and $B$ to be odd, one must be **even** and the other must be **odd**. 

In the range $[1, N]$:
1. The number of **odd** integers is given by $\lceil N/2 \rceil$, which can be calculated as `(N + 1) / 2`.
2. The number of **even** integers is given by $\lfloor N/2 \rfloor$, which can be calculated as `N / 2`.

Let $O$ be the count of odd numbers and $E$ be the count of even numbers. The total number of pairs $(A, B)$ with an odd sum is:
- Case 1: $A$ is odd and $B$ is even $\rightarrow O \times E$ pairs.
- Case 2: $A$ is even and $B$ is odd $\rightarrow E \times O$ pairs.

Thus, the total number of valid pairs is $2 \times O \times E$. Since $N$ can be as large as $10^9$, the product $O \times E$ can reach $\approx 2.5 \times 10^{17}$, which exceeds the capacity of a 32-bit integer. Therefore, we must use `long long` in C++ to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the counts and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the number of pairs (A, B) such that 1 <= A, B <= N and A + B is odd.
 * A + B is odd if and only if one of the numbers is even and the other is odd.
 * 
 * In the range [1, N]:
 * - Number of odd integers: ceil(N / 2) = (N + 1) / 2
 * - Number of even integers: floor(N / 2) = N / 2
 * 
 * Let 'odd_count' be the number of odd integers and 'even_count' be the number of even integers.
 * A pair (A, B) has an odd sum if:
 * 1. A is odd and B is even: There are (odd_count * even_count) such pairs.
 * 2. A is even and B is odd: There are (even_count * odd_count) such pairs.
 * 
 * Total pairs = 2 * (odd_count * even_count)
 * 
 * Constraints: N <= 10^9, so N*N can exceed 2^31-1. We must use long long.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long odd_count = (n + 1) / 2;
        long long even_count = n / 2;

        // The number of pairs is 2 * (odd * even)
        long long result = 2 * odd_count * even_count;

        cout << result << "\n";
    }

    return 0;
}
```