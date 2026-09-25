# [Two vs Ten (TWOVSTEN)](https://www.codechef.com/problems/TWOVSTEN)

- **Difficulty Rating**: 936
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, we can perform an operation where we multiply $X$ by 2. We need to determine the minimum number of operations required to make $X$ divisible by 10. If it is impossible to make $X$ divisible by 10, output -1.

## Intuition & Mathematical Observation
To make a number divisible by 10, it must be divisible by both 2 and 5. Let's analyze the last digit of $X$:

1.  **If $X \pmod{10} == 0$**: The number is already divisible by 10. The number of operations required is **0**.
2.  **If $X \pmod{10} == 5$**: The number is divisible by 5 but not by 2. Multiplying it by 2 once will result in a number ending in 0 (since $5 \times 2 = 10$). Thus, the number of operations required is **1**.
3.  **Other cases**:
    *   If $X$ is even but not divisible by 10 (ends in 2, 4, 6, or 8), multiplying by 2 will continue to produce even numbers that do not end in 0.
    *   If $X$ ends in 1, 3, 7, or 9, multiplying by 2 will result in numbers ending in 2, 6, 4, or 8, respectively. None of these operations will ever produce a number ending in 0.
    *   Therefore, if $X$ is not divisible by 5, it is impossible to reach a multiple of 10. The result is **-1**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a few constant-time arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a single variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with X. In each turn, X = X * 2.
 * We want X % 10 == 0.
 * 
 * Conclusion:
 * 1. If X % 10 == 0, return 0.
 * 2. If X % 10 == 5, return 1.
 * 3. Otherwise, return -1.
 */

void solve() {
    long long x;
    cin >> x;
    
    if (x % 10 == 0) {
        cout << 0 << "\n";
    } else if (x % 5 == 0) {
        // Since x % 10 != 0 but x % 5 == 0, x must end in 5.
        // Multiplying by 2 makes it end in 0.
        cout << 1 << "\n";
    } else {
        // Any other case will never result in a number divisible by 10.
        cout << -1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```