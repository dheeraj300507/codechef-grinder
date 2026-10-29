#include <iostream>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * - 0 operations: String contains no '1's.
 * - 1 operation: String contains '1's, but no two '1's are adjacent.
 * - 2 operations: String contains at least one pair of adjacent '1's.
 * 
 * Complexity:
 * Time: O(N) per test case.
 * Space: O(N) to store the string.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    string S;
    cin >> S;

    bool has_ones = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_ones = true;
            if (i > 0 && S[i - 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_ones) {
        cout << 0 << "\n";
    } else if (has_adjacent_ones) {
        // If there are adjacent ones, we need 2 operations.
        // Example: 11 -> {1} then {2} or similar.
        cout << 2 << "\n";
    } else {
        // If there are ones but no adjacent ones, 1 operation is sufficient.
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations to prevent TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}