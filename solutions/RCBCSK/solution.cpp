#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB qualifies if (X - Y) >= 18.
 * Otherwise, CSK qualifies.
 * Constraints: 150 <= X <= 250, 150 <= Y <= X + 6.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice often involves reading until EOF
    // or handling a specific number of test cases. Given the problem description:
    if (cin >> X >> Y) {
        if (X - Y >= 18) {
            cout << "RCB" << "\n";
        } else {
            cout << "CSK" << "\n";
        }
    }

    return 0;
}