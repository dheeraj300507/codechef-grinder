#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * A simple construction is to pick numbers around X.
 * Let A1 = X - 1, A2 = X, A3 = X + 1.
 * Sum = (X - 1) + X + (X + 1) = 3X.
 * Mean = 3X / 3 = X.
 * 
 * Constraints:
 * 1 <= A1, A2, A3 <= 1000
 * 2 <= X <= 100
 * 
 * If X = 2:
 * A1 = 2 - 1 = 1
 * A2 = 2
 * A3 = 2 + 1 = 3
 * 1, 2, 3 are distinct and 1+2+3 = 6, 6/3 = 2.
 * This construction works for all X >= 2.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Using the construction A1 = x-1, A2 = x, A3 = x+1
        // Since x >= 2, x-1 >= 1, which satisfies the lower bound.
        // Since x <= 100, x+1 <= 101, which satisfies the upper bound.
        // The numbers are distinct because (x-1) < x < (x+1).
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}