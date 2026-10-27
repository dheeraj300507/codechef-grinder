#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total players = 2N
 * Rated players = X
 * Unrated players = 2N - X
 * 
 * We want to pair rated players with unrated players as much as possible to minimize
 * the number of rated-rated pairs.
 * 
 * Each pair of (rated, unrated) uses 1 rated player and 1 unrated player.
 * We can form at most (2N - X) such pairs because there are only (2N - X) unrated players.
 * 
 * After using all (2N - X) unrated players, we have used (2N - X) rated players.
 * The remaining rated players are: X - (2N - X) = 2X - 2N.
 * 
 * If 2X - 2N <= 0, it means we can pair all rated players with unrated players 
 * (or there are no rated players left), so the answer is 0.
 * 
 * If 2X - 2N > 0, these remaining rated players must be paired with each other.
 * Each pair of (rated, rated) contributes 2 to the count of rated players with rated opponents.
 * Thus, the answer is 2X - 2N.
 * 
 * Combining these, the answer is max(0, 2X - 2N).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        // Calculate remaining rated players after pairing with all unrated players
        long long remaining_rated = x - (2 * n - x);
        
        if (remaining_rated <= 0) {
            cout << 0 << "\n";
        } else {
            cout << remaining_rated << "\n";
        }
    }
    return 0;
}