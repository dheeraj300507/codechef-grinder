#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem defines the "hardest" problem as the one with the minimum number of successful submissions.
 * We are given S_A, S_B, and S_C.
 * - If S_C is the minimum, Alice wins.
 * - If S_B is the minimum, Bob wins.
 * - If S_A is the minimum, it's a Draw.
 * 
 * Constraints: 1 <= S_A, S_B, S_C <= 100, all distinct.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

void solve() {
    int sa, sb, sc;
    if (!(cin >> sa >> sb >> sc)) return;

    // Find the minimum value among the three
    int min_val = min({sa, sb, sc});

    if (min_val == sc) {
        cout << "Alice" << "\n";
    } else if (min_val == sb) {
        cout << "Bob" << "\n";
    } else {
        cout << "Draw" << "\n";
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