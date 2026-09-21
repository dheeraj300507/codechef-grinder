# [Lazy Chef (LAZYCHF)](https://www.codechef.com/problems/LAZYCHF)

- **Difficulty Rating**: 801
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a task that takes $x$ units of time to complete. Due to his laziness, he multiplies the time taken by a factor of $m$, resulting in $m \times x$ units of time. However, there is a constraint: the total time taken cannot exceed the original time $x$ plus a maximum delay allowance of $d$. We need to find the actual time Chef takes to complete the task, which is the minimum of his "lazy" time and the maximum allowed time.

## Intuition & Mathematical Observation
The problem asks us to compare two values:
1. **The Lazy Time**: $m \times x$
2. **The Maximum Allowed Time**: $x + d$

Since Chef will take the shortest possible time that satisfies the constraints, the answer is simply the minimum of these two values:
$$\text{Result} = \min(m \times x, x + d)$$

Given the constraints ($x, m \le 10$ and $d < 100$), the values will easily fit within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's work takes x units of time.
 * Due to laziness, he takes m * x units of time.
 * However, there is a limit to the delay: he can delay at most d units.
 * This means the total time taken is capped at x + d.
 * Therefore, the time taken is min(m * x, x + d).
 * 
 * Constraints:
 * 1 <= T <= 10^4
 * 1 <= x, m <= 10
 * 0 <= d < 100
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, m, d;
        cin >> x >> m >> d;
        
        // Calculate the time taken by laziness: m * x
        // Calculate the maximum allowed time: x + d
        // The result is the minimum of these two values
        long long lazy_time = m * x;
        long long max_allowed_time = x + d;
        
        cout << min(lazy_time, max_allowed_time) << "\n";
    }
    
    return 0;
}
```