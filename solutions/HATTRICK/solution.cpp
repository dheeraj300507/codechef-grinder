#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HATTRICK
 * A hattrick occurs if there are three consecutive 'W's in the sequence of 6 balls.
 * We read the 6 inputs as strings and check for the patterns:
 * (W, W, W, x, x, x), (x, W, W, W, x, x), or (x, x, W, W, W, x), or (x, x, x, W, W, W)
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string s[6];
        for (int i = 0; i < 6; ++i) {
            cin >> s[i];
        }

        bool hattrick = false;
        // Check for 3 consecutive Ws
        // Possible starting indices for a sequence of 3 are 0, 1, 2, 3
        for (int i = 0; i <= 3; ++i) {
            if (s[i] == "W" && s[i + 1] == "W" && s[i + 2] == "W") {
                hattrick = true;
                break;
            }
        }

        if (hattrick) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}