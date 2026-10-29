#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is defined as A[i] = i for 1 <= i <= N.
 * The sum of all elements in the array is TotalSum = N * (N + 1) / 2.
 * We are looking for an index x such that:
 * (Sum of all elements except A[x]) = S
 * (TotalSum - x) = S
 * Therefore, x = TotalSum - S.
 * 
 * Constraints:
 * 1 <= x <= N
 * 1 <= N <= 10^9
 * 1 <= S <= 10^18
 * 
 * Since N can be up to 10^9, TotalSum can be up to ~5 * 10^17, which fits in a long long.
 * We need to check if the calculated x satisfies 1 <= x <= N.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;

        // Calculate the sum of the first N natural numbers
        // Use __int128_t or careful multiplication to prevent overflow if N was larger,
        // but with N=10^9, N*(N+1)/2 fits in a 64-bit signed long long (max ~9e18).
        long long total_sum = n * (n + 1) / 2;

        // The equation is: total_sum - x = s
        // So, x = total_sum - s
        long long x = total_sum - s;

        // Check if x is a valid index in the array [1, N]
        if (x >= 1 && x <= n) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}