# [Find the Direction (FACEDIR)](https://www.codechef.com/problems/FACEDIR)

- **Difficulty Rating**: 880
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts facing **North**. Every second, he rotates 90 degrees in the clockwise direction. Given an integer $X$ representing the number of seconds passed, determine the final direction Chef is facing.

## Intuition & Mathematical Observation
The directions follow a cyclic pattern of length 4 when rotating 90 degrees clockwise:
1. **North** (Initial state, 0 rotations)
2. **East** (1 rotation)
3. **South** (2 rotations)
4. **West** (3 rotations)

After 4 rotations, Chef returns to the North position. Therefore, the final direction depends solely on the remainder of $X$ when divided by 4 ($X \pmod 4$):
- If $X \pmod 4 = 0$, the direction is **North**.
- If $X \pmod 4 = 1$, the direction is **East**.
- If $X \pmod 4 = 2$, the direction is **South**.
- If $X \pmod 4 = 3$, the direction is **West**.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time modulo operation and a print statement.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts facing North.
 * Each second, he rotates 90 degrees clockwise.
 * The directions in clockwise order are:
 * 0: North
 * 1: East
 * 2: South
 * 3: West
 * 
 * After X seconds, the direction is determined by X % 4.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        int remainder = x % 4;
        
        if (remainder == 0) {
            cout << "North" << "\n";
        } else if (remainder == 1) {
            cout << "East" << "\n";
        } else if (remainder == 2) {
            cout << "South" << "\n";
        } else {
            cout << "West" << "\n";
        }
    }
    
    return 0;
}
```