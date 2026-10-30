#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: INTMTCH
 * Logic:
 * The problem asks to check if the absolute difference between X and Y is <= 2.
 * The input format specifies two integers X and Y directly, without a test case count.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    // Read X and Y directly as per the problem format
    if (cin >> x >> y) {
        // Calculate absolute difference
        int diff = abs(x - y);

        // Check condition
        if (diff <= 2) {
            cout << "Interesting" << endl;
        } else {
            cout << "Boring" << endl;
        }
    }

    return 0;
}