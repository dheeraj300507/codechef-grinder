#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: BESTMOVIE
 * Approach:
 * We need to find the minimum cost (B_i) among all movies where the IMDB score (A_i) is >= 7.
 * We initialize a variable 'min_cost' to a value larger than any possible cost (e.g., 2000).
 * We iterate through all N movies, and if A_i >= 7, we update min_cost = min(min_cost, B_i).
 * If after checking all movies min_cost remains unchanged, we output -1.
 */

void solve() {
    int N;
    cin >> N;
    
    int min_cost = 2000; // Since max B_i is 1000, 2000 is a safe infinity
    bool found = false;
    
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        if (a >= 7) {
            if (b < min_cost) {
                min_cost = b;
            }
            found = true;
        }
    }
    
    if (found) {
        cout << min_cost << "\n";
    } else {
        cout << -1 << "\n";
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