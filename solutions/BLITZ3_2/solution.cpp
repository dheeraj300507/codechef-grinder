#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each player starts with 180 seconds (3 minutes).
 * In an "a + b" match, each move adds 'b' seconds to the clock.
 * Here, a = 180 and b = 2.
 * 
 * Total time initially available to both players = 180 + 180 = 360 seconds.
 * Total time added to both players after N turns:
 * White makes floor((N+1)/2) moves.
 * Black makes floor(N/2) moves.
 * Total moves = floor((N+1)/2) + floor(N/2) = N.
 * Total time added = N * 2 seconds.
 * 
 * Total time available throughout the game = 360 + 2*N.
 * Total time remaining at the end = A + B.
 * 
 * The duration of the game is the total time consumed:
 * Duration = (Total time available) - (Total time remaining)
 * Duration = (360 + 2*N) - (A + B)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        // Total time available = 2 * 180 (initial) + 2 * N (increments)
        long long total_time_available = 360 + 2 * n;
        long long total_time_remaining = a + b;

        long long duration = total_time_available - total_time_remaining;

        cout << duration << "\n";
    }

    return 0;
}