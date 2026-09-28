#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the number of pairs (A, B) such that 1 <= A, B <= N and A + B is odd.
 * A + B is odd if and only if one of the numbers is even and the other is odd.
 * 
 * In the range [1, N]:
 * - Number of odd integers: ceil(N / 2) = (N + 1) / 2
 * - Number of even integers: floor(N / 2) = N / 2
 * 
 * Let 'odd_count' be the number of odd integers and 'even_count' be the number of even integers.
 * A pair (A, B) has an odd sum if:
 * 1. A is odd and B is even: There are (odd_count * even_count) such pairs.
 * 2. A is even and B is odd: There are (even_count * odd_count) such pairs.
 * 
 * Total pairs = 2 * (odd_count * even_count)
 * 
 * Constraints: N <= 10^9, so N*N can exceed 2^31-1. We must use long long.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long odd_count = (n + 1) / 2;
        long long even_count = n / 2;

        // The number of pairs is 2 * (odd * even)
        long long result = 2 * odd_count * even_count;

        cout << result << "\n";
    }

    return 0;
}