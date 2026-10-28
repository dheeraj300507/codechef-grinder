# [Odd Repeat (REPEAT)](https://www.codechef.com/problems/REPEAT)

- **Difficulty Rating**: 1218
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array containing the first $N$ positive odd numbers. However, one specific odd number $x$ is repeated $K$ times instead of appearing once, while all other $N-1$ odd numbers appear exactly once. Given the total sum $S$ of the elements in this array, we need to identify the value of the repeated number $x$.

## Intuition & Mathematical Observation
1. **Sum of first $N$ odd numbers**: The sequence of the first $N$ odd numbers is $1, 3, 5, \dots, (2N-1)$. The sum of this arithmetic progression is known to be $N^2$.
2. **Formulating the total sum $S$**:
   - The original sum of the first $N$ odd numbers is $N^2$.
   - In the modified array, the number $x$ is added $K$ times instead of once.
   - Therefore, we remove one instance of $x$ from the original sum and add $K$ instances of $x$.
   - The equation for the total sum $S$ is:
     $$S = N^2 - x + (K \cdot x)$$
     $$S = N^2 + x(K - 1)$$
3. **Solving for $x$**:
   - Rearranging the equation to isolate $x$:
     $$x(K - 1) = S - N^2$$
     $$x = \frac{S - N^2}{K - 1}$$

Since $N, K,$ and $S$ are provided, we can directly compute $x$ using this formula.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N positive odd numbers are 1, 3, 5, ..., (2N - 1).
 * The sum of the first N odd numbers is N^2.
 * 
 * Let x be the number that appears K times.
 * The other (N - 1) numbers appear exactly once.
 * The total sum S is given by:
 * S = (Sum of all first N odd numbers) - x + (K * x)
 * S = N^2 - x + K * x
 * S = N^2 + x * (K - 1)
 * 
 * Rearranging to solve for x:
 * x * (K - 1) = S - N^2
 * x = (S - N^2) / (K - 1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, s;
        cin >> n >> k >> s;

        // Calculate N^2
        long long n_squared = n * n;

        // Calculate the repeated number x
        // x = (S - N^2) / (K - 1)
        long long x = (s - n_squared) / (k - 1);

        cout << x << "\n";
    }

    return 0;
}
```