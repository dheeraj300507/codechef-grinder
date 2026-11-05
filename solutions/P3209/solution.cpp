#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N players, each with a score gcd(i, N).
 * Sorting criteria:
 * 1. Higher score comes first.
 * 2. If scores are equal, smaller player index comes first.
 * 
 * Since N is small (up to 100), we can simply store pairs of (score, player_index)
 * and sort them according to the criteria.
 * 
 * Sorting criteria for pair (s1, i1) and (s2, i2):
 * - If s1 != s2, we want higher score first: s1 > s2.
 * - If s1 == s2, we want smaller index first: i1 < i2.
 */

struct Player {
    int id;
    int score;
};

bool comparePlayers(const Player& a, const Player& b) {
    if (a.score != b.score) {
        return a.score > b.score; // Higher score first
    }
    return a.id < b.id; // Smaller index first
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int N;
    cin >> N;
    vector<Player> players(N);
    for (int i = 1; i <= N; ++i) {
        players[i - 1] = {i, gcd(i, N)};
    }
    
    sort(players.begin(), players.end(), comparePlayers);
    
    for (int i = 0; i < N; ++i) {
        cout << players[i].id << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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