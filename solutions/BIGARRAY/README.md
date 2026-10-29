# [Obtain the Sum (BIGARRAY)](https://www.codechef.com/problems/BIGARRAY)

- **Difficulty Rating**: 1368
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ containing all integers from $1$ to $N$ (i.e., $A = [1, 2, 3, \dots, N]$), we are given a target sum $S$. We need to find an element $x$ in the array such that the sum of all elements in the array excluding $x$ is exactly equal to $S$. If no such $x$ exists, output $-1$.

## Intuition & Mathematical Observation
The sum of the first $N$ natural numbers is given by the arithmetic series formula:
$$\text{TotalSum} = \frac{N \times (N + 1)}{2}$$

Let $x$ be the element removed from the array. The problem states that the sum of the remaining elements is $S$. Mathematically, this is expressed as:
$$\text{TotalSum} - x = S$$

Rearranging the equation to solve for $x$:
$$x = \text{TotalSum} - S$$

Since $x$ must be an element of the original array, it must satisfy the condition $1 \le x \le N$. If the calculated $x$ falls within this range, it is our answer; otherwise, no such element exists, and we output $-1$.

**Note on Data Types:**
Given $N \le 10^9$, $\text{TotalSum}$ can reach approximately $5 \times 10^{17}$. This fits within a standard 64-bit signed integer (`long long` in C++), which has a maximum value of approximately $9 \times 10^{18}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is defined as A[i] = i for 1 <= i <= N.
 * The sum of all elements in the array is TotalSum = N * (N + 1) / 2.
 * We are looking for an index x such that:
 * (Sum of all elements except A[x]) = S
 * (TotalSum - x) = S
 * Therefore, x = TotalSum - S.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;

        // Calculate the sum of the first N natural numbers
        // N=10^9, so N*(N+1)/2 fits in a 64-bit signed long long.
        long long total_sum = n * (n + 1) / 2;

        // The equation is: total_sum - x = s
        // So, x = total_sum - s
        long long x = total_sum - s;

        // Check if x is a valid element in the array [1, N]
        if (x >= 1 && x <= n) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```