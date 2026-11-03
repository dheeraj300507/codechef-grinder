# [All Odd Prefix Sums (ODDPREFSUM)](https://www.codechef.com/problems/ODDPREFSUM)

- **Difficulty Rating**: 1085
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, determine if it is possible to rearrange the elements such that every prefix sum $S_i = \sum_{j=1}^{i} A_j$ is an odd number for all $1 \le i \le N$.

## Intuition & Mathematical Observation
Let the rearranged array be $B = [B_1, B_2, \dots, B_N]$. We require $S_i$ to be odd for all $i$.

1. **For $i=1$**: $S_1 = B_1$. Since $S_1$ must be odd, $B_1$ must be an **odd** number.
2. **For $i > 1$**: $S_i = S_{i-1} + B_i$. 
   - We know $S_{i-1}$ is odd (by our requirement).
   - For $S_i$ to be odd, the sum of an odd number ($S_{i-1}$) and $B_i$ must be odd.
   - Mathematically: $\text{odd} + B_i = \text{odd} \implies B_i$ must be **even**.

**Conclusion**: To satisfy the condition, the array must contain exactly one odd number (which will be placed at the first position) and all other $N-1$ numbers must be even. If there are zero odd numbers, $S_1$ will be even. If there are two or more odd numbers, at least one prefix sum will eventually become even because $\text{odd} + \text{odd} = \text{even}$.

Thus, the condition is satisfied if and only if the count of odd numbers in the input array is exactly **1**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we iterate through the array exactly once to count the odd numbers.
- **Space Complexity**: $O(1)$, as we only store the count of odd numbers and do not need to store the entire array in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To ensure every prefix sum is odd:
 * 1. The first element must be odd (to make S_1 odd).
 * 2. Every subsequent element must be even (to maintain the odd parity of the prefix sum).
 * 
 * Therefore, the array must contain exactly one odd number.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        // Check if the number is odd
        if (abs(a) % 2 != 0) {
            odd_count++;
        }
    }

    // The condition is satisfied if and only if there is exactly one odd number
    if (odd_count == 1) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```