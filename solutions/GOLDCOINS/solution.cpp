#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef receives A coins if he wins (X > Y).
 * Chef receives B coins if he loses (X < Y).
 * Given X != Y, we simply compare X and Y to determine the outcome.
 * Constraints are small (A, B <= 10), so standard integer types are sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run based on the input format.
    // However, if the platform expects handling multiple test cases, the structure is provided.
    // Given the problem description "The first and only line of input...", we read once.
    
    int A, B, X, Y;
    if (cin >> A >> B >> X >> Y) {
        if (X > Y) {
            // Chef wins
            cout << A << "\n";
        } else {
            // Chef loses
            cout << B << "\n";
        }
    }

    return 0;
}