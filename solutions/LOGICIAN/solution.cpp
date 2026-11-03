#include <bits/stdc++.h>
using namespace std;

/**
 * Logic Analysis:
 * The bartender asks "Does everyone want a beer?".
 * A logician can say "YES" only if they are certain that everyone wants a beer.
 * A logician can say "NO" if they are certain that at least one person does not want a beer.
 * Otherwise, they say "IDK" (I don't know).
 * 
 * Let's track the state:
 * - If any logician has said "NO", then everyone knows for sure that not everyone wants a beer.
 *   Therefore, all subsequent logicians will say "NO".
 * - If all previous logicians have said "IDK", it means they all wanted a beer (S_i == 1).
 *   If the current logician i has S_i == 0, they know not everyone wants a beer, so they say "NO".
 *   If the current logician i has S_i == 1, they still don't know about the remaining logicians, so they say "IDK".
 * - The only exception is the very last logician (N). If all previous logicians said "IDK" and the N-th logician 
 *   also has S_N == 1, they know everyone wants a beer, so they say "YES".
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool someone_said_no = false;

    for (int i = 0; i < N; ++i) {
        if (someone_said_no) {
            cout << "NO" << "\n";
            continue;
        }

        if (S[i] == '0') {
            cout << "NO" << "\n";
            someone_said_no = true;
        } else {
            // S[i] == '1'
            // If this is the last person and no one said NO yet, 
            // they know everyone wants a beer.
            if (i == N - 1) {
                cout << "YES" << "\n";
            } else {
                cout << "IDK" << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}