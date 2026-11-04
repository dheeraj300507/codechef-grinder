#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N. We delete exactly one character S[i].
 * We want to find the number of distinct strings of length N-1.
 * 
 * Let's observe the operation:
 * If we have a sequence of identical characters like "111", deleting any of the 
 * '1's results in the same string "11".
 * If we have a sequence like "10", deleting '1' gives "0", and deleting '0' gives "1".
 * 
 * Key Insight:
 * Deleting S[i] results in the same string as deleting S[i+1] if and only if S[i] == S[i+1].
 * If S[i] != S[i+1], deleting S[i] results in a string where the character at index i 
 * is S[i+1], while deleting S[i+1] results in a string where the character at index i 
 * is S[i]. Since S[i] != S[i+1], these resulting strings are distinct.
 * 
 * Effectively, we are counting the number of "blocks" of identical consecutive characters.
 * For example:
 * 100 -> Blocks are {1}, {00}. Number of blocks = 2.
 * 1111 -> Blocks are {1111}. Number of blocks = 1.
 * 10110 -> Blocks are {1}, {0}, {11}, {0}. Number of blocks = 4.
 * 
 * The number of distinct strings is equal to the number of contiguous blocks of 
 * identical characters in the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    int blocks = 1;
    for (int i = 1; i < N; ++i) {
        if (S[i] != S[i - 1]) {
            blocks++;
        }
    }

    cout << blocks << "\n";
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