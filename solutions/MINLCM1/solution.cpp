#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X and K. The range is [X, X*K].
 * We need to find min and max LCM(i, j) where X <= i < j <= X*K.
 * 
 * Minimum LCM:
 * To minimize LCM(i, j), we want i and j to be as close as possible and share as many factors as possible.
 * The smallest possible LCM is obtained by picking i = X and j = 2*X.
 * LCM(X, 2*X) = 2*X. Since X >= 1, this is always valid as long as 2*X <= X*K (which is true since K >= 2).
 * 
 * Maximum LCM:
 * To maximize LCM(i, j), we want i and j to be as large as possible and share as few factors as possible (ideally coprime).
 * Let M = X * K. We want to pick two numbers close to M that are coprime.
 * The pair (M-1, M) are always coprime because gcd(M-1, M) = 1.
 * Thus, LCM(M-1, M) = (M-1) * M.
 * Since M = X * K, the maximum LCM is (X*K - 1) * (X*K).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, K;
        cin >> X >> K;

        // Minimum LCM:
        // Choosing i = X and j = 2*X gives LCM(X, 2*X) = 2*X.
        long long min_lcm = 2 * X;

        // Maximum LCM:
        // Let M = X * K. The largest possible values are M and M-1.
        // Since gcd(M, M-1) = 1, their LCM is M * (M-1).
        long long M = X * K;
        long long max_lcm = M * (M - 1);

        cout << min_lcm << " " << max_lcm << "\n";
    }

    return 0;
}