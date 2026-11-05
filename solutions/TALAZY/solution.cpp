#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Jem has N problems.
 * In each step:
 * 1. He calculates the number of problems to solve before the next break:
 *    If N is even, solve N/2 problems.
 *    If N is odd, solve (N+1)/2 problems.
 * 2. Time taken for this batch = (problems_to_solve) * M.
 * 3. Update N = N - problems_to_solve.
 * 4. If N > 0, add break time B to total time.
 * 5. Update M = M * 2.
 * 
 * Constraints:
 * N, B, M up to 10^8.
 * Total time can exceed 2^31 - 1, so use long long.
 * The number of iterations is logarithmic (O(log N)) because N is halved each time.
 */

void solve() {
    long long N, B, M;
    cin >> N >> B >> M;

    long long total_time = 0;
    long long current_M = M;

    while (N > 0) {
        long long problems_to_solve;
        if (N % 2 == 0) {
            problems_to_solve = N / 2;
        } else {
            problems_to_solve = (N + 1) / 2;
        }

        total_time += (problems_to_solve * current_M);
        N -= problems_to_solve;

        if (N > 0) {
            total_time += B;
            current_M *= 2;
        }
    }

    cout << total_time << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}