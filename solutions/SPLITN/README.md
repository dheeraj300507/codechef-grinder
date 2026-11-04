# [Split N (SPLITN)](https://www.codechef.com/problems/SPLITN)

- **Difficulty Rating**: 1195
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we want to represent it as a sum of powers of 2. In one operation, we can take any integer $X$ and replace it with two integers $Y$ and $Z$ such that $Y + Z = X$. We want to find the minimum number of operations required to reach a state where every number in our collection is a power of 2.

## Intuition & Mathematical Observation
Any positive integer $N$ can be uniquely represented as a sum of powers of 2 based on its binary representation. If $N$ has $k$ set bits (1s) in its binary form, it can be written as:
$N = 2^{a_1} + 2^{a_2} + \dots + 2^{a_k}$

*   If $N$ is already a power of 2, it has only 1 set bit ($k=1$). We need $1-1 = 0$ operations.
*   If $N$ has $k$ set bits, we can think of this as having $k$ numbers that are already powers of 2. To reach this state from a single number $N$, we need to perform $k-1$ split operations. Each operation effectively increases the count of numbers in our set by 1. 

Therefore, the minimum number of operations required is simply **(number of set bits in $N$) - 1**.

## Complexity Analysis
- **Time Complexity**: $O(\log N)$ per test case. The number of bits in $N$ is $\log_2 N$, and we iterate through these bits once to count them.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the bit count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with an integer N. We want to break it into powers of 2.
 * An operation consists of taking an integer X and splitting it into Y + Z = X.
 * If we start with N, and we want to reach a state where all numbers are powers of 2,
 * this is equivalent to finding the binary representation of N.
 * 
 * If N = 2^a1 + 2^a2 + ... + 2^ak, then N has k set bits in its binary representation.
 * To reach this state from N, we need to perform (k - 1) operations.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Count the number of set bits (1s) in the binary representation of n.
        // The minimum number of operations to split N into powers of 2 is (popcount(N) - 1).
        int set_bits = 0;
        long long temp = n;
        while (temp > 0) {
            if (temp & 1) set_bits++;
            temp >>= 1;
        }
        
        cout << set_bits - 1 << "\n";
    }
    
    return 0;
}
```