#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Grade The Steel
 * Logic:
 * Condition 1: Hardness > 50
 * Condition 2: Carbon < 0.7
 * Condition 3: Tensile > 5600
 * 
 * Grade 10: All 3 met
 * Grade 9: (1) and (2) met
 * Grade 8: (2) and (3) met
 * Grade 7: (1) and (3) met
 * Grade 6: Only 1 met
 * Grade 5: None met
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double h, c, ts;
        cin >> h >> c >> ts;

        bool cond1 = (h > 50);
        bool cond2 = (c < 0.7);
        bool cond3 = (ts > 5600);

        int count = (cond1 ? 1 : 0) + (cond2 ? 1 : 0) + (cond3 ? 1 : 0);

        if (cond1 && cond2 && cond3) {
            cout << 10 << "\n";
        } else if (cond1 && cond2) {
            cout << 9 << "\n";
        } else if (cond2 && cond3) {
            cout << 8 << "\n";
        } else if (cond1 && cond3) {
            cout << 7 << "\n";
        } else if (count == 1) {
            cout << 6 << "\n";
        } else {
            cout << 5 << "\n";
        }
    }

    return 0;
}