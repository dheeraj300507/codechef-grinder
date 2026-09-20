#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Lower Deck: 1 to 15
 * Upper Deck: 16 to 30
 * 
 * Lower Deck (1-15):
 * Single: 11, 12, 13, 14, 15
 * Double: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
 * 
 * Upper Deck (16-30):
 * Single: 26, 27, 28, 29, 30
 * Double: 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
 */

void solve() {
    int n;
    cin >> n;

    if (n >= 1 && n <= 15) {
        // Lower Deck
        if (n >= 1 && n <= 10) {
            cout << "Lower Double" << "\n";
        } else {
            cout << "Lower Single" << "\n";
        }
    } else {
        // Upper Deck
        if (n >= 16 && n <= 25) {
            cout << "Upper Double" << "\n";
        } else {
            cout << "Upper Single" << "\n";
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