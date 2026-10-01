#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let X be the initial price, Y be the monthly increase, and Z be the monthly earnings.
 * After n months:
 * Price of GPU = X + n * Y
 * Chef's total coins = n * Z
 * 
 * Chef buys the GPU when:
 * n * Z >= X + n * Y
 * n * Z - n * Y >= X
 * n * (Z - Y) >= X
 * 
 * Case 1: If Z > Y, then n >= X / (Z - Y).
 * Since n must be an integer, n = ceil(X / (Z - Y)).
 * Using integer arithmetic, ceil(a / b) = (a + b - 1) / b.
 * 
 * Case 2: If Z <= Y, then n * (Z - Y) <= 0.
 * Since X > 0, the inequality n * (Z - Y) >= X can never be satisfied
 * because the left side is <= 0 and the right side is > 0.
 * Exception: If Z == Y, the inequality is 0 >= X, which is impossible for X >= 1.
 * Thus, if Z <= Y, output -1.
 */

void solve() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;

    if (Z <= Y) {
        cout << -1 << "\n";
    } else {
        // We need the smallest integer n such that n * (Z - Y) >= X
        // n >= X / (Z - Y)
        long long diff = Z - Y;
        long long n = (X + diff - 1) / diff;
        cout << n << "\n";
    }
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