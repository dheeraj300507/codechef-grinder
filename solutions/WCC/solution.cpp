#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - 14 games total.
 * - Carlsen (C) wins: 2 points.
 * - Chef (N) wins: 0 points for Carlsen.
 * - Draw (D): 1 point for Carlsen.
 * - Carlsen's total points = (count of 'C' * 2) + (count of 'D' * 1).
 * - Chef's total points = (count of 'N' * 2) + (count of 'D' * 1).
 * 
 * Prize logic:
 * - If Carlsen points > Chef points: Carlsen gets 60 * X.
 * - If Carlsen points == Chef points: Carlsen gets 55 * X.
 * - If Carlsen points < Chef points: Carlsen gets 40 * X.
 * 
 * Constraints:
 * - X up to 10^6, so prize money can be 60 * 10^6 = 60,000,000.
 * - This fits in a standard 32-bit signed integer, but using long long is safer.
 */

void solve() {
    long long X;
    cin >> X;
    string s;
    cin >> s;

    int carlsen_points = 0;
    int chef_points = 0;

    for (char c : s) {
        if (c == 'C') {
            carlsen_points += 2;
        } else if (c == 'N') {
            chef_points += 2;
        } else {
            carlsen_points += 1;
            chef_points += 1;
        }
    }

    if (carlsen_points > chef_points) {
        cout << 60 * X << "\n";
    } else if (carlsen_points == chef_points) {
        cout << 55 * X << "\n";
    } else {
        cout << 40 * X << "\n";
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