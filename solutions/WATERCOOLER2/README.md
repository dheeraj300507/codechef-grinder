# [The Cooler Dilemma 2 (WATERCOOLER2)](https://www.codechef.com/problems/WATERCOOLER2)

- **Difficulty Rating**: 798
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the cost to rent a water cooler per month ($X$) and the cost to purchase the cooler ($Y$). We need to find the maximum number of months ($M$) we can rent the cooler such that the total rental cost is **strictly less** than the purchase cost. If it is impossible to rent for even one month while staying cheaper than the purchase price, the answer is 0.

## Intuition & Mathematical Observation
The problem asks for the largest integer $M$ that satisfies the inequality:
$$M \times X < Y$$

1. **Case 1: $X \ge Y$**
   If the cost of renting for one month is already greater than or equal to the purchase price, we cannot rent the cooler for any amount of time while keeping the cost strictly less than $Y$. Thus, the answer is $0$.

2. **Case 2: $X < Y$**
   We need to solve for $M$ in $M < \frac{Y}{X}$. Since $M$ must be an integer, the largest such $M$ is $\lfloor \frac{Y-1}{X} \rfloor$. 
   *Example:* If $X=2$ and $Y=10$, we need $M \times 2 < 10 \implies M < 5$. The largest integer is $4$. Using the formula: $(10-1) / 2 = 9 / 2 = 4$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum integer M such that:
 * M * X < Y
 * 
 * Rearranging the inequality:
 * M < Y / X
 * 
 * Since M must be an integer, M = floor((Y - 1) / X).
 * 
 * If Y <= X, then even for M = 1, M * X >= Y.
 * In this case, the condition "strictly less" cannot be satisfied for any M >= 1,
 * so the answer is 0.
 * 
 * Constraints:
 * X, Y up to 10^9. Calculations fit in long long.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // If renting for 1 month is already >= purchasing, answer is 0.
        if (x >= y) {
            cout << 0 << "\n";
        } else {
            // We want max M such that M * X < Y.
            // This is equivalent to M = (Y - 1) / X using integer division.
            // Since we already checked x >= y, we know y > x, so y-1 >= x.
            long long ans = (y - 1) / x;
            cout << ans << "\n";
        }
    }

    return 0;
}
```