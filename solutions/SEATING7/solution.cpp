#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * N <= 100, M, K <= N.
 * The simulation approach is O(T * K * N).
 * With T=100, N=100, K=100, total operations ~ 1,000,000.
 * This is well within the time limit. The previous TLE was likely due to 
 * I/O handling or environment-specific issues.
 */

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<bool> occupied(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int seat;
        cin >> seat;
        if (seat >= 1 && seat <= N) {
            occupied[seat] = true;
        }
    }

    bool first = true;
    for (int k = 0; k < K; ++k) {
        for (int seat = 1; seat <= N; ++seat) {
            if (!occupied[seat]) {
                occupied[seat] = true;
                if (!first) cout << " ";
                cout << seat;
                first = false;
                break;
            }
        }
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}