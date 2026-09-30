#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/**
 * Problem: BOX2
 * Approach:
 * Let S = X + Y. We want to reach a state where |X' - Y'| = K.
 * Since X' + Y' = S, we have:
 * X' - Y' = K  => 2X' = S + K => X' = (S + K) / 2
 * X' - Y' = -K => 2X' = S - K => X' = (S - K) / 2
 * 
 * For a solution to exist:
 * 1. (S + K) must be even (i.e., S and K have the same parity).
 * 2. S >= K (since stones cannot be negative).
 * 
 * The number of moves is the absolute difference between the current X and the target X'.
 */

void solve() {
    long long X, Y, K;
    if (!(cin >> X >> Y >> K)) return;

    long long S = X + Y;

    // Check parity and feasibility
    if ((S + K) % 2 != 0 || S < K) {
        cout << -1 << endl;
        return;
    }

    // Target X' can be (S + K) / 2 or (S - K) / 2
    // We want to minimize |X - X'|
    long long target1 = (S + K) / 2;
    long long target2 = (S - K) / 2;

    long long ans = min(abs(X - target1), abs(X - target2));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}