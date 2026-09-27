# [Binary Parity (BINPARITY)](https://www.codechef.com/problems/BINPARITY)

- **Difficulty Rating**: 771
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to determine the "parity" of its binary representation. The parity is defined based on the sum of the digits in the binary form of $N$. If the sum of the binary digits (which is equivalent to the number of set bits or 1s) is even, the output should be `EVEN`. If the sum is odd, the output should be `ODD`.

## Intuition & Mathematical Observation
The problem asks for the parity of the number of set bits (also known as the Hamming weight or population count) of an integer $N$. 

1. **Binary Representation**: Any integer $N$ can be represented as a sequence of 0s and 1s. The sum of these digits is simply the count of 1s in that sequence.
2. **Built-in Functions**: In C++, the compiler provides a highly optimized intrinsic function `__builtin_popcount(n)` which returns the number of set bits in an integer.
3. **Parity Check**: Once we have the count of set bits, we simply use the modulo operator (`% 2`) to check if the count is even or odd.
   - If `count % 2 == 0`, the parity is `EVEN`.
   - Otherwise, the parity is `ODD`.

Since $N \le 10^9$, it fits comfortably within a standard 32-bit `int`, making `__builtin_popcount` an efficient and safe choice.

## Complexity Analysis
- **Time Complexity**: $O(T \times \log N)$, where $T$ is the number of test cases. The `__builtin_popcount` function typically runs in $O(1)$ or $O(\text{number of bits})$ time, which is effectively constant for a 32-bit integer.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the bit count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The binary parity of N is defined by the parity of the sum of its binary digits.
 * This is equivalent to the population count (number of set bits) of N.
 * If the number of set bits is even, the parity is EVEN.
 * If the number of set bits is odd, the parity is ODD.
 * 
 * In C++, __builtin_popcount(N) returns the number of set bits in an integer.
 * Since N <= 10^9, it fits within a standard 32-bit signed integer.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        // __builtin_popcount returns the number of 1s in the binary representation
        int set_bits = __builtin_popcount(n);
        
        // Check if the count is even or odd
        if (set_bits % 2 == 0) {
            cout << "EVEN" << "\n";
        } else {
            cout << "ODD" << "\n";
        }
    }
    
    return 0;
}
```