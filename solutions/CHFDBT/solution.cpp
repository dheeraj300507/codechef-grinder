#include <iostream>

/**
 * Problem Analysis:
 * F(X) = F(2*X) implies that any integer X can be represented as X = m * 2^p,
 * where m is the largest odd divisor of X.
 * Thus, F(X) = F(m).
 * The set of values {F(1), F(2), ..., F(N)} is equivalent to the set of values
 * {F(m) | m is an odd integer and 1 <= m <= N}.
 * To maximize the number of distinct values, we assign a unique value to each 
 * distinct odd integer m in the range [1, N].
 * The number of odd integers in [1, N] is (N + 1) / 2.
 */

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            long long n;
            cin >> n;
            // The number of odd integers in [1, N] is (N + 1) / 2
            long long result = (n + 1) / 2;
            cout << result << "\n";
        }
    }

    return 0;
}