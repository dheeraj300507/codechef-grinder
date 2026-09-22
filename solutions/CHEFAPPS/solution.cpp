#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total storage = S
 * Occupied storage = X + Y
 * Free storage = S - (X + Y)
 * Required storage = Z
 * 
 * Logic:
 * 1. If Free storage >= Z, we need to delete 0 apps.
 * 2. If Free storage < Z, we check if deleting one app (the larger one, Y) is enough:
 *    (Free storage + Y) >= Z. If yes, delete 1.
 * 3. If still not enough, we must delete both apps:
 *    (Free storage + X + Y) >= Z. Since X + Y <= S, this is always true if Z <= S.
 *    So, delete 2.
 */

void solve() {
    long long S, X, Y, Z;
    if (!(cin >> S >> X >> Y >> Z)) return;

    long long free_storage = S - (X + Y);

    if (free_storage >= Z) {
        cout << 0 << "\n";
    } else if (free_storage + X >= Z || free_storage + Y >= Z) {
        // We check both X and Y, but since Y >= X, if free + X >= Z, 
        // then free + Y is definitely >= Z.
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}