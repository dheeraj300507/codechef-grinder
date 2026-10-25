#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Total matches = N
 * Matches played = M
 * Matches remaining = R = N - M
 * Alice's current wins = A
 * Bob's current wins = B = M - A
 * 
 * For a tie, both must have N/2 wins.
 * This is only possible if N is even.
 * If N is even, Alice needs (N/2 - A) more wins.
 * Let x = N/2 - A.
 * We need 0 <= x <= R.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    string S;
    cin >> S;

    if (N % 2 != 0) {
        cout << "No" << "\n";
        return;
    }

    int alice_wins = 0;
    for (char c : S) {
        if (c == '1') {
            alice_wins++;
        }
    }

    int target = N / 2;
    int needed = target - alice_wins;
    int remaining = N - M;

    if (needed >= 0 && needed <= remaining) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}