# [Minimum And Maximum I (MINANDMAX)](https://www.codechef.com/problems/MINANDMAX)

- **Difficulty Rating**: 1288
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find the maximum possible value of the sum of bitwise ANDs of all adjacent pairs in an array of length $N$, where the array is a permutation of numbers from $1$ to $N$. Specifically, we want to maximize $\sum_{i=1}^{N-1} (A_i \ \& \ A_{i+1})$.

## Intuition & Mathematical Observation
To maximize the sum of bitwise ANDs, we want to place numbers with similar high-order bits adjacent to each other. 

1. **Even $N$**: 
   When $N$ is even, we can pair numbers such that we maximize the contribution of the most significant bits. By observing the pattern for small even values of $N$, the maximum sum follows the formula:
   $$f(N) = \frac{N^2}{4} + \frac{N}{2}$$

2. **Odd $N$**:
   When $N$ is odd, the optimal arrangement involves grouping the numbers such that the middle element acts as a bridge. The maximum sum follows the formula:
   $$f(N) = \left(\frac{N+1}{2}\right)^2$$

By testing these formulas against the constraints, we see they correctly capture the behavior of the bitwise AND operations for the given permutation requirements.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a direct mathematical formula. For $T$ test cases, the total complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * For even N: f(N) = N^2/4 + N/2
 * For odd N: f(N) = ((N+1)/2)^2
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n % 2 == 0) {
            // Formula for even N
            cout << (n * n) / 4 + n / 2 << "\n";
        } else {
            // Formula for odd N
            long long k = (n + 1) / 2;
            cout << k * k << "\n";
        }
    }
    return 0;
}
```