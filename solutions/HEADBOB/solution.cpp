#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Logic:
 * - 'I' is the Indian head-bob. If found, the person is definitely INDIAN.
 * - 'Y' is the standard "Yes" gesture. If found, the person is NOT INDIAN.
 * - 'N' is the "No" gesture. If only 'N's are present, we cannot determine the origin (NOT SURE).
 * 
 * Complexity:
 * - Time: O(N) per test case, where N is the length of the string.
 * - Space: O(N) to store the input string.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    bool found_i = false;
    bool found_y = false;

    for (char c : s) {
        if (c == 'I') {
            found_i = true;
            break;
        } else if (c == 'Y') {
            found_y = true;
            break;
        }
    }

    if (found_i) {
        cout << "INDIAN" << "\n";
    } else if (found_y) {
        cout << "NOT INDIAN" << "\n";
    } else {
        cout << "NOT SURE" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}