# [Coins And Triangle (TRICOIN)](https://www.codechef.com/problems/TRICOIN)

- **Difficulty Rating**: 1075
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ coins, we need to construct a triangle such that the first row has 1 coin, the second row has 2 coins, the third row has 3 coins, and so on. The goal is to find the maximum height $h$ of a triangle that can be formed using at most $N$ coins.

## Intuition & Mathematical Observation
To form a triangle of height $h$, the total number of coins required is the sum of the first $h$ natural numbers:
$$S = 1 + 2 + 3 + \dots + h = \frac{h(h + 1)}{2}$$

We are looking for the largest integer $h$ such that:
$$\frac{h(h + 1)}{2} \le N$$

This inequality can be solved in two ways:
1. **Mathematical Approach**: Solving the quadratic equation $h^2 + h - 2N = 0$ using the quadratic formula gives $h = \frac{-1 + \sqrt{1 + 8N}}{2}$. Taking the floor of this value provides the maximum height.
2. **Binary Search Approach**: Since the function $f(h) = \frac{h(h+1)}{2}$ is monotonically increasing, we can binary search for the largest $h$ in the range $[1, 2 \cdot 10^9]$. This approach is highly robust and avoids potential floating-point precision errors associated with `sqrt()`.

Given $N \le 10^9$, the maximum possible height is approximately $\sqrt{2 \cdot 10^9} \approx 44,721$. Using `long long` ensures we avoid overflow during the calculation of $mid \cdot (mid + 1)$.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot \log(\sqrt{N}))$, where $T$ is the number of test cases. Since the binary search runs over a range up to $2 \cdot 10^9$, it performs roughly 31 iterations per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the search boundaries.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form a triangle of height 'h', we need:
 * 1 + 2 + 3 + ... + h = h * (h + 1) / 2 coins.
 * We are given N coins and want to find the maximum 'h' such that:
 * h * (h + 1) / 2 <= N
 * 
 * Constraints: N <= 10^9. 
 * Binary search is used to find the largest h efficiently.
 */

void solve() {
    long long n;
    cin >> n;
    
    // Binary search for the largest h such that h*(h+1)/2 <= n
    long long low = 1, high = 2000000000LL; 
    long long ans = 0;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * (mid + 1) / 2 <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
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