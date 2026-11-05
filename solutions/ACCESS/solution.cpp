#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We start with 0 swipes.
 * - If S[i] == '1', swipes become X.
 * - If S[i] == '0', we must have at least 1 swipe, and then we decrement it.
 * - If at any point we encounter '0' and swipes == 0, the process is invalid.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    int current_swipes = 0;
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            // Renewal: reset swipes to X
            current_swipes = X;
        } else {
            // Swipe: check if we have any swipes left
            if (current_swipes > 0) {
                current_swipes--;
            } else {
                // No swipes left, cannot access the door
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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