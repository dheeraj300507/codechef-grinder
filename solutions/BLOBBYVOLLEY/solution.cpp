#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Alice starts as the server.
 * - If the current server wins the point, their score increases by 1, and they remain the server.
 * - If the receiver wins the point, their score does not increase, but they become the server.
 * 
 * We can maintain a variable `current_server` ('A' or 'B') and update it based on the rules.
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the string, or O(1) if processed character by character.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long alice_score = 0;
    long long bob_score = 0;
    char current_server = 'A';

    for (int i = 0; i < N; ++i) {
        char winner = S[i];
        
        if (winner == current_server) {
            // Server wins the point
            if (winner == 'A') {
                alice_score++;
            } else {
                bob_score++;
            }
        } else {
            // Receiver wins the point, they become the new server
            current_server = winner;
        }
    }

    cout << alice_score << " " << bob_score << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}