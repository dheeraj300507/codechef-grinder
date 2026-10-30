# [Multiple of 3 (MULT3)](https://www.codechef.com/problems/MULT3)

- **Difficulty Rating**: 297
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a positive integer $N$, the goal is to find the nearest multiple of 3. If there are two multiples of 3 equidistant from $N$, the problem implies choosing the one that results in the smallest absolute difference.

## Intuition & Mathematical Observation
To find the nearest multiple of 3, we examine the remainder of $N$ when divided by 3 ($N \pmod 3$):

1.  **If $N \pmod 3 = 0$**: $N$ is already a multiple of 3. The distance is 0, so the nearest multiple is $N$ itself.
2.  **If $N \pmod 3 = 1$**: The two closest multiples are $(N-1)$ and $(N+2)$. The distance to $(N-1)$ is 1, while the distance to $(N+2)$ is 2. Therefore, $(N-1)$ is the nearest multiple.
3.  **If $N \pmod 3 = 2$**: The two closest multiples are $(N-2)$ and $(N+1)$. The distance to $(N-2)$ is 2, while the distance to $(N+1)$ is 1. Therefore, $(N+1)$ is the nearest multiple.

This logic covers all positive integers $N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations and conditional checks regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a single variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the nearest multiple of 3 for a given integer N.
 * 
 * For any integer N:
 * 1. If N % 3 == 0, the nearest multiple is N itself.
 * 2. If N % 3 == 1, the nearest multiple is (N-1).
 * 3. If N % 3 == 2, the nearest multiple is (N+1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    // Read input N
    if (!(cin >> n)) return 0;

    long long remainder = n % 3;

    if (remainder == 0) {
        cout << n << "\n";
    } else if (remainder == 1) {
        cout << (n - 1) << "\n";
    } else {
        // remainder == 2
        cout << (n + 1) << "\n";
    }

    return 0;
}
```