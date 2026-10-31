#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the minimum integer n such that:
 * (10*X + 100*n) / (10 + n) >= Y
 * 10*X + 100*n >= 10*Y + n*Y
 * n*(100 - Y) >= 10*(Y - X)
 * n >= (10 * (Y - X)) / (100 - Y)
 * 
 * Since we need the minimum integer n, we use ceiling division.
 * For integers a/b, ceil(a/b) can be calculated as (a + b - 1) / b.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;

    int numerator = 10 * (Y - X);
    int denominator = 100 - Y;

    // Ceiling division: (numerator + denominator - 1) / denominator
    int n = (numerator + denominator - 1) / denominator;

    cout << n << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}