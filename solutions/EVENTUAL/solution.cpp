#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to remove a substring if every character in that substring 
 * appears an even number of times. 
 * 
 * If we can remove the entire string, it implies that every character in the 
 * original string must appear an even number of times. 
 * 
 * Proof sketch:
 * 1. If every character appears an even number of times, we can simply choose the 
 *    entire string as the substring to erase in one go. Since the whole string 
 *    has an even count for every character, the condition is satisfied.
 * 2. If any character appears an odd number of times, no matter how many 
 *    substrings we remove (each of which must have even counts for all characters), 
 *    the parity of the count of that character will never change. Since we start 
 *    with an odd count and we want to reach an empty string (where all counts are 0, 
 *    which is even), it is impossible.
 * 
 * Therefore, the condition is simply: "YES" if all character frequencies are even, 
 * otherwise "NO".
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Frequency array for lowercase English letters
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    bool possible = true;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}