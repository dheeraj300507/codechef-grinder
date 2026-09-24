#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: DICEGAME2
 * The score is the sum of the two highest rolls.
 * Given 3 rolls, the sum of the two highest is (sum of all three) - (minimum roll).
 */

void solve() {
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    // Calculate Alice's score
    int alice_sum = a1 + a2 + a3;
    int alice_min = min({a1, a2, a3});
    int alice_score = alice_sum - alice_min;

    // Calculate Bob's score
    int bob_sum = b1 + b2 + b3;
    int bob_min = min({b1, b2, b3});
    int bob_score = bob_sum - bob_min;

    if (alice_score > bob_score) {
        cout << "Alice" << "\n";
    } else if (bob_score > alice_score) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
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