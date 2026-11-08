#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wins if the number of votes for him (1s) is strictly greater than 
 * the number of votes for AntiChef (0s) at the point the counting stops.
 * 
 * Let 'c' be the count of 1s and 'a' be the count of 0s up to index i.
 * Chef wins if c > a.
 * 
 * We iterate through the string, maintaining the running counts of 1s and 0s.
 * For each prefix of length k (1 <= k <= N), we check if the condition holds.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int chef_votes = 0;
    int antichef_votes = 0;
    int win_count = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            chef_votes++;
        } else {
            antichef_votes++;
        }

        // Chef wins if he has strictly more votes than AntiChef
        if (chef_votes > antichef_votes) {
            win_count++;
        }
    }

    cout << win_count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}