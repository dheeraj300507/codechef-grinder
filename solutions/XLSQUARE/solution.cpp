#include <iostream>
#include <cmath>

/**
 * Problem Analysis:
 * We have N squares of side length A.
 * A mega square of side length S = m * A is composed of m * m small squares.
 * To maximize S, we need to maximize m such that m * m <= N.
 * Thus, m = floor(sqrt(N)).
 * The side length of the mega square is floor(sqrt(N)) * A.
 * 
 * Constraints:
 * N <= 10^5, A <= 10^4.
 * The result can be up to sqrt(10^5) * 10^4 ≈ 316 * 10^4 = 3,160,000.
 * This fits comfortably within a standard 32-bit integer, but using 
 * long long is safer and prevents overflow during intermediate calculations.
 */

using namespace std;

void solve() {
    long long n, a;
    if (!(cin >> n >> a)) return;

    // Calculate the maximum integer m such that m*m <= n
    // Using sqrt is safe for N up to 10^5.
    long long m = static_cast<long long>(sqrt(n));

    // The side length of the mega square is m * A
    long long result = m * a;

    cout << result << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }

    return 0;
}