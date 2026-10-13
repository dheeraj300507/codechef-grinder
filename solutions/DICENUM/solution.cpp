#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the maximum number from three digits, we should sort the digits 
 * in descending order and concatenate them.
 * For example, if Alice rolls 3, 2, 5, the maximum number is 532.
 * We calculate the maximum number for both Alice and Bob and compare them.
 */

int get_max_score(int d1, int d2, int d3) {
    vector<int> dice = {d1, d2, d3};
    // Sort in descending order to form the largest possible number
    sort(dice.begin(), dice.end(), greater<int>());
    
    // Construct the number: digit1 * 100 + digit2 * 10 + digit3
    return dice[0] * 100 + dice[1] * 10 + dice[2];
}

void solve() {
    int a1, a2, a3, b1, b2, b3;
    if (!(cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3)) return;
    
    int alice_score = get_max_score(a1, a2, a3);
    int bob_score = get_max_score(b1, b2, b3);
    
    if (alice_score > bob_score) {
        cout << "Alice" << "\n";
    } else if (bob_score > alice_score) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
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