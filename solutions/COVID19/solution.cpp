#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N people at positions X_1, X_2, ..., X_N.
 * The virus spreads if the distance between two people is <= 2.
 * This is a transitive property: if A infects B, and B infects C, then A infects C.
 * For each person i, we can simulate the spread by checking adjacent distances.
 * If X_{j+1} - X_j <= 2, the infection spreads from j to j+1.
 * We can calculate the size of the connected component for each starting person i.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    int min_infected = N;
    int max_infected = 1;

    // Try starting the infection from each person i
    for (int i = 0; i < N; ++i) {
        int current_infected = 1;
        
        // Look to the right
        for (int j = i; j < N - 1; ++j) {
            if (X[j + 1] - X[j] <= 2) {
                current_infected++;
            } else {
                break;
            }
        }
        
        // Look to the left
        for (int j = i; j > 0; --j) {
            if (X[j] - X[j - 1] <= 2) {
                current_infected++;
            } else {
                break;
            }
        }
        
        if (current_infected < min_infected) {
            min_infected = current_infected;
        }
        if (current_infected > max_infected) {
            max_infected = current_infected;
        }
    }

    cout << min_infected << " " << max_infected << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}