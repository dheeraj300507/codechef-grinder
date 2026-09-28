# [Move Grid (MOVEMENT)](https://www.codechef.com/problems/MOVEMENT)

- **Difficulty Rating**: 215
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to track the final position of an object starting at the origin $(0, 0)$ after a sequence of four movements:
1. Move $A$ units in the positive X direction.
2. Move $B$ units in the positive Y direction.
3. Move $C$ units in the negative X direction.
4. Move $D$ units in the negative Y direction.

We need to output the final coordinates $(X_{final}, Y_{final})$.

## Intuition & Mathematical Observation
The movement can be broken down into simple arithmetic operations on the X and Y axes independently:

*   **X-axis movement**: We start at $0$, add $A$, and then subtract $C$.
    *   $X_{final} = 0 + A - C = A - C$
*   **Y-axis movement**: We start at $0$, add $B$, and then subtract $D$.
    *   $Y_{final} = 0 + B - D = B - D$

Since the constraints are very small ($1 \le A, B, C, D \le 10$), we can simply perform these subtractions using standard integer types and print the results.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the four input variables and the two result variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Starting at (0, 0):
 * 1. Move A units along positive X: (A, 0)
 * 2. Move B units along positive Y: (A, B)
 * 3. Move C units along negative X: (A - C, B)
 * 4. Move D units along negative Y: (A - C, B - D)
 * 
 * Final position: (A - C, B - D)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, D;
    
    // Read the four movement values
    if (cin >> A >> B >> C >> D) {
        int final_x = A - C;
        int final_y = B - D;
        
        // Output the resulting coordinates
        cout << final_x << " " << final_y << "\n";
    }

    return 0;
}
```