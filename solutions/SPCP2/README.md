# [Airlines (SPCP2)](https://www.codechef.com/problems/SPCP2)

- **Difficulty Rating**: 712
- **Solved in**: 3 attempt(s)

## Problem Summary
An airline currently owns $X$ planes, and each plane can carry a maximum of 100 passengers. Given that $N$ passengers need to travel, determine the minimum number of **additional** planes the airline must purchase to accommodate all $N$ passengers.

## Intuition & Mathematical Observation
1. **Capacity Calculation**: Since each plane holds 100 passengers, the total number of planes required to carry $N$ passengers is $\lceil N / 100 \rceil$.
2. **Integer Arithmetic**: In C++, integer division truncates toward zero. To perform a ceiling division for positive integers $N$ and $D$, we can use the formula: `(N + D - 1) / D`. Thus, the total planes required is `(N + 99) / 100`.
3. **Conditional Logic**:
   - Let $R$ be the total planes required.
   - If $R \le X$, the airline already has enough capacity, so the answer is $0$.
   - If $R > X$, the airline needs to purchase $R - X$ additional planes.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ constant time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Each plane carries 100 passengers.
 * Total planes required = ceil(N / 100.0).
 * Using integer arithmetic, ceil(N / 100) is (N + 99) / 100.
 * Let R be the required number of planes.
 * If R <= X, we need 0 new planes.
 * If R > X, we need (R - X) new planes.
 * 
 * Constraints:
 * T <= 1000, X, N <= 10^6.
 * The logic is O(1) per test case, O(T) total.
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, n;
        cin >> x >> n;

        // Calculate total planes needed using integer ceiling division.
        // (n + 99) / 100 is the standard way to perform ceil(n/100)
        // for positive integers.
        long long required_planes = (n + 99) / 100;

        // Calculate how many more are needed.
        // If the airline already has enough planes, the result is 0.
        if (required_planes <= x) {
            cout << 0 << "\n";
        } else {
            cout << (required_planes - x) << "\n";
        }
    }

    return 0;
}
```