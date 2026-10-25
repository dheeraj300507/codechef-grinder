#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * 1. Roads exist between (2i+1, 2i+2) for i >= 0.
 *    This implies if |a - b| == 1, they are connected if min(a, b) is odd.
 * 2. Roads exist between consecutive odd numbers (1-3, 3-5, ...) 
 *    and consecutive even numbers (2-4, 4-6, ...).
 *    This implies if |a - b| == 2, they are always connected.
 * 
 * Complexity: O(Q) time, O(1) space.
 */

void solve() {
    long long a, b;
    if (!(cin >> a >> b)) return;

    long long diff = abs(a - b);
    long long mn = min(a, b);

    if (diff == 1) {
        // Road exists if the smaller number is odd (1-2, 3-4, 5-6...)
        if (mn % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else if (diff == 2) {
        // Road exists between consecutive odds or consecutive evens
        cout << "YES" << "\n";
    } else {
        // No other roads exist
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }

    return 0;
}