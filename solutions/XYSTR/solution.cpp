#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a string of 'x' (girls) and 'y' (boys).
 * We want to form the maximum number of pairs (boy, girl) where the students are adjacent.
 * This is a classic greedy problem. We iterate through the string from left to right.
 * If we find an adjacent pair (S[i], S[i+1]) such that one is 'x' and the other is 'y',
 * we form a pair and skip both students (move to i+2).
 * If they are not a pair, we move to the next student (i+1).
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int pairs = 0;
    
    // Iterate through the string, checking adjacent pairs
    for (int i = 0; i < n - 1; ) {
        // Check if current student and next student are different
        if (s[i] != s[i + 1]) {
            pairs++;
            // Both students are now paired, move to the next available student
            i += 2;
        } else {
            // Cannot pair these two, move to the next student
            i++;
        }
    }
    
    cout << pairs << "\n";
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