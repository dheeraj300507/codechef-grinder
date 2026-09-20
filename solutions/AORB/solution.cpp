#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two problems, A and B.
 * Points for A: 500 - (time_A * 2)
 * Points for B: 1000 - (time_B * 4)
 * 
 * Order 1: A then B
 * Time A = X, Time B = X + Y
 * Total = (500 - 2*X) + (1000 - 4*(X + Y))
 * 
 * Order 2: B then A
 * Time B = Y, Time A = X + Y
 * Total = (1000 - 4*Y) + (500 - 2*(X + Y))
 * 
 * We calculate both and take the maximum.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // Order A -> B
    // A is submitted at time X
    // B is submitted at time X + Y
    long long score1 = (500 - 2 * X) + (1000 - 4 * (X + Y));

    // Order B -> A
    // B is submitted at time Y
    // A is submitted at time X + Y
    long long score2 = (1000 - 4 * Y) + (500 - 2 * (X + Y));

    cout << max(score1, score2) << "\n";
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