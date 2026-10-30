#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct an N x N matrix with numbers 1 to N^2 such that for any square submatrix,
 * the sum of the corners is even.
 * 
 * The condition M[r,c] + M[r+a, c+a] is even implies that M[r,c] and M[r+a, c+a] 
 * must have the same parity.
 * Similarly, M[r, c+a] + M[r+a, c] is even implies M[r, c+a] and M[r+a, c] 
 * must have the same parity.
 * 
 * A simple way to satisfy this is to fill the matrix such that the parity of the cells
 * follows a checkerboard pattern.
 * 
 * Strategy:
 * Fill the matrix row by row with numbers 1 to N^2.
 * If we fill row 1: 1, 2, 3, ..., N
 * Row 2: N+1, N+2, ..., 2N
 * ...
 * If we reverse the order of elements in every even-indexed row (0-indexed),
 * we can maintain the parity property.
 * 
 * Example N=3:
 * Row 0: 1 2 3
 * Row 1: 6 5 4 (Reversed)
 * Row 2: 7 8 9
 * 
 * Parity:
 * O E O
 * E O E
 * O E O
 * This checkerboard pattern ensures that any two cells with the same parity 
 * distance (even distance) will have the same parity, satisfying the condition.
 */

void solve() {
    int N;
    cin >> N;
    
    int current = 1;
    for (int i = 0; i < N; ++i) {
        vector<int> row(N);
        if (i % 2 == 0) {
            // Fill left to right
            for (int j = 0; j < N; ++j) {
                row[j] = current++;
            }
        } else {
            // Fill right to left
            for (int j = N - 1; j >= 0; --j) {
                row[j] = current++;
            }
        }
        
        for (int j = 0; j < N; ++j) {
            cout << row[j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}