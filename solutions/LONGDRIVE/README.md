# [Long Drive (LONGDRIVE)](https://www.codechef.com/problems/LONGDRIVE)

- **Difficulty Rating**: 939
- **Solved in**: 3 attempt(s)

## Problem Summary
Chef has already driven 10 km at an average speed of $X$ km/h. He wants his overall average speed for the entire journey to be at least $Y$ km/h. We need to find the minimum integer distance $n$ (in km) that Chef must drive at a speed of 100 km/h to achieve this target average speed.

## Intuition & Mathematical Observation
To solve this, we set up an inequality based on the definition of average speed (Total Distance / Total Time).

1. **Initial state**: Distance = 10 km, Speed = $X$ km/h. Time taken = $10/X$ hours.
2. **Additional state**: Distance = $n$ km, Speed = 100 km/h. Time taken = $n/100$ hours.
3. **Target**: Total distance $(10 + n)$ divided by total time $(10/X + n/100) \ge Y$.

However, the problem simplifies the math by stating the average speed is calculated over the total distance. The total time taken is $(10/X) + (n/100)$. 
*Wait, looking at the problem constraints and logic:* The problem implies the average speed is calculated as:
$$\frac{\text{Total Distance}}{\text{Total Time}} \ge Y$$
$$\frac{10 + n}{\frac{10}{X} + \frac{n}{100}} \ge Y$$

*Correction based on the provided solution logic:* The provided code assumes the average speed calculation is based on the weighted sum of speeds:
$$\frac{10 \cdot X + n \cdot 100}{10 + n} \ge Y$$

Rearranging the inequality:
1. $10X + 100n \ge Y(10 + n)$
2. $10X + 100n \ge 10Y + nY$
3. $100n - nY \ge 10Y - 10X$
4. $n(100 - Y) \ge 10(Y - X)$
5. $n \ge \frac{10(Y - X)}{100 - Y}$

Since $n$ must be an integer, we use ceiling division: `(numerator + denominator - 1) / denominator`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. Total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the minimum integer n such that:
 * (10*X + 100*n) / (10 + n) >= Y
 * 10*X + 100*n >= 10*Y + n*Y
 * n*(100 - Y) >= 10*(Y - X)
 * n >= (10 * (Y - X)) / (100 - Y)
 * 
 * Since we need the minimum integer n, we use ceiling division.
 * For integers a/b, ceil(a/b) can be calculated as (a + b - 1) / b.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;

    int numerator = 10 * (Y - X);
    int denominator = 100 - Y;

    // Ceiling division: (numerator + denominator - 1) / denominator
    int n = (numerator + denominator - 1) / denominator;

    cout << n << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```