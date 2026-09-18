#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A number is "pretty" if its last digit is 2, 3, or 9.
 * We need to count how many such numbers exist in the range [L, R].
 * 
 * Approach:
 * Let f(N) be the count of pretty numbers in the range [1, N].
 * The answer for [L, R] is f(R) - f(L - 1).
 * 
 * In every block of 10 numbers (e.g., 0-9, 10-19, ...), there are exactly 3 pretty numbers:
 * the ones ending in 2, 3, and 9.
 * 
 * For a number N:
 * - Full blocks of 10: (N / 10) * 3
 * - Remaining part: Check the last digit (N % 10).
 *   If the last digit is >= 2, add 1.
 *   If the last digit is >= 3, add 1.
 *   If the last digit is >= 9, add 1.
 */

long long countPretty(int n) {
    if (n < 0) return 0;
    long long count = (n / 10) * 3;
    int rem = n % 10;
    if (rem >= 2) count++;
    if (rem >= 3) count++;
    if (rem >= 9) count++;
    return count;
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int L, R;
        cin >> L >> R;
        cout << countPretty(R) - countPretty(L - 1) << "\n";
    }
    return 0;
}