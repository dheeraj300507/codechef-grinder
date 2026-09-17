# [Good Program (NIBBLE)](https://www.codechef.com/problems/NIBBLE)

- **Difficulty Rating**: 593
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given number of bits $N$ constitutes a "Good" program. A program is defined as "Good" if it consists of an exact integer number of nibbles. Since one nibble is defined as 4 bits, we need to check if $N$ is perfectly divisible by 4.

## Intuition & Mathematical Observation
A nibble is a unit of digital information consisting of 4 bits. If a program has $N$ bits, the number of nibbles it contains is given by $X = N / 4$. 

For the program to be "Good," $X$ must be a positive integer. 
1. **Divisibility**: $N$ must be divisible by 4, meaning $N \pmod 4 = 0$.
2. **Positivity**: Since the problem constraints imply $N \ge 1$, any $N$ that is a multiple of 4 will result in $X \ge 1$, satisfying the condition that $X$ is a positive integer.

Therefore, the logic simplifies to checking if `n % 4 == 0`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time modulo operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A nibble is defined as 4 bits.
 * A program is "Good" if it takes exactly X nibbles, where X is a positive integer.
 * Given N bits, the number of nibbles is N / 4.
 * For this to be an integer, N must be perfectly divisible by 4 (i.e., N % 4 == 0).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Check if the number of bits is a multiple of 4
        if (n % 4 == 0) {
            cout << "Good" << "\n";
        } else {
            cout << "Not Good" << "\n";
        }
    }
    
    return 0;
}
```