# [Ciel and Receipt (CIELRCPT)](https://www.codechef.com/problems/CIELRCPT)

- **Difficulty Rating**: 936
- **Solved in**: 1 attempt(s)

## Problem Summary
Tomya has a menu with 12 items, each priced at a power of 2 ($2^0, 2^1, 2^2, \dots, 2^{11}$). Given a total bill amount $p$, we need to find the minimum number of items required to sum exactly to $p$. Note that we can order the same item multiple times.

## Intuition & Mathematical Observation
The menu prices are $1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048$. 

1. **Greedy Strategy**: To minimize the number of items, we should always pick the largest possible price that is less than or equal to the remaining bill amount.
2. **Handling 2048**: Since 2048 is the largest price and we can use it multiple times, we first divide the total $p$ by 2048. The quotient gives the number of 2048-priced items, and the remainder is less than 2048.
3. **Binary Representation**: Any integer less than 2048 can be uniquely represented as a sum of distinct powers of 2 (from $2^0$ to $2^{10}$). This is exactly how binary numbers work. The number of items needed for the remainder is equal to the number of set bits (1s) in the binary representation of the remainder.
4. **Implementation**: We can use the built-in function `__builtin_popcount(n)` in C++ to efficiently count the set bits.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs constant time arithmetic operations and a bit-count operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The menu prices are powers of 2: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048.
 * This is equivalent to representing a number in binary, but with a constraint:
 * we only have powers of 2 up to 2^11 (2048).
 * 
 * To minimize the number of items, we should use the largest possible menu prices first (Greedy approach).
 * Since we can use the 2048 menu multiple times, for any price p:
 * 1. Use as many 2048 menus as possible: count += p / 2048, p %= 2048.
 * 2. For the remaining p, use the binary representation (sum of powers of 2).
 *    The number of items for the remainder is simply the number of set bits (popcount).
 */

void solve() {
    int p;
    cin >> p;
    
    int count = 0;
    
    // Use the largest menu (2048) as much as possible
    count += p / 2048;
    p %= 2048;
    
    // For the remainder, use the binary representation (powers of 2)
    // __builtin_popcount returns the number of set bits in an integer
    count += __builtin_popcount(p);
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
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