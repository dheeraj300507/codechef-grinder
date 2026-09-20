#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice starts with rating X and needs to reach at least Y.
 * Each win increases the rating by 8.
 * Let n be the number of games won.
 * We need: X + 8 * n >= Y
 * 8 * n >= Y - X
 * n >= (Y - X) / 8
 * Since n must be an integer, n = ceil((Y - X) / 8).
 * 
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b
 * for positive integers a and b.
 * Here, a = Y - X, b = 8.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (x >= y) {
            cout << 0 << "\n";
        } else {
            long long diff = y - x;
            // Calculate ceiling of diff / 8
            long long n = (diff + 7) / 8;
            cout << n << "\n";
        }
    }

    return 0;
}