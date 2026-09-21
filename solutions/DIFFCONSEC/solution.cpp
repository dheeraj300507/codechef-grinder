#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S and we want to ensure no two consecutive characters are the same.
 * We can insert characters to break sequences of identical characters.
 * 
 * If we have a sequence of identical characters like "00", we must insert a character
 * between them to make it "010". This takes 1 operation.
 * If we have "000", we need to break the first pair (0100) and then the second pair (01010).
 * Essentially, for every index i from 0 to N-2, if S[i] == S[i+1], we must perform 
 * an insertion to separate them.
 * 
 * Each time we find S[i] == S[i+1], we increment our operation count.
 * This is optimal because each insertion can fix exactly one pair of identical 
 * consecutive characters.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int operations = 0;
    // Iterate through the string and check adjacent characters
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == S[i + 1]) {
            operations++;
        }
    }
    cout << operations << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}