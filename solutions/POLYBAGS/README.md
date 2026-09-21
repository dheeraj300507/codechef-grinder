# [Too many items (POLYBAGS)](https://www.codechef.com/problems/POLYBAGS)

- **Difficulty Rating**: 738
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to pack $N$ items into polybags. Each polybag can hold a maximum of 10 items. The goal is to determine the minimum number of polybags required to store all $N$ items.

## Intuition & Mathematical Observation
To find the minimum number of polybags, we need to perform a ceiling division of $N$ by 10. 
- If $N$ is perfectly divisible by 10, the answer is $N/10$.
- If there is a remainder, we need one additional polybag to hold the remaining items.

In integer arithmetic, the ceiling of $N/K$ can be calculated using the formula:
$$\text{result} = \frac{N + K - 1}{K}$$
Substituting $K = 10$, we get:
$$\text{result} = \frac{N + 9}{10}$$
This formula effectively handles both cases (divisible and non-divisible) without requiring floating-point arithmetic or conditional statements.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each polybag holds at most 10 items.
 * To find the minimum number of polybags for N items, we need to calculate ceil(N / 10).
 * Using integer arithmetic, ceil(N / 10) can be calculated as (N + 9) / 10.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= N <= 1000
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate minimum polybags using integer division ceiling formula
        // (n + 10 - 1) / 10
        long long result = (n + 9) / 10;
        
        cout << result << "\n";
    }
    
    return 0;
}
```