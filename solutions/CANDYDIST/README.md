# [Candy Distribution (CANDYDIST)](https://www.codechef.com/problems/CANDYDIST)

- **Difficulty Rating**: 668
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ candies and wants to distribute them equally among $M$ friends. For the distribution to be valid, two conditions must be met:
1. Every friend must receive an equal number of candies (i.e., $N$ must be perfectly divisible by $M$).
2. Each friend must receive an **even** number of candies.

We need to determine if it is possible to distribute the candies such that both conditions are satisfied.

## Intuition & Mathematical Observation
To solve this problem, we translate the requirements into mathematical expressions:
1. **Equal distribution**: This is satisfied if the remainder of $N$ divided by $M$ is zero ($N \pmod M = 0$).
2. **Even number of candies**: If the first condition is met, each friend receives $K = N / M$ candies. We must check if this quotient $K$ is even, which is true if $K \pmod 2 = 0$.

Combining these, the condition for a "Yes" output is:
$$(N \pmod M == 0) \land ((N / M) \pmod 2 == 0)$$

If either condition fails, the output should be "No".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Chef has N candies and M friends.
 * 2. Each friend must get an equal number of candies: N must be divisible by M (N % M == 0).
 * 3. Each friend must get an even number of candies: (N / M) % 2 == 0.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= N, M <= 1000
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // Condition 1: N must be perfectly divisible by M
        // Condition 2: The quotient (N/M) must be even
        if ((n % m == 0) && ((n / m) % 2 == 0)) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```