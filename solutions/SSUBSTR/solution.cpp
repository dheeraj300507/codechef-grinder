#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * A binary string is sorted if it contains no "10" substring.
 * Each operation allows removing a sorted substring (0...0, 1...1, or 0...01...1).
 * Removing a sorted substring can eliminate one "10" transition.
 * The minimum number of operations is the count of occurrences where '1' is 
 * immediately followed by '0'.
 * 
 * Complexity: O(N) time per test case, O(N) space to store the string.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int count10 = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '0') {
            count10++;
        }
    }
    cout << count10 << "\n";
}

int main() {
    // Optimize I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}