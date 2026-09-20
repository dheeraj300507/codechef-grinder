#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Alice speed = A / X
 * Bob speed = B / Y
 * To compare A/X and B/Y, compare A*Y and B*X to avoid floating point issues.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, x, b, y;
        cin >> a >> x >> b >> y;

        // Compare speeds using cross-multiplication: (a/x) vs (b/y) => a*y vs b*x
        long long alice_val = a * y;
        long long bob_val = b * x;

        if (alice_val > bob_val) {
            cout << "ALICE" << "\n";
        } else if (bob_val > alice_val) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}