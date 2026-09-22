#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HDIVISR
 * The task is to find the largest integer x in the range [1, 10] such that N % x == 0.
 * Since the range is very small (1 to 10), we can simply iterate backwards from 10 down to 1.
 * The first number we encounter that divides N will be the largest divisor in that range.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Iterate from 10 down to 1 to find the largest divisor
    for (int i = 10; i >= 1; --i) {
        if (n % i == 0) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}