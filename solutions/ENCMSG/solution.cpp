#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Step 1: Swap adjacent characters in pairs (0,1), (2,3), etc.
 *    If N is odd, the last character remains unchanged.
 * 2. Step 2: Replace each character 'c' with its mirror in the alphabet.
 *    'a' (0) -> 'z' (25), 'b' (1) -> 'y' (24), ..., 'z' (25) -> 'a' (0).
 *    Formula: new_char = 'z' - (old_char - 'a')
 * 
 * Complexity:
 * Time: O(N) per test case, O(T*N) total. Given N <= 100 and T <= 1000, 
 * this is well within the 1s time limit.
 * Space: O(N) to store the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Step 1: Swap pairs
    for (int i = 0; i + 1 < N; i += 2) {
        swap(S[i], S[i + 1]);
    }

    // Step 2: Replace characters
    for (int i = 0; i < N; ++i) {
        // 'a' is 97, 'z' is 122
        // The mapping is: char -> 'z' - (char - 'a')
        S[i] = 'z' - (S[i] - 'a');
    }

    cout << S << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}