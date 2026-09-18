#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: DOREWARD - Donation Rewards
 * Logic:
 * - If X <= 3: BRONZE
 * - If 3 < X <= 6: SILVER
 * - If X > 6: GOLD
 * 
 * Complexity:
 * - Time: O(T), where T is the number of test cases.
 * - Space: O(1), as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int x;
        cin >> x;

        if (x <= 3) {
            cout << "BRONZE" << "\n";
        } else if (x <= 6) {
            cout << "SILVER" << "\n";
        } else {
            cout << "GOLD" << "\n";
        }
    }

    return 0;
}