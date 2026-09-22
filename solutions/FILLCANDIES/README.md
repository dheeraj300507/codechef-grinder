# [Fill Candies (FILLCANDIES)](https://www.codechef.com/problems/FILLCANDIES)

- **Difficulty Rating**: 681
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ candies, and you have bags that contain $K$ pockets each. Each pocket can hold at most $M$ candies. You need to determine the minimum number of bags required to store all $N$ candies.

## Intuition & Mathematical Observation
1. **Calculate Capacity**: Since each bag has $K$ pockets and each pocket holds $M$ candies, the total capacity of a single bag is $K \times M$.
2. **Determine Bags Needed**: To store $N$ candies, we need to divide $N$ by the capacity per bag. If $N$ is not perfectly divisible by the capacity, we need an additional bag for the remainder. This is equivalent to the ceiling division: $\lceil N / (K \times M) \rceil$.
3. **Integer Arithmetic**: In C++, integer division `a / b` truncates toward zero. To perform ceiling division using only integers, we use the formula:
   $$\text{result} = \frac{N + \text{capacity} - 1}{\text{capacity}}$$
   This effectively rounds up the result of the division.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each bag has K pockets.
 * Each pocket can hold at most M candies.
 * Therefore, one bag can hold at most (K * M) candies.
 * To find the minimum number of bags needed for N candies,
 * we need to calculate ceil(N / (K * M)).
 * 
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k, m;
        cin >> n >> k >> m;

        // Capacity of one bag
        long long capacity_per_bag = k * m;

        // Calculate minimum bags needed using integer ceiling division
        // bags = (n + capacity_per_bag - 1) / capacity_per_bag
        long long bags = (n + capacity_per_bag - 1) / capacity_per_bag;

        cout << bags << "\n";
    }

    return 0;
}
```