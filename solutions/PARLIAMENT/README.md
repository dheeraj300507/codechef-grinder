# [Parliament (PARLIAMENT)](https://www.codechef.com/problems/PARLIAMENT)

- **Difficulty Rating**: 419
- **Solved in**: 1 attempt(s)

## Problem Summary
In a parliament of $N$ members, a resolution is passed if at least half of the members vote in favor. Given $N$ (total members) and $X$ (members who voted in favor), determine if the resolution passes.

## Intuition & Mathematical Observation
The condition for the resolution to pass is:
$$\text{Votes in favor} \ge \frac{\text{Total members}}{2}$$
Mathematically, this is $X \ge \frac{N}{2}$.

To avoid potential precision issues with floating-point division, we can multiply both sides of the inequality by 2:
$$2 \times X \ge N$$

This approach is robust for both even and odd values of $N$:
- If $N=5$ and $X=2$: $2 \times 2 = 4$, which is not $\ge 5$ (Resolution fails).
- If $N=5$ and $X=3$: $2 \times 3 = 6$, which is $\ge 5$ (Resolution passes).

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The resolution passes if X >= N / 2.0.
 * To avoid floating point arithmetic, we can multiply both sides by 2:
 * 2 * X >= N
 * This condition correctly handles both even and odd N.
 * 
 * Constraints:
 * T <= 5000, N <= 100.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 * Space complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // The condition is X >= N / 2.0
        // Equivalent to 2 * X >= N
        if (2 * x >= n) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```