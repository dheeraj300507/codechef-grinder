#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a string of length N such that no substring of length >= 2 is a palindrome.
 * A substring of length 2 is a palindrome if S[i] == S[i+1].
 * A substring of length 3 is a palindrome if S[i] == S[i+2].
 * If we ensure that S[i] != S[i-1] and S[i] != S[i-2] for all i,
 * then no substring of length 2 or 3 can be a palindrome.
 * If no substring of length 2 or 3 is a palindrome, then no substring of length > 3
 * can be a palindrome either (because any palindrome of length > 3 would contain
 * a smaller palindrome of length 2 or 3 as a core).
 * 
 * We can achieve this by cycling through the first 3 letters of the alphabet ('a', 'b', 'c').
 * Pattern: "abcabcabc..."
 * - S[i] != S[i-1] is satisfied (e.g., 'a' != 'b', 'b' != 'c', 'c' != 'a').
 * - S[i] != S[i-2] is satisfied (e.g., 'a' != 'c', 'b' != 'a', 'c' != 'b').
 */

void solve() {
    int N;
    cin >> N;
    string result = "";
    for (int i = 0; i < N; ++i) {
        // Use modulo 3 to cycle through 'a', 'b', 'c'
        result += (char)('a' + (i % 3));
    }
    cout << result << "\n";
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