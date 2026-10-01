# [Bytelandian gold coins (COINS)](https://www.codechef.com/problems/COINS)

- **Difficulty Rating**: 944
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a Bytelandian gold coin of value $n$. You can either keep the coin and exchange it for $n$ American dollars, or you can exchange the coin into three smaller coins of values $\lfloor n/2 \rfloor$, $\lfloor n/3 \rfloor$, and $\lfloor n/4 \rfloor$. This process can be repeated recursively for the new coins. The goal is to find the maximum amount of American dollars you can obtain for a given $n$.

## Intuition & Mathematical Observation
The problem defines a recursive relationship:
$$f(n) = \max(n, f(\lfloor n/2 \rfloor) + f(\lfloor n/3 \rfloor) + f(\lfloor n/4 \rfloor))$$

**Key Observations:**
1. **Base Case:** For small values of $n$ (specifically $n < 12$), the sum of the sub-coins ($\lfloor n/2 \rfloor + \lfloor n/3 \rfloor + \lfloor n/4 \rfloor$) is less than or equal to $n$. Therefore, for $n < 12$, it is always optimal to keep the coin as is ($f(n) = n$).
2. **Memoization:** Since $n$ can be as large as $10^9$, a standard array-based dynamic programming approach is impossible due to memory constraints. However, many recursive branches will overlap. We use a `std::map<long long, long long>` to store the results of previously computed values of $n$ to avoid redundant calculations.
3. **Input Handling:** The problem requires reading until the End-Of-File (EOF), which is handled by the `while (cin >> n)` loop.

## Complexity Analysis
- **Time Complexity**: $O(\log n)$ per test case. While the exact number of states is not strictly logarithmic, the recursive tree is pruned significantly because we only branch when $n \ge 12$, and the values decrease rapidly.
- **Space Complexity**: $O(\log n)$ to store the memoized results in the map.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a coin of value n, we have two choices:
 * 1. Keep the coin and exchange it for n dollars.
 * 2. Exchange the coin for three coins of values floor(n/2), floor(n/3), and floor(n/4).
 * 
 * Let f(n) be the maximum dollars we can get from a coin of value n.
 * f(n) = max(n, f(floor(n/2)) + f(floor(n/3)) + f(floor(n/4)))
 */

map<long long, long long> memo;

long long solve(long long n) {
    if (n == 0) return 0;
    if (n < 12) return n;
    
    // Check if already computed
    if (memo.count(n)) return memo[n];
    
    // Recursive step: max of current value or sum of sub-coins
    long long res = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
    
    return memo[n] = res;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    // Read until EOF
    while (cin >> n) {
        cout << solve(n) << "\n";
    }
    
    return 0;
}
```