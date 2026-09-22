#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * N episodes, 1 to N.
 * Even indexed: 2, 4, 6... have duration A.
 * Odd indexed: 1, 3, 5... have duration B.
 * 
 * Number of even indices in [1, N] is N / 2.
 * Number of odd indices in [1, N] is N - (N / 2).
 * 
 * Total duration = (even_count * A) + (odd_count * B).
 */

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;

    int even_count = N / 2;
    int odd_count = N - even_count;

    int total_duration = (even_count * A) + (odd_count * B);
    cout << total_duration << "\n";
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