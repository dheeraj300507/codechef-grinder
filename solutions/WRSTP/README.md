# [One Wrong Step (WRSTP)](https://www.codechef.com/problems/WRSTP)

- **Difficulty Rating**: 1070
- **Solved in**: 1 attempt(s)

## Problem Summary
The robot starts at the origin $(0, 0)$ and executes a sequence of $N$ moves ('U', 'D', 'L', 'R'). We are allowed to change exactly one move in the sequence to any other valid move. The goal is to determine if it is possible to reach the origin $(0, 0)$ after exactly $N$ moves by changing exactly one of the original moves.

## Intuition & Mathematical Observation
1. **Initial State**: First, calculate the final position $(X, Y)$ after executing the original sequence of moves.
2. **Effect of Changing a Move**:
   - Changing 'U' to 'D' changes the Y-coordinate by $-2$ (from $+1$ to $-1$).
   - Changing 'D' to 'U' changes the Y-coordinate by $+2$ (from $-1$ to $+1$).
   - Changing 'L' to 'R' changes the X-coordinate by $+2$ (from $-1$ to $+1$).
   - Changing 'R' to 'L' changes the X-coordinate by $-2$ (from $+1$ to $-1$).
3. **Target Condition**: We want the final position $(X', Y')$ to be $(0, 0)$.
   - If we change a move, the new position $(X', Y')$ is calculated by applying the delta associated with that specific change to the original $(X, Y)$.
   - We iterate through every move in the string, simulate the change, and check if the resulting position is $(0, 0)$. If any such change results in $(0, 0)$, the answer is "YES".

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform one pass to calculate the initial position and a second pass to check each possible modification.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The robot starts at (0, 0).
 * Let the final position after N moves be (X, Y).
 * If we change a move 'U' to 'D', the Y-coordinate changes by -2.
 * If we change a move 'D' to 'U', the Y-coordinate changes by +2.
 * If we change a move 'L' to 'R', the X-coordinate changes by +2.
 * If we change a move 'R' to 'L', the X-coordinate changes by -2.
 * 
 * We check if there exists at least one move that, when flipped, 
 * results in the final position (0, 0).
 */

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int x = 0, y = 0;
    // Calculate initial final position
    for (char c : s) {
        if (c == 'U') y++;
        else if (c == 'D') y--;
        else if (c == 'L') x--;
        else if (c == 'R') x++;
    }

    bool possible = false;
    // Try changing each move and check if we land on (0, 0)
    for (char c : s) {
        int nx = x, ny = y;
        if (c == 'U') {
            ny -= 2;
        } else if (c == 'D') {
            ny += 2;
        } else if (c == 'L') {
            nx += 2;
        } else if (c == 'R') {
            nx -= 2;
        }
        
        if (nx == 0 && ny == 0) {
            possible = true;
            break;
        }
    }

    if (possible) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
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