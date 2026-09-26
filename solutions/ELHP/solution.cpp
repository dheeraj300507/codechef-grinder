#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Election Hopes
 * Logic: Chef dominates if X >= 2 * Y.
 * Constraints: 1 <= X, Y <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    if (cin >> X >> Y) {
        // Check if Chef's votes are at least double Chefu's votes
        if (X >= 2 * Y) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}