# [Minimum Cars required (MINCARS)](https://www.codechef.com/problems/MINCARS)

- **Difficulty Rating**: 608
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ people who need to travel, and knowing that each car can accommodate a maximum of 4 people, determine the minimum number of cars required to transport all $N$ people.

## Intuition & Mathematical Observation
To minimize the number of cars, we want to fill each car to its maximum capacity (4 people). 
- If $N$ is perfectly divisible by 4, the answer is simply $N/4$.
- If there is a remainder (i.e., $N$ is not divisible by 4), we need one additional car to accommodate the remaining people.

This is a classic "ceiling division" problem. In integer arithmetic, the ceiling of $N/K$ can be calculated using the formula:
$$\text{result} = \frac{N + K - 1}{K}$$
Substituting $K = 4$, we get:
$$\text{cars} = \frac{N + 3}{4}$$
This formula effectively handles both cases (divisible and non-divisible) without requiring conditional `if-else` statements.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time $O(1)$ arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each car can hold at most 4 people.
 * To find the minimum number of cars for N people, we need to calculate ceil(N / 4).
 * Using integer arithmetic, ceil(N / 4) can be calculated as (N + 3) / 4.
 * 
 * Constraints:
 * T <= 1000, N <= 1000.
 * The result will fit in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Calculate minimum cars using integer division ceiling formula
        // (n + 4 - 1) / 4 = (n + 3) / 4
        int cars = (n + 3) / 4;
        
        cout << cars << "\n";
    }

    return 0;
}
```