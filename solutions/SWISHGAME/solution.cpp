#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Logic:
 * 1. If the total swishes in S >= K, the game ended because he reached K swishes.
 *    Therefore, N = M.
 * 2. If the total swishes in S < K, the game ended because it became impossible
 *    to reach K swishes.
 *    The game ends at move M if: (swishes_at_M) + (N - M) < K.
 *    The smallest N satisfying this is N = M + K - swishes_at_M - 1.
 */

void solve() {
    int M, K;
    cin >> M >> K;
    string S;
    cin >> S;

    int swishes = 0;
    for (char c : S) {
        if (c == 'S') swishes++;
    }

    if (swishes >= K) {
        cout << M << "\n";
    } else {
        // The game ends when the number of remaining rings (N-M) 
        // is such that even if all are swishes, we can't reach K.
        // swishes + (N - M) = K - 1
        // N = M + K - swishes - 1
        cout << M + K - swishes - 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}