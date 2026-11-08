#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S. We need to check if there exists a character 'c' 
 * such that the frequency of 'c' is equal to the sum of the frequencies 
 * of all other characters in the string.
 * 
 * Let N be the total length of the string.
 * Let freq(c) be the frequency of character c.
 * The condition is: freq(c) = sum_{x != c} freq(x).
 * Since sum_{all x} freq(x) = N, the condition is equivalent to:
 * freq(c) = N - freq(c)
 * 2 * freq(c) = N
 * freq(c) = N / 2.
 * 
 * So, we simply need to check if any character in the string appears 
 * exactly N/2 times, where N is the length of the string.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // Frequency map for characters 'a' through 'z'
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    bool found = false;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] * 2 == n) {
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}