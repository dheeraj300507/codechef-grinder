# [Nearest Square (NEARSQ)](https://www.codechef.com/problems/NEARSQ)

- **Difficulty Rating**: 570
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$ ($1 \le N \le 100$), the task is to find the largest perfect square $A$ such that $1 \le A \le N$.

## Intuition & Mathematical Observation
A perfect square is an integer that is the square of an integer (e.g., $1, 4, 9, 16, \dots$). 
To find the largest perfect square less than or equal to $N$:
1. Calculate the square root of $N$ using `sqrt(N)`.
2. Take the floor of this value (the integer part), which gives us the largest integer $B$ such that $B^2 \le N$.
3. The result is simply $B \times B$.

For example, if $N = 10$:
- $\sqrt{10} \approx 3.16$
- $\lfloor 3.16 \rfloor = 3$
- $3^2 = 9$, which is the largest square $\le 10$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the `sqrt` function and basic arithmetic operations run in constant time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an integer N (1 <= N <= 100).
 * We need to find the largest square number A such that 1 <= A <= N.
 * Since N is small (up to 100), we can find the integer square root of N,
 * let's call it B = floor(sqrt(N)).
 * The largest square number A <= N will be B * B.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate the integer square root
        long long b = (long long)sqrt(n);
        
        // The largest square <= N is b * b
        long long result = b * b;
        
        cout << result << "\n";
    }
    
    return 0;
}
```