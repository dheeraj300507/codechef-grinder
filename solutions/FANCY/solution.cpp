#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if the word "not" exists as a standalone word in a given string S.
 * A word "not" is present if:
 * 1. The string is exactly "not".
 * 2. The string starts with "not " (followed by a space).
 * 3. The string ends with " not" (preceded by a space).
 * 4. The string contains " not " (surrounded by spaces).
 * 
 * Given the constraints (|S| <= 100), we can split the string into words or use 
 * string searching techniques. Using stringstream is an efficient way to extract 
 * words and check for equality with "not".
 */

void solve() {
    string s;
    getline(cin, s);
    
    stringstream ss(s);
    string word;
    bool found = false;
    
    while (ss >> word) {
        if (word == "not") {
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << "Real Fancy" << "\n";
    } else {
        cout << "regularly fancy" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    
    // Consume the newline character left after reading t
    string dummy;
    getline(cin, dummy);
    
    while (t--) {
        solve();
    }
    
    return 0;
}