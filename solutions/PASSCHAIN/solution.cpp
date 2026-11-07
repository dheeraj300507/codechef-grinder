#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We start at player 1.
 * While current_player + K <= N:
 *     current_player = current_player + K
 * The final value of current_player is the answer.
 * 
 * Constraints: N, K <= 50. The simulation will run at most 50 times,
 * which is O(N/K) per test case. With T=2500, this is well within limits.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    int current_player = 1;
    
    // Simulate the passing chain
    while (current_player + K <= N) {
        current_player += K;
    }
    
    cout << current_player << endl;
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