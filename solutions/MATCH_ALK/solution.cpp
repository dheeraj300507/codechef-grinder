#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Man of the Match
 * Logic:
 * For each player, calculate points = (runs) + (wickets * 20).
 * Keep track of the maximum points found so far and the index of the player.
 * Since there are 22 players per test case and T test cases, 
 * the complexity will be O(T * 22), which is well within the time limit.
 */

void solve() {
    int max_points = -1;
    int man_of_the_match_index = -1;

    for (int i = 1; i <= 22; ++i) {
        int runs, wickets;
        cin >> runs >> wickets;
        
        int current_points = runs + (wickets * 20);
        
        if (current_points > max_points) {
            max_points = current_points;
            man_of_the_match_index = i;
        }
    }
    
    cout << man_of_the_match_index << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}