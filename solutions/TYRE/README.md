# [Tyre problem (TYRE)](https://www.codechef.com/problems/TYRE)

- **Difficulty Rating**: 452
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ bikes and $M$ cars, calculate the total number of tyres present. Each bike has 2 tyres, and each car has 4 tyres.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. Since every bike contributes 2 tyres and every car contributes 4 tyres, the total number of tyres can be expressed by the linear equation:
$$\text{Total Tyres} = (N \times 2) + (M \times 4)$$

Given the constraints $N, M \le 100$, the maximum possible result is $600$, which easily fits within standard integer data types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each bike has 2 tyres.
 * Each car has 4 tyres.
 * Total tyres = (N * 2) + (M * 4).
 * Constraints: N, M <= 100. The result will be at most (100*2 + 100*4) = 600.
 * This fits comfortably within a standard 'int'.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        if (cin >> n >> m) {
            // Calculate total tyres
            long long total_tyres = (n * 2) + (m * 4);
            cout << total_tyres << "\n";
        }
    }

    return 0;
}
```