# [Run for Fun (RURT)](https://www.codechef.com/problems/RURT)

- **Difficulty Rating**: 375
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to cover a total distance of $Y$ kilometers. He runs $X$ kilometers at a time before stopping to rest. We need to calculate the total number of times Chef stops to rest before reaching the finish line. Note that if Chef reaches the finish line exactly at the end of a run, he does not need to rest.

## Intuition & Mathematical Observation
The problem asks for the number of stops made at distances $X, 2X, 3X, \dots$ such that the stop distance is strictly less than $Y$.

1. **Case 1 ($Y \le X$):** If the total distance is less than or equal to the distance Chef can run in one go, he reaches the destination without any stops. The answer is $0$.
2. **Case 2 ($Y > X$):** Chef stops at every multiple of $X$ that is strictly less than $Y$. 
   - If $Y$ is a multiple of $X$ (e.g., $X=2, Y=4$), he stops at $2$. He does not stop at $4$ because that is the finish line. Total stops: $(4/2) - 1 = 1$.
   - If $Y$ is not a multiple of $X$ (e.g., $X=2, Y=5$), he stops at $2$ and $4$. Total stops: $\lfloor 5/2 \rfloor = 2$.
   
Both scenarios can be unified using the formula: **$\lfloor (Y - 1) / X \rfloor$**.
- For $X=2, Y=4$: $(4-1)/2 = 3/2 = 1$.
- For $X=2, Y=5$: $(5-1)/2 = 4/2 = 2$.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a single arithmetic calculation regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef runs X km before resting. Total distance is Y km.
 * Chef stops to rest at distances X, 2X, 3X, ... as long as the distance
 * is strictly less than Y.
 * 
 * If Y <= X, Chef reaches the finish line without stopping (0 stops).
 * If Y > X, the number of stops is floor((Y - 1) / X).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    
    // Read input X and Y
    if (cin >> X >> Y) {
        if (Y <= X) {
            cout << 0 << "\n";
        } else {
            // The number of stops is the total distance Y divided by X, 
            // excluding the final segment if it lands exactly on the finish line.
            // This is equivalent to (Y - 1) / X using integer division.
            cout << (Y - 1) / X << "\n";
        }
    }

    return 0;
}
```