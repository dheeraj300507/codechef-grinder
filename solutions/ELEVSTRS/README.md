# [From heaven to earth (ELEVSTRS)](https://www.codechef.com/problems/ELEVSTRS)

- **Difficulty Rating**: 1066
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the number of floors $N$ in a building. We need to determine whether it is faster to reach the $N$-th floor using the stairs or the elevator.
- **Stairs**: The distance covered is the diagonal of the building's height, which is $N \times \sqrt{2}$. The velocity is $V_1$.
- **Elevator**: The elevator must travel from the ground to the $N$-th floor and then back to the ground (as per the problem description, it covers $2 \times N$ distance). The velocity is $V_2$.

## Intuition & Mathematical Observation
To determine the faster method, we compare the time taken for both:
1. **Time for Stairs ($T_s$):** $\frac{N \times \sqrt{2}}{V_1}$
2. **Time for Elevator ($T_e$):** $\frac{2 \times N}{V_2}$

We need to compare $\frac{N\sqrt{2}}{V_1}$ and $\frac{2N}{V_2}$. Since $N > 0$, we can divide both sides by $N$:
$$\frac{\sqrt{2}}{V_1} \text{ vs } \frac{2}{V_2}$$

While floating-point arithmetic using `double` is sufficient for the constraints of this problem, we can derive a precision-safe comparison by squaring both sides:
$$\frac{2}{V_1^2} \text{ vs } \frac{4}{V_2^2}$$
$$2 \times V_2^2 \text{ vs } 4 \times V_1^2$$
$$V_2^2 \text{ vs } 2 \times V_1^2$$

If $2 \times V_1^2 < V_2^2$, the stairs are faster. Otherwise, the elevator is faster.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves constant time arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Time_stairs = (N * sqrt(2)) / V1
 * Time_elevator = (2 * N) / V2
 * 
 * We compare these two values to determine which is smaller.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        double n, v1, v2;
        cin >> n >> v1 >> v2;

        // Calculate time taken for both methods
        double time_stairs = (n * sqrt(2.0)) / v1;
        double time_elevator = (2.0 * n) / v2;

        // Compare and output the result
        if (time_stairs < time_elevator) {
            cout << "Stairs" << "\n";
        } else {
            cout << "Elevator" << "\n";
        }
    }

    return 0;
}
```