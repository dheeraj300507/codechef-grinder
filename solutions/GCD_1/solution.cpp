#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct an N x M matrix such that the GCD of every row and every column is 1.
 * Elements must be >= 2.
 * 
 * A simple construction strategy:
 * Use two coprime numbers, say 2 and 3.
 * We can place 2s and 3s in a pattern such that every row and column contains at least one 2 and at least one 3.
 * Since GCD(2, 3) = 1, if a row/column contains both 2 and 3, its GCD will be 1.
 * 
 * Let's use a diagonal-based approach:
 * A[i][j] = 2 if (i + j) % 2 == 0
 * A[i][j] = 3 if (i + j) % 2 != 0
 * 
 * However, this only works if every row and column has both a 2 and a 3.
 * For N, M >= 2, this pattern ensures that every row and column has at least one 2 and one 3,
 * provided the dimensions allow it.
 * 
 * Actually, a more robust way is to use a shifted pattern:
 * A[i][j] = 2 if (i + j) % 2 == 0
 * A[i][j] = 3 if (i + j) % 2 != 0
 * This works for all N, M >= 2.
 * 
 * Example 2x3:
 * (0,0): 2, (0,1): 3, (0,2): 2
 * (1,0): 3, (1,1): 2, (1,2): 3
 * Row 0: GCD(2,3,2) = 1. Row 1: GCD(3,2,3) = 1.
 * Col 0: GCD(2,3) = 1. Col 1: GCD(3,2) = 1. Col 2: GCD(2,3) = 1.
 * This satisfies the condition.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if ((i + j) % 2 == 0) {
                cout << 2 << (j == M - 1 ? "" : " ");
            } else {
                cout << 3 << (j == M - 1 ? "" : " ");
            }
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}