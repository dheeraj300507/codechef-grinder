# [Dividing Stamps (DIVIDING)](https://www.codechef.com/problems/DIVIDING)

- **Difficulty Rating**: 1109
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ members, each currently holding a certain number of stamps. We want to redistribute these stamps such that the $i$-th member (1-indexed) ends up with exactly $i$ stamps. We need to determine if it is possible to achieve this distribution given the total number of stamps currently available.

## Intuition & Mathematical Observation
The problem asks if we can distribute stamps such that the members have $1, 2, 3, \dots, N$ stamps respectively. 

1. **Total Required Stamps**: The total number of stamps needed to satisfy the condition is the sum of the first $N$ natural numbers. This is given by the arithmetic series formula:
   $$S = \sum_{i=1}^{N} i = \frac{N \times (N + 1)}{2}$$
2. **Condition for Success**: Since we are only redistributing the existing stamps, the total number of stamps provided in the input must be exactly equal to the sum of the first $N$ natural numbers. If the sum of the input stamps is equal to $S$, we can always arrange them to satisfy the requirement. If the sum is greater or less than $S$, it is impossible.
3. **Data Types**: Given $N \le 100,000$, the sum can reach approximately $\frac{10^5 \times 10^5}{2} \approx 5 \times 10^9$. Since this exceeds the capacity of a standard 32-bit `int` (which maxes out at $\approx 2 \times 10^9$), we must use `long long` in C++ to prevent integer overflow.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of members. We iterate through the input list exactly once to calculate the total sum of stamps.
- **Space Complexity**: $O(1)$, as we only store the running total and the input $N$, requiring constant extra space regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N members. We want to redistribute the total number of stamps such that
 * the i-th member (1-indexed) gets exactly i stamps.
 * 
 * The total number of stamps required to satisfy the condition is the sum of 
 * the first N natural numbers: 1 + 2 + 3 + ... + N.
 * The formula for this sum is S = N * (N + 1) / 2.
 * 
 * If the sum of the given stamps (C1 + C2 + ... + CN) is exactly equal to S,
 * then it is possible to redistribute them as required. Otherwise, it is not.
 * 
 * Constraints:
 * N <= 100,000
 * Ci <= 10^9
 * Total sum can exceed 2^31 - 1, so we must use long long.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long total_stamps = 0;
    for (int i = 0; i < n; ++i) {
        long long c;
        cin >> c;
        total_stamps += c;
    }

    // The required sum is the sum of 1 to N
    // Using long long to prevent overflow during calculation
    long long required_sum = (long long)n * (n + 1) / 2;

    if (total_stamps == required_sum) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```