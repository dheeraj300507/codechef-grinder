# [Ada King (ADAKING)](https://www.codechef.com/problems/ADAKING)

- **Difficulty Rating**: 1378
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given an $8 \times 8$ chessboard and an integer $K$. We need to place a King at some position $(r, c)$ on the board and mark exactly $K$ cells (including the King's position) such that the King can reach all marked cells. The remaining $64 - K$ cells must be marked as blocked ('X').

## Intuition & Mathematical Observation
The key constraint is that the King must be able to reach exactly $K$ cells. Since a King can move to any of its 8 adjacent neighbors, the simplest way to ensure connectivity is to fill the board greedily.

1. **Placement**: By placing the King at $(0, 0)$, we occupy the first cell.
2. **Filling**: We fill the board row by row, column by column. By marking the first $K$ cells as '.' (reachable) and the remaining $64 - K$ cells as 'X' (blocked), we guarantee that the King can reach every '.' cell because they are all adjacent to one another in the sequence.
3. **Representation**: 
   - 'O' represents the King's starting position at $(0, 0)$.
   - '.' represents a reachable cell.
   - 'X' represents a blocked cell.

This greedy approach works perfectly because the King's movement range covers the immediate neighbors, and filling the grid sequentially ensures no "islands" are created that the King cannot reach.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the board size is fixed at $8 \times 8 = 64$ cells, the nested loops always perform a constant number of operations (64 iterations).
- **Space Complexity**: $O(1)$. We use a fixed-size $8 \times 8$ character array, which does not scale with input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to place a king at (0, 0) and mark exactly K cells as reachable.
 * By filling the board row by row, we ensure that the first K cells are 
 * connected. Since the king can move to any adjacent cell (including diagonals),
 * placing the king at (0, 0) and filling the first K cells with '.' 
 * (and the rest with 'X') ensures the king can reach exactly those K cells.
 */

void solve() {
    int K;
    cin >> K;

    char board[8][8];
    int count = 0;

    // Fill the board: first K cells are '.', remaining are 'X'
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (count < K) {
                board[i][j] = '.';
                count++;
            } else {
                board[i][j] = 'X';
            }
        }
    }

    // Place the king at (0, 0)
    board[0][0] = 'O';

    // Print the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    // Optimize I/O operations
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