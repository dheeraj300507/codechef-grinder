# [Hackerman (PRIMEDICE)](https://www.codechef.com/problems/PRIMEDICE)

- **Difficulty Rating**: 643
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob are playing a game involving two dice. Alice rolls a die with value $A$ and Bob rolls a die with value $B$, where $1 \le A, B \le 6$. The sum of the two dice is $S = A + B$. Alice wins if $S$ is a prime number; otherwise, Bob wins. Given $A$ and $B$, we need to determine the winner.

## Intuition & Mathematical Observation
The sum $S$ of two six-sided dice ranges from $2$ ($1+1$) to $12$ ($6+6$). 
To determine the winner, we simply need to check if the sum $S$ is a prime number. The prime numbers within the range $[2, 12]$ are:
**2, 3, 5, 7, and 11.**

Since the range is very small, we can either use a helper function to check for primality or simply check if the sum belongs to the set $\{2, 3, 5, 7, 11\}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the maximum sum is 12, the primality check (or lookup) takes constant time.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob roll dice with values A and B (1 <= A, B <= 6).
 * The sum S = A + B ranges from 2 to 12.
 * Alice wins if S is prime.
 * Prime numbers in the range [2, 12] are: 2, 3, 5, 7, 11.
 */

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int sum = a + b;
        
        // Check if the sum is prime to determine the winner
        if (is_prime(sum)) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
    }
    return 0;
}
```