#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: DNA Storage
 * Approach:
 * The problem asks to map pairs of binary digits to specific characters:
 * "00" -> 'A'
 * "01" -> 'T'
 * "10" -> 'C'
 * "11" -> 'G'
 * 
 * Since N is even, we can iterate through the string with a step of 2,
 * extract the substring of length 2, and map it to the corresponding character.
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the input string and the result.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    string result = "";
    for (int i = 0; i < n; i += 2) {
        string pair = s.substr(i, 2);
        if (pair == "00") {
            result += 'A';
        } else if (pair == "01") {
            result += 'T';
        } else if (pair == "10") {
            result += 'C';
        } else if (pair == "11") {
            result += 'G';
        }
    }
    cout << result << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}