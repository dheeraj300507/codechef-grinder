#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N kids and M cookies. We need to reach a total number of cookies K
 * such that K is a multiple of N (K % N == 0) and K >= N (since each kid gets at least 1).
 * The time taken is |M - K|. We want to minimize this.
 * 
 * Let K1 be the largest multiple of N less than or equal to M.
 * K1 = (M / N) * N.
 * If K1 >= N, then K1 is a valid target. The cost is M - K1 = M % N.
 * If K1 < N, then K1 is not a valid target (because each kid must get at least 1).
 * In that case, the only valid target smaller than M is not possible, so we must 
 * look for the smallest multiple of N that is >= N.
 * The smallest multiple of N >= N is simply N itself.
 * The cost to reach N from M is N - M.
 * 
 * Let K2 be the smallest multiple of N greater than or equal to M.
 * K2 = ((M + N - 1) / N) * N.
 * Since K2 >= M and N >= 1, K2 is always >= N, so K2 is always a valid target.
 * The cost is K2 - M = (N - (M % N)) % N.
 * 
 * Combining these:
 * 1. If M < N:
 *    We must increase cookies to N. Cost = N - M.
 * 2. If M >= N:
 *    We can either decrease to the nearest multiple (M % N) or increase to the 
 *    next multiple (N - (M % N)). We take the minimum of these two.
 */

void solve() {
    long long N, M;
    cin >> N >> M;

    if (M < N) {
        cout << (N - M) << "\n";
    } else {
        long long rem = M % N;
        if (rem == 0) {
            cout << 0 << "\n";
        } else {
            // Option 1: Destroy 'rem' cookies to reach (M/N)*N
            // Option 2: Create 'N - rem' cookies to reach ((M/N)+1)*N
            cout << min(rem, N - rem) << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}