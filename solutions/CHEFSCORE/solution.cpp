#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N problems, each worth X marks.
 * Chef can get either 0 or X marks per problem.
 * Total score Y must be a multiple of X, specifically Y = k * X,
 * where k is the number of problems solved correctly.
 * Since there are N problems, 0 <= k <= N.
 * Therefore, Y must satisfy:
 * 1. Y % X == 0 (Y must be divisible by X)
 * 2. (Y / X) <= N (The number of problems solved cannot exceed total problems)
 * 3. Y >= 0 (Already guaranteed by constraints)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // Case where Chef scores 0: Always possible
        if (y == 0) {
            cout << "YES" << "\n";
        } 
        // Check if Y is a multiple of X and the number of problems solved is <= N
        else if (y % x == 0 && (y / x) <= n) {
            cout << "YES" << "\n";
        } 
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}