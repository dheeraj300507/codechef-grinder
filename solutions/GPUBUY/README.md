# [Buying GPU (GPUBUY)](https://www.codechef.com/problems/GPUBUY)

- **Difficulty Rating**: 728
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a GPU. The initial price of the GPU is $X$. Every month, the price increases by $Y$. Chef earns $Z$ coins every month. We need to find the minimum number of months $n$ required for Chef to have enough coins to buy the GPU. If it is impossible for Chef to ever afford the GPU, output -1.

## Intuition & Mathematical Observation
To afford the GPU after $n$ months, Chef's total savings must be greater than or equal to the price of the GPU at that time:
$$n \cdot Z \ge X + n \cdot Y$$

Rearranging the inequality to solve for $n$:
$$n \cdot Z - n \cdot Y \ge X$$
$$n \cdot (Z - Y) \ge X$$

**Case 1: $Z \le Y$**
If the monthly earnings ($Z$) are less than or equal to the monthly price increase ($Y$), the gap between the price and Chef's savings will either stay the same or grow larger every month. Since $X > 0$, Chef will never be able to afford the GPU. In this case, we output `-1`.

**Case 2: $Z > Y$**
If $Z > Y$, we can isolate $n$:
$$n \ge \frac{X}{Z - Y}$$
Since $n$ must be an integer, we take the ceiling of the division. Using integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated as `(a + b - 1) / b`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let X be the initial price, Y be the monthly increase, and Z be the monthly earnings.
 * After n months:
 * Price of GPU = X + n * Y
 * Chef's total coins = n * Z
 * 
 * Chef buys the GPU when:
 * n * Z >= X + n * Y
 * n * Z - n * Y >= X
 * n * (Z - Y) >= X
 * 
 * Case 1: If Z > Y, then n >= X / (Z - Y).
 * Since n must be an integer, n = ceil(X / (Z - Y)).
 * Using integer arithmetic, ceil(a / b) = (a + b - 1) / b.
 * 
 * Case 2: If Z <= Y, then n * (Z - Y) <= 0.
 * Since X > 0, the inequality n * (Z - Y) >= X can never be satisfied.
 * Thus, if Z <= Y, output -1.
 */

void solve() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;

    if (Z <= Y) {
        cout << -1 << "\n";
    } else {
        // We need the smallest integer n such that n * (Z - Y) >= X
        // n >= X / (Z - Y)
        long long diff = Z - Y;
        long long n = (X + diff - 1) / diff;
        cout << n << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```