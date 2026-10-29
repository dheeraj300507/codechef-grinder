#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * Each 4-bit block represents a character from 'a' to 'p'.
 * 'a' is 0000 (0), 'b' is 0001 (1), ..., 'p' is 1111 (15).
 * We can convert the 4-bit binary string to an integer and add it to 'a'.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    string result = "";
    for (int i = 0; i < N; i += 4) {
        int val = 0;
        // Convert 4-bit substring to integer
        for (int j = 0; j < 4; ++j) {
            val = (val << 1) + (S[i + j] - '0');
        }
        // Map integer to character
        result += (char)('a' + val);
    }
    cout << result << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}