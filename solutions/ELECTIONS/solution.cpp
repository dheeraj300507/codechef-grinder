#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 101 citizens. A party wins if they receive strictly more than 50 votes.
 * Since 50 * 2 = 100, and the total is 101, it is mathematically impossible for 
 * two parties to have > 50 votes simultaneously.
 * We simply check if X_A > 50, X_B > 50, or X_C > 50.
 * If none satisfy this, output NOTA.
 */

void solve() {
    long long XA, XB, XC;
    if (!(cin >> XA >> XB >> XC)) return;

    if (XA > 50) {
        cout << "A" << "\n";
    } else if (XB > 50) {
        cout << "B" << "\n";
    } else if (XC > 50) {
        cout << "C" << "\n";
    } else {
        cout << "NOTA" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}