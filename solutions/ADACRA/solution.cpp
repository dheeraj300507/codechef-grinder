#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a string of 'U' and 'D'. We want to make all characters the same.
 * A flip operation on a segment [i, j] changes all 'U' to 'D' and 'D' to 'U'.
 * 
 * Let's count the number of contiguous blocks of 'U's and 'D's.
 * For example, "UUDDDUUU" has blocks: "UU", "DDD", "UUU".
 * Number of 'U' blocks = 2, Number of 'D' blocks = 1.
 * 
 * To make all 'U', we need to flip all 'D' blocks.
 * To make all 'D', we need to flip all 'U' blocks.
 * The minimum number of steps is simply min(count of 'U' blocks, count of 'D' blocks).
 */

void solve() {
    string s;
    cin >> s;
    if (s.empty()) {
        cout << 0 << "\n";
        return;
    }

    int u_blocks = 0;
    int d_blocks = 0;

    // Count contiguous blocks
    for (int i = 0; i < s.length(); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            if (s[i] == 'U') {
                u_blocks++;
            } else {
                d_blocks++;
            }
        }
    }

    cout << min(u_blocks, d_blocks) << "\n";
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