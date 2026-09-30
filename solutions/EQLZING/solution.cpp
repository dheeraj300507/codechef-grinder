#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can change A and B by adding/subtracting d.
 * The sum (A + B) remains invariant.
 * For A and B to be equal, A must equal B, so A + B must be 2*A (even).
 * If (A + B) is odd, it is impossible to make them equal.
 * If (A + B) is even, the difference (A - B) is even, and we can 
 * reach equality by choosing d = (B - A) / 2.
 */

void solve() {
    int A, B;
    cin >> A >> B;
    // Check if the difference is even (or if both have the same parity)
    if (abs(A - B) % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}