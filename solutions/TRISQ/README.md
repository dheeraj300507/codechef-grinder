# [Fit Squares in Triangle (TRISQ)](https://www.codechef.com/problems/TRISQ)

- **Difficulty Rating**: 985
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a right-angled isosceles triangle with a base of length $B$, we need to determine the maximum number of $2 \times 2$ squares that can be fitted inside the triangle. The squares must be placed such that their sides are parallel to the legs of the triangle.

## Intuition & Mathematical Observation
To fit $2 \times 2$ squares into a right-angled isosceles triangle with base $B$:
1. The height of the triangle is equal to its base $B$.
2. A $2 \times 2$ square requires a height of 2. Placing a row of squares at the bottom reduces the remaining space to a smaller triangle with a base of $B - 2$.
3. The number of squares that can fit in the bottom-most row is $\frac{B-2}{2}$.
4. Let $n = \frac{B-2}{2}$. The total number of squares is the sum of the number of squares in each row:
   - Row 1: $n$ squares
   - Row 2: $n-1$ squares
   - ...
   - Row $n$: $1$ square
5. This forms an arithmetic progression: $n + (n-1) + \dots + 1$, which simplifies to the formula for the sum of the first $n$ natural numbers:
   $$\text{Total Squares} = \frac{n(n+1)}{2}$$
   where $n = \lfloor \frac{B-2}{2} \rfloor$. If $B < 4$, the answer is 0.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A right-angled isosceles triangle with base B has a height equal to B.
 * We want to fit 2x2 squares.
 * Let the base be B. The first row of squares (at the bottom) will have a height of 2.
 * The remaining triangle above these squares is a smaller right-angled isosceles triangle
 * with base (B - 4).
 * 
 * Let f(B) be the number of squares.
 * If B < 4, f(B) = 0.
 * If B >= 4, the number of squares in the bottom row is (B - 2) / 2.
 * The remaining triangle has base (B - 2).
 * So, f(B) = (B - 2) / 2 + f(B - 2).
 * 
 * Let n = (B - 2) / 2.
 * The sequence is:
 * B=4: n=1, f(4) = 1
 * B=6: n=2, f(6) = 2 + 1 = 3
 * B=8: n=3, f(8) = 3 + 2 + 1 = 6
 * B=10: n=4, f(10) = 4 + 3 + 2 + 1 = 10
 * This is the sum of the first n integers: n * (n + 1) / 2.
 */

void solve() {
    long long B;
    cin >> B;
    
    // The base of the triangle available for squares is B.
    // We need at least a 2x2 square, so B must be at least 4.
    if (B < 4) {
        cout << 0 << "\n";
        return;
    }
    
    // Calculate n = (B - 2) / 2
    long long n = (B - 2) / 2;
    
    // The result is the sum of integers from 1 to n
    long long ans = n * (n + 1) / 2;
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```