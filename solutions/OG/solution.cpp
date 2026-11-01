#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "origin" of a number is equivalent to its digital root.
 * The digital root of a positive integer n is given by:
 * dr(n) = 1 + ((n - 1) % 9)
 * 
 * The sequence of origins for n = 1, 2, 3, ... is:
 * 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, ...
 * This is a periodic sequence with period 9.
 * 
 * To find the sum of origins from 1 to N:
 * 1. The number of full periods of (1, 2, ..., 9) is q = N / 9.
 * 2. The sum of one full period is 1+2+3+4+5+6+7+8+9 = 45.
 * 3. The remainder is r = N % 9.
 * 4. The sum of the first r elements is r * (r + 1) / 2.
 * 
 * Total sum = (q * 45) + (r * (r + 1) / 2).
 * 
 * Constraints: N up to 10^18, so we must use long long.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;

        long long q = n / 9;
        long long r = n % 9;

        // Sum of full periods (each sum is 45)
        long long total_sum = q * 45;

        // Sum of the remaining r elements (1, 2, ..., r)
        // Sum = r * (r + 1) / 2
        total_sum += (r * (r + 1)) / 2;

        cout << total_sum << "\n";
    }

    return 0;
}