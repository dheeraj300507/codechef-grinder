#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The hallway has tiles 0 to N+1.
 * Forward journey: The ball lands on tiles 0, k, 2k, ..., mk such that mk <= N+1.
 * This means the ball lands on tile x if x % k == 0.
 * 
 * Backward journey: The ball starts at N+1 and lands on (N+1), (N+1)-k, (N+1)-2k, ...
 * This means the ball lands on tile x if (N+1 - x) % k == 0.
 * 
 * We need to check if (x % k == 0) OR ((N + 1 - x) % k == 0).
 * 
 * Constraints:
 * N, x, k up to 10^9. Use long long to prevent any potential overflow,
 * though standard int is sufficient for these specific operations.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        // Check forward journey: x is a multiple of k
        bool forward = (x % k == 0);
        
        // Check backward journey: (N + 1 - x) is a multiple of k
        bool backward = ((n + 1 - x) % k == 0);

        if (forward || backward) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}