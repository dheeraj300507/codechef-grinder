#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a string of length N such that the number of distinct 
 * palindromic substrings is at most 5.
 * 
 * Consider the string consisting of repeating characters 'abc'.
 * If we use a pattern like "abcabcabc...", the distinct palindromic 
 * substrings are just the individual characters 'a', 'b', and 'c'.
 * Total distinct palindromes = 3.
 * 
 * Let's verify:
 * For S = "abcabc":
 * Palindromes are 'a', 'b', 'c'.
 * Any substring of length > 1 like "ab", "bc", "ca", "abca", etc., 
 * is not a palindrome.
 * 
 * Thus, the string "abcabc..." (repeating 'a', 'b', 'c') will have 
 * exactly 3 distinct palindromic substrings, which is <= 5.
 * This works for any N >= 1.
 */

void solve() {
    int N;
    cin >> N;
    string s = "";
    string pattern = "abc";
    for (int i = 0; i < N; ++i) {
        s += pattern[i % 3];
    }
    cout << s << "\n";
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