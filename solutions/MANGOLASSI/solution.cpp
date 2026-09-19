#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Summer Time
 * Logic: Mamalesh drinks mango lassi if temperature X > 35.
 * Constraints: 1 <= X <= 50.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // Check if temperature is strictly greater than 35
    if (X > 35) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}