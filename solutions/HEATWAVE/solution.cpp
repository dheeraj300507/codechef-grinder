#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Heat Wave
 * Logic: A new record high is created if the temperature on the next day (Y)
 * is strictly greater than the previous record high (X).
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // The problem description implies a single test case per run based on the input format,
    // but standard competitive programming practice handles input as specified.
    if (cin >> X >> Y) {
        if (Y > X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}