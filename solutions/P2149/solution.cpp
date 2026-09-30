#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a red rectangle (A x B) and a blue square (X x X).
 * We want Area(Rectangle) <= Area(Square), i.e., A * B <= X * X.
 * Each change of a dimension (A or B) costs 1 unit.
 * Since we want to minimize cost, we check:
 * 0 moves: If A * B <= X * X, cost is 0.
 * 1 move: If we can change A to A' or B to B' such that A' * B <= X * X or A * B' <= X * X.
 *         Since we want to minimize the area, we can change a dimension to 1.
 *         If A * 1 <= X * X or 1 * B <= X * X, cost is 1.
 * 2 moves: If neither 0 nor 1 move works, we can change both dimensions to 1.
 *          1 * 1 <= X * X is always true since X >= 1. So cost is 2.
 */

void solve() {
    int A, B, X;
    cin >> A >> B >> X;

    long long rectArea = (long long)A * B;
    long long squareArea = (long long)X * X;

    // Case 0: Already satisfied
    if (rectArea <= squareArea) {
        cout << 0 << "\n";
        return;
    }

    // Case 1: Can we satisfy by changing one dimension?
    // We can change A to 1 or B to 1.
    // New area would be 1 * B or A * 1.
    if (B <= squareArea || A <= squareArea) {
        cout << 1 << "\n";
        return;
    }

    // Case 2: Change both dimensions to 1.
    // 1 * 1 = 1, and since X >= 1, 1 <= X*X is always true.
    cout << 2 << "\n";
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