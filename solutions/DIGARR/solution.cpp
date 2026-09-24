#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * A number is a multiple of 5 if and only if its last digit is 0 or 5.
 * By rearranging the digits of N, we can place any digit at the end.
 * Therefore, if the string N contains at least one '0' or at least one '5',
 * we can always form a multiple of 5.
 * 
 * Complexity:
 * Time: O(D) per test case, where D is the number of digits.
 * Space: O(D) to store the string of digits.
 */

void solve() {
    int D;
    if (!(cin >> D)) return;
    string N;
    cin >> N;

    bool found = false;
    for (char c : N) {
        if (c == '0' || c == '5') {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}