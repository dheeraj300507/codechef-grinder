# [Bucket and Water Flow (WATERFLOW)](https://www.codechef.com/problems/WATERFLOW)

- **Difficulty Rating**: 483
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a bucket with an initial amount of water $W$ and a maximum capacity $X$. Water is poured into the bucket at a rate of $Y$ units per hour for $Z$ hours. We need to determine the final state of the bucket:
1. **"overflow"**: If the total water exceeds the capacity $X$.
2. **"filled"**: If the total water is exactly equal to the capacity $X$.
3. **"unfilled"**: If the total water is less than the capacity $X$.

## Intuition & Mathematical Observation
The total amount of water in the bucket after $Z$ hours is calculated by adding the initial volume to the total inflow:
$$\text{Total Water} = W + (Y \times Z)$$

By comparing this result to the capacity $X$, we can determine the state:
- If $W + (Y \times Z) > X$, the bucket overflows.
- If $W + (Y \times Z) == X$, the bucket is perfectly filled.
- If $W + (Y \times Z) < X$, the bucket remains unfilled.

Given the constraints ($W, X, Y, Z \le 1000$), the maximum possible value is $1,000 + (1,000 \times 1,000) = 1,001,000$. This fits comfortably within a standard 32-bit integer, though `long long` is used to ensure safety against potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial water: W
 * Capacity: X
 * Inflow rate: Y
 * Time: Z
 * Total water after Z hours = W + (Y * Z)
 * 
 * Comparison:
 * If (W + Y * Z) > X: overflow
 * If (W + Y * Z) == X: filled
 * If (W + Y * Z) < X: unfilled
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long W, X, Y, Z;
        cin >> W >> X >> Y >> Z;
        
        long long total_water = W + (Y * Z);
        
        if (total_water > X) {
            cout << "overflow" << "\n";
        } else if (total_water == X) {
            cout << "filled" << "\n";
        } else {
            cout << "unfilled" << "\n";
        }
    }
    
    return 0;
}
```