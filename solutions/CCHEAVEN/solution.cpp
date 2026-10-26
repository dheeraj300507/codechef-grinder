#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to check if there exists any prefix of length L' (1 <= L' <= L)
 * such that the number of '1's in that prefix is >= 50% of L'.
 * 
 * Condition: good_years / L' >= 0.5  =>  2 * good_years >= L'
 * 
 * Complexity:
 * Time: O(L) per test case, O(sum of L) total.
 * Space: O(L) to store the string.
 * This is optimal. The TLE might have been due to I/O overhead or 
 * specific environment constraints.
 */

void solve() {
    int L;
    if (!(cin >> L)) return;
    string S;
    cin >> S;

    int good_years = 0;
    bool possible = false;

    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years++;
        }
        
        // Current length is i + 1
        // Check if good_years / (i + 1) >= 0.5
        // Equivalent to 2 * good_years >= i + 1
        if (2 * good_years >= (i + 1)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}