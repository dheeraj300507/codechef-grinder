#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: TCS Examination
 * Logic:
 * We need to compare two students (Dragon and Sloth) based on a hierarchy of criteria:
 * 1. Total score (DSA + TOC + DM)
 * 2. DSA score
 * 3. TOC score
 * 
 * We can represent these criteria as a tuple (Total, DSA, TOC) and compare them lexicographically.
 */

void solve() {
    int d_dsa, d_toc, d_dm;
    int s_dsa, s_toc, s_dm;

    cin >> d_dsa >> d_toc >> d_dm;
    cin >> s_dsa >> s_toc >> s_dm;

    int d_total = d_dsa + d_toc + d_dm;
    int s_total = s_dsa + s_toc + s_dm;

    // Compare based on the criteria provided
    if (d_total > s_total) {
        cout << "DRAGON" << "\n";
    } else if (s_total > d_total) {
        cout << "SLOTH" << "\n";
    } else {
        // Total scores are tied, check DSA
        if (d_dsa > s_dsa) {
            cout << "DRAGON" << "\n";
        } else if (s_dsa > d_dsa) {
            cout << "SLOTH" << "\n";
        } else {
            // DSA scores are tied, check TOC
            if (d_toc > s_toc) {
                cout << "DRAGON" << "\n";
            } else if (s_toc > d_toc) {
                cout << "SLOTH" << "\n";
            } else {
                // Everything is tied
                cout << "TIE" << "\n";
            }
        }
    }
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