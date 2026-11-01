# [Back to Campus (MINDAYSRET)](https://www.codechef.com/problems/MINDAYSRET)

- **Difficulty Rating**: 933
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the minimum number of days required for $N$ students to return to campus, given that the campus can accommodate at most $K$ students per day. If $N$ is not perfectly divisible by $K$, the remaining students will require an additional day.

## Intuition & Mathematical Observation
To find the minimum number of days, we need to calculate the ceiling of the division $N/K$. 

In integer arithmetic, the standard division operator `/` performs floor division (truncating the decimal part). To perform ceiling division using only integers, we can use the formula:
$$\text{days} = \lceil N / K \rceil = \frac{N + K - 1}{K}$$

**Why this works:**
- If $N$ is a multiple of $K$ (e.g., $N=10, K=5$), the formula gives $(10+5-1)/5 = 14/5 = 2$.
- If $N$ is not a multiple of $K$ (e.g., $N=11, K=5$), the formula gives $(11+5-1)/5 = 15/5 = 3$.
This approach avoids the use of floating-point numbers and potential precision issues.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant time $O(1)$ arithmetic calculation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N students and a capacity of K students per day.
 * To find the minimum number of days, we need to perform ceiling division of N by K.
 * Mathematically, this is ceil(N / K).
 * Using integer arithmetic, ceil(N / K) can be calculated as (N + K - 1) / K.
 * 
 * Constraints:
 * T <= 10^4, N, K <= 10^2.
 * The calculation (N + K - 1) / K will not overflow standard integers.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate ceiling division: (n + k - 1) / k
        // This works for all positive integers n and k.
        long long days = (n + k - 1) / k;
        
        cout << days << "\n";
    }

    return 0;
}
```