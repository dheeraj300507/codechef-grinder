# [Volume Comparison (CABLE)](https://www.codechef.com/problems/CABLE)

- **Difficulty Rating**: 318
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to compare the volumes of two geometric shapes:
1. A **cuboid** with dimensions $A \times B \times C$.
2. A **cube** with side length $X$.

We need to determine if the volume of the cuboid is greater than, less than, or equal to the volume of the cube and output "Cuboid", "Cube", or "Equal" accordingly.

## Intuition & Mathematical Observation
- The volume of a cuboid is calculated as $V_{cuboid} = A \times B \times C$.
- The volume of a cube is calculated as $V_{cube} = X \times X \times X$.
- Since the input values can be large enough that their product might exceed the range of a standard 32-bit integer, we use `long long` in C++ to prevent integer overflow during calculation.
- After calculating both volumes, a simple conditional (`if-else`) structure is used to compare the two values and print the result.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the four integer variables and the calculated volumes.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: CABLE
 * Logic: 
 * 1. Calculate volume of cuboid: V_cuboid = A * B * C
 * 2. Calculate volume of cube: V_cube = X * X * X
 * 3. Compare V_cuboid and V_cube and print the corresponding result.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, X;
    // Read the four integers
    if (!(cin >> A >> B >> C >> X)) return 0;

    // Use long long to prevent overflow during multiplication
    long long vol_cuboid = (long long)A * B * C;
    long long vol_cube = (long long)X * X * X;

    if (vol_cuboid > vol_cube) {
        cout << "Cuboid" << "\n";
    } else if (vol_cube > vol_cuboid) {
        cout << "Cube" << "\n";
    } else {
        cout << "Equal" << "\n";
    }

    return 0;
}
```