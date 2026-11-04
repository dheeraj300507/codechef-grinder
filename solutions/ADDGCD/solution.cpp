#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to find the minimum operations to make gcd(X+a, Y+b) > 1,
 * where a, b >= 0 are the number of increments.
 * 
 * If gcd(X, Y) > 1, the answer is 0.
 * If we want to reach a common divisor Z, we need:
 * X + a = k1 * Z
 * Y + b = k2 * Z
 * 
 * Since we want to minimize (a + b), we can iterate over possible values of Z.
 * However, Z can be any integer > 1.
 * Notice that if we pick Z = 2, we need:
 * a = (2 - (X % 2)) % 2
 * b = (2 - (Y % 2)) % 2
 * Total operations = a + b.
 * 
 * For Z = 2:
 * If X is even, a=0. If X is odd, a=1.
 * If Y is even, b=0. If Y is odd, b=1.
 * Max operations for Z=2 is 1+1 = 2.
 * 
 * Can we do better than 2?
 * If gcd(X, Y) > 1, answer is 0.
 * If gcd(X+1, Y) > 1 or gcd(X, Y+1) > 1, answer is 1.
 * Otherwise, the answer is 2 (by making both even).
 * 
 * Since the constraints are up to 10^9, we check:
 * 1. gcd(X, Y) > 1 -> 0
 * 2. gcd(X+1, Y) > 1 or gcd(X, Y+1) > 1 -> 1
 * 3. Otherwise -> 2
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (gcd(X, Y) > 1) {
        cout << 0 << "\n";
        return;
    }

    if (gcd(X + 1, Y) > 1 || gcd(X, Y + 1) > 1) {
        cout << 1 << "\n";
        return;
    }

    cout << 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}