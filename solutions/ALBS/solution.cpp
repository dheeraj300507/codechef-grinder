#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string alternating (S[i] != S[i-1]).
 * An operation at index i flips all characters from i to N.
 * Let's look at the boundaries where the alternating property is violated.
 * A violation occurs at index i (where 2 <= i <= N) if S[i] == S[i-1].
 * 
 * When we perform an operation at index i, it flips S[i], S[i+1], ..., S[N].
 * This operation changes the relationship between S[i-1] and S[i].
 * Specifically, if S[i-1] == S[i] before the flip, after the flip, 
 * S[i] becomes the opposite, so S[i-1] != S[i].
 * 
 * This is a classic problem where we can count the number of adjacent pairs 
 * that violate the condition. If S[i] == S[i-1], we must perform an operation 
 * to fix this. Because an operation at index i affects all subsequent 
 * relationships, we can process the string from left to right. 
 * Every time we encounter a violation S[i] == S[i-1], we perform an operation 
 * at index i, which fixes the current violation and potentially changes 
 * the state of the rest of the string.
 * 
 * The number of operations is simply the count of indices i (from 2 to N) 
 * such that S[i] == S[i-1].
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N <= 1) {
        cout << 0 << "\n";
        return;
    }

    int operations = 0;
    // We count how many times the alternating condition is broken.
    // Each break requires exactly one operation to fix.
    for (int i = 1; i < N; ++i) {
        if (S[i] == S[i - 1]) {
            operations++;
        }
    }

    cout << operations << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}