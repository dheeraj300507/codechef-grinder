#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are looking for a substring s1 of A and s2 of B such that s1 + s2 is a palindrome.
 * The simplest palindrome is a single character (e.g., "a").
 * If A and B share at least one common character, say 'x', we can choose s1 = "x" and s2 = "".
 * Wait, the problem says s1 and s2 must be non-empty.
 * If A and B share a common character 'c', we can pick s1 = "c" and s2 = "c".
 * Then s1 + s2 = "cc", which is a palindrome.
 * 
 * Is it possible to have a palindrome s1 + s2 without sharing a common character?
 * If s1 + s2 is a palindrome, it must read the same forwards and backwards.
 * If s1 + s2 has length >= 2, and we only have characters from A and B,
 * the only way to guarantee a palindrome is if there is at least one character
 * that exists in both A and B.
 * 
 * Proof:
 * If A and B share a character 'c', we can always form "cc", which is a palindrome.
 * If A and B share no characters, any s1 from A and s2 from B will consist of 
 * disjoint sets of characters. A palindrome s1 + s2 would require the first 
 * character of s1 to match the last character of s2, the second of s1 to match 
 * the second to last of s2, etc. If they share no characters, this is impossible.
 * 
 * Thus, the condition is simply: Do A and B share at least one common character?
 */

void solve() {
    string A, B;
    cin >> A >> B;

    vector<bool> existsInA(26, false);
    for (char c : A) {
        existsInA[c - 'a'] = true;
    }

    bool found = false;
    for (char c : B) {
        if (existsInA[c - 'a']) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}