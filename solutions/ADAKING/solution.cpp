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