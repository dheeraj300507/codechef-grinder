#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two options:
 * 1. Use only normal attacks:
 *    The number of attacks required is ceil(H / X).
 *    In integer arithmetic, this is (H + X - 1) / X.
 * 
 * 2. Use the special attack once, then normal attacks:
 *    The special attack reduces health by Y.
 *    Remaining health = H - Y.
 *    If H - Y <= 0, the total attacks needed is 1.
 *    Otherwise, the number of normal attacks needed is ceil((H - Y) / X).
 *    Total attacks = 1 + ceil((H - Y) / X).
 * 
 * We want the minimum of these two options.
 */

void solve() {
    long long H, X, Y;
    cin >> H >> X >> Y;

    // Option 1: Only normal attacks
    long long attacks_only_normal = (H + X - 1) / X;

    // Option 2: Special attack once + normal attacks
    long long attacks_with_special;
    if (H <= Y) {
        attacks_with_special = 1;
    } else {
        long long remaining_health = H - Y;
        attacks_with_special = 1 + (remaining_health + X - 1) / X;
    }

    cout << min(attacks_only_normal, attacks_with_special) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}