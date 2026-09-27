#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three integers A, B, and C representing the colors of three socks.
 * We need to determine if at least two of these socks have the same color.
 * This is equivalent to checking if:
 * A == B OR A == C OR B == C.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    // The problem description implies a single test case input format,
    // but we structure it to handle the input as specified.
    if (cin >> A >> B >> C) {
        if (A == B || A == C || B == C) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}