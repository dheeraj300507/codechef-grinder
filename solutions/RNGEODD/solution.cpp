#include <iostream>

using namespace std;

/**
 * Problem: Range Odd
 * Optimized approach:
 * 1. Find the first odd number >= L.
 * 2. Iterate by adding 2 until R is reached.
 * This reduces the number of iterations and eliminates the modulo check.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, R;
    if (!(cin >> L >> R)) return 0;

    // If L is even, the first odd number is L + 1.
    // If L is odd, the first odd number is L.
    int start = (L % 2 != 0) ? L : L + 1;

    bool first = true;
    for (int i = start; i <= R; i += 2) {
        if (!first) {
            cout << " ";
        }
        cout << i;
        first = false;
    }
    cout << "\n";

    return 0;
}