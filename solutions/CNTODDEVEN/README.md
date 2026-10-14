# [Count Odd Even Divisors (CNTODDEVEN)](https://www.codechef.com/problems/CNTODDEVEN)

- **Difficulty Rating**: 538
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, the task is to count how many divisors of $N$ are odd and how many are even. A divisor $d$ is considered odd if $d \pmod 2 \neq 0$ and even if $d \pmod 2 = 0$.

## Intuition & Mathematical Observation
Since the constraint on $N$ is very small ($1 \le N \le 100$), we do not need complex prime factorization or advanced number theory. We can simply iterate through every integer $i$ from $1$ to $N$:
1. Check if $i$ is a divisor of $N$ using the condition `N % i == 0`.
2. If it is a divisor, check its parity:
   - If `i % 2 != 0`, increment the `odd_count`.
   - Otherwise, increment the `even_count`.

This brute-force approach is highly efficient given the constraints and guarantees correctness.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the input integer. Given $N \le 100$, this performs at most 100 operations per test case, which is well within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts and the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an integer N, we need to count its odd divisors and even divisors.
 * Since N is small (1 <= N <= 100), we can iterate from 1 to N to find all divisors.
 */

void solve() {
    int N;
    cin >> N;
    
    int odd_count = 0;
    int even_count = 0;
    
    // Iterate through all numbers from 1 to N to find divisors
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            // Check if the divisor is odd or even
            if (i % 2 != 0) {
                odd_count++;
            } else {
                even_count++;
            }
        }
    }
    
    cout << odd_count << " " << even_count << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```