#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers X and Y representing the runtime on the old and new systems respectively.
 * A smaller runtime indicates a faster system.
 * - If X < Y, the old system is faster (Old).
 * - If X > Y, the new system is faster (New).
 * - If X == Y, they are equally fast (Same).
 * 
 * Constraints: 1 <= X, Y <= 3000.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice is to handle input as provided.
    if (cin >> X >> Y) {
        if (X < Y) {
            cout << "Old" << "\n";
        } else if (Y < X) {
            cout << "New" << "\n";
        } else {
            cout << "Same" << "\n";
        }
    }

    return 0;
}