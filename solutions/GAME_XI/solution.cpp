#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to select 11 players total.
 * Constraints:
 * - At least 4 batsmen (b)
 * - At least 4 bowlers (w)
 * - b + w = 11
 * 
 * Possible combinations (b, w):
 * (4, 7), (5, 6), (6, 5), (7, 4)
 * 
 * We must ensure b <= N and w <= M.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<long long> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];

    if (N < 4 || M < 4 || (N + M) < 11) {
        cout << -1 << "\n";
        return;
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    vector<long long> prefA(N + 1, 0), prefB(M + 1, 0);
    for (int i = 0; i < N; ++i) prefA[i + 1] = prefA[i] + A[i];
    for (int i = 0; i < M; ++i) prefB[i + 1] = prefB[i] + B[i];

    long long max_skill = -1;

    // Valid combinations (b, w) such that b+w=11, b>=4, w>=4
    // b can range from 4 to 7
    for (int b = 4; b <= 7; ++b) {
        int w = 11 - b;
        if (b <= N && w <= M) {
            long long current_skill = prefA[b] + prefB[w];
            if (max_skill == -1 || current_skill > max_skill) {
                max_skill = current_skill;
            }
        }
    }

    cout << max_skill << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}