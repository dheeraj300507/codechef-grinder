# [Ada School (ADASCOOL)](https://www.codechef.com/problems/ADASCOOL)

- **Difficulty Rating**: 1004
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an $N \times M$ grid of students. Each student must move to an adjacent cell (up, down, left, or right). We need to determine if it is possible for every student to move to a unique adjacent cell such that every cell is occupied by exactly one student after the move. This is equivalent to determining if the grid graph has a **perfect matching**.

## Intuition & Mathematical Observation
The problem asks whether we can pair every cell in an $N \times M$ grid with an adjacent cell. 

1.  **Parity Constraint**: A grid can be colored like a chessboard with black and white cells. In any move, a student must move from a cell of one color to a cell of the opposite color. For a perfect matching to exist, the number of black cells must equal the number of white cells.
2.  **Total Cells**: If the total number of cells ($N \times M$) is odd, the number of black and white cells will differ by 1 (e.g., in a $3 \times 3$ grid, there are 5 of one color and 4 of the other). Thus, a perfect matching is impossible.
3.  **Even Case**: If $N \times M$ is even, at least one of $N$ or $M$ must be even. If $N$ is even, we can divide the grid into $N/2$ rows of $2 \times M$ blocks, or simply tile the entire grid with $1 \times 2$ dominoes. If $M$ is even, we can tile it with $2 \times 1$ dominoes.
4.  **Conclusion**: A perfect matching exists if and only if the total number of cells $N \times M$ is even. This is true if and only if $N$ is even OR $M$ is even.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M grid of students. Each student must move to an adjacent cell.
 * This is equivalent to finding a perfect matching in the grid graph where each 
 * node (cell) is matched with an adjacent node.
 * 
 * A grid graph is a bipartite graph. A perfect matching exists if and only if 
 * the total number of vertices (N * M) is even.
 * 
 * Specifically:
 * 1. If N * M is odd, it is impossible to have a perfect matching.
 * 2. If N * M is even, at least one of N or M must be even, allowing 
 *    the grid to be tiled by dominoes.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;

        // If either N or M is even, the total number of cells N*M is even.
        // A grid with an even number of cells always allows a perfect matching.
        if (n % 2 == 0 || m % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            // If both are odd, N*M is odd, making a perfect matching impossible.
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```