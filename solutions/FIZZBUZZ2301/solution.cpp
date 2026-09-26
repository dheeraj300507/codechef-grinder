#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Fan Poll
 * Dhoni (A), Rohit (B), Kohli (C)
 * Dhoni wins if A > B and A > C.
 * Since it is guaranteed that no two players received the same number of votes,
 * we only need to check if A is strictly greater than B and C.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice suggests handling input as provided.
    if (cin >> A >> B >> C) {
        if (A > B && A > C) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}