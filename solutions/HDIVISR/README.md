# [Highest Divisor (HDIVISR)](https://www.codechef.com/problems/HDIVISR)

- **Difficulty Rating**: 860
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$ ($2 \le N \le 1000$), the task is to find the largest integer $x$ in the range $[1, 10]$ such that $N$ is divisible by $x$ (i.e., $N \pmod x = 0$).

## Intuition & Mathematical Observation
Since the range of possible divisors is extremely small (only integers from 1 to 10), we do not need to perform complex prime factorization or advanced number theory. 

The most efficient approach is to iterate through the numbers from 10 down to 1. The first number we encounter that divides $N$ without leaving a remainder is guaranteed to be the largest divisor in that range. By iterating backwards, we ensure that the first match we find is the maximum possible value.

## Complexity Analysis
- **Time Complexity**: $O(1)$. Since the loop always runs a maximum of 10 times regardless of the input size $N$, the time complexity is constant.
- **Space Complexity**: $O(1)$. We only use a single integer variable to store the input and the loop index, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HDIVISR
 * The task is to find the largest integer x in the range [1, 10] such that N % x == 0.
 * Since the range is very small (1 to 10), we can simply iterate backwards from 10 down to 1.
 * The first number we encounter that divides N will be the largest divisor in that range.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Iterate from 10 down to 1 to find the largest divisor
    for (int i = 10; i >= 1; --i) {
        if (n % i == 0) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
```