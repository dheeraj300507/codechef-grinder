#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * We can flip a prefix S[1...X] if it has an equal number of 0s and 1s.
 * Let's define a balance value for each prefix:
 * Let count0(i) be the number of 0s in S[1...i] and count1(i) be the number of 1s.
 * A prefix S[1...X] can be flipped if count0(X) == count1(X).
 * 
 * Let's look at the sequence of characters. If we group consecutive identical characters,
 * e.g., 001101 -> (00), (11), (0), (1).
 * Flipping a prefix of length X where count0(X) == count1(X) effectively merges 
 * the boundary at X with the previous block or creates a new one.
 * 
 * Actually, the problem can be simplified by observing the blocks of identical characters.
 * Let the string be represented as a sequence of blocks of identical characters.
 * For example, 001101 -> 00, 11, 0, 1.
 * A prefix of length X has equal 0s and 1s if and only if the prefix ends at the end of a block
 * such that the total number of 0s equals the total number of 1s.
 * 
 * By performing the allowed operations, we can change the state of the string.
 * The number of reachable strings is determined by the number of "flippable" boundaries.
 * A boundary after index i is flippable if the prefix S[1...i] has equal 0s and 1s.
 * Let these indices be i_1, i_2, ..., i_k.
 * Each such index allows us to flip the prefix, which toggles the state of all blocks 
 * before that index. This is equivalent to choosing a subset of these k boundaries 
 * to perform flips. However, since flipping a prefix changes the balance of subsequent 
 * prefixes, we analyze the independent segments.
 * 
 * The number of reachable strings is 2^k, where k is the number of indices i 
 * such that S[1...i] has equal 0s and 1s.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count0 = 0;
    int count1 = 0;
    long long k = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') count0++;
        else count1++;

        if (count0 == count1) {
            k++;
        }
    }

    // The number of reachable strings is 2^k.
    // Since N <= 60, 2^60 fits in a long long.
    long long ans = 1LL << k;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}