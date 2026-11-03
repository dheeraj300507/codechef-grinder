#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: MOVIEWKN
 * Approach:
 * We need to select a movie based on three criteria in order of priority:
 * 1. Maximal product of L[i] * R[i].
 * 2. If products are equal, maximal R[i].
 * 3. If products and ratings are equal, minimal index (1-based).
 * 
 * Since n is small (up to 100), we can iterate through all movies and keep track 
 * of the best movie found so far based on these criteria.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> L(n), R(n);
    for (int i = 0; i < n; ++i) cin >> L[i];
    for (int i = 0; i < n; ++i) cin >> R[i];

    int best_idx = 0; // 0-based index of the best movie
    long long max_prod = -1;
    long long max_rating = -1;

    for (int i = 0; i < n; ++i) {
        long long current_prod = L[i] * R[i];
        
        if (current_prod > max_prod) {
            max_prod = current_prod;
            max_rating = R[i];
            best_idx = i;
        } else if (current_prod == max_prod) {
            if (R[i] > max_rating) {
                max_rating = R[i];
                best_idx = i;
            } else if (R[i] == max_rating) {
                // If ratings are equal, we prefer the smaller index.
                // Since we iterate from 0 to n-1, the first one we encounter
                // is already the smallest index. No action needed.
                continue;
            }
        }
    }

    // Output 1-based index
    cout << best_idx + 1 << "\n";
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