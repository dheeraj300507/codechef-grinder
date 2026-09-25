# [Greedy puppy (GDOG)](https://www.codechef.com/problems/GDOG)

- **Difficulty Rating**: 1306
- **Solved in**: 1 attempt(s)

## Problem Summary
Tuzik has $N$ coins and wants to distribute them among $i$ people, where $1 \le i \le K$. When he chooses $i$ people, the coins are divided equally, and the remainder (the coins left over for Tuzik) is calculated as $N \pmod i$. The goal is to find the maximum possible remainder Tuzik can get by choosing any number of people $i$ in the range $[1, K]$.

## Intuition & Mathematical Observation
The problem asks us to maximize the expression $N \pmod i$ for all integers $i$ such that $1 \le i \le K$.

1. **Brute Force Approach**: Since the constraints are $N, K \le 10^5$ and the number of test cases $T \le 50$, a simple linear scan from $1$ to $K$ is sufficient.
2. **Mathematical Insight**: The remainder $N \pmod i$ is always less than $i$. To maximize the remainder, we are looking for the largest possible value of $N \pmod i$ within the given constraints.
3. **Efficiency**: With $T \times K \approx 5 \times 10^6$ operations, the brute force approach comfortably fits within the standard 1-second time limit for C++.

## Complexity Analysis
- **Time Complexity**: $O(T \times K)$, where $T$ is the number of test cases and $K$ is the maximum number of people. Given the constraints, this is approximately $5 \times 10^6$ operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the running maximum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tuzik has N coins and can choose between 1 and K people.
 * When he chooses 'i' people, the coins are divided equally among them.
 * The number of coins each person gets is floor(N / i).
 * The number of coins left for Tuzik is N % i.
 * We need to find the maximum value of (N % i) for all i in the range [1, K].
 * 
 * Constraints:
 * T <= 50
 * N, K <= 10^5
 * 
 * Complexity:
 * For each test case, we can iterate from 1 to K and calculate N % i.
 * Total complexity: O(T * K), which is 50 * 10^5 = 5 * 10^6 operations.
 * This is well within the 1s time limit.
 */

void solve() {
    long long N, K;
    if (!(cin >> N >> K)) return;

    long long max_coins = 0;
    
    // We want to maximize N % i for 1 <= i <= K
    for (long long i = 1; i <= K; ++i) {
        long long remainder = N % i;
        if (remainder > max_coins) {
            max_coins = remainder;
        }
    }
    
    cout << max_coins << "\n";
}

int main() {
    // Optimize I/O operations
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