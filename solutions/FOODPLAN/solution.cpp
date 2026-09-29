#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Online cost after 10% discount = N - (0.1 * N) = 0.9 * N
 * We need to compare 0.9 * N with M.
 * To avoid floating point precision issues, multiply both sides by 10:
 * Compare (9 * N) with (10 * M).
 * 
 * Constraints: N, M <= 1000.
 * 9 * 1000 = 9000, which fits in a standard 32-bit integer.
 */

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    int online_scaled = 9 * n;
    int dining_scaled = 10 * m;

    if (online_scaled < dining_scaled) {
        cout << "ONLINE" << "\n";
    } else if (online_scaled > dining_scaled) {
        cout << "DINING" << "\n";
    } else {
        cout << "EITHER" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}