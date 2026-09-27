#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N balls into K boxes such that:
 * 1. Each box has at least 1 ball.
 * 2. No two boxes have the same number of balls.
 * 
 * To minimize the total number of balls required for K boxes, we should pick the 
 * smallest possible distinct integers starting from 1:
 * 1, 2, 3, ..., K.
 * 
 * The sum of these K integers is:
 * Sum = 1 + 2 + 3 + ... + K = K * (K + 1) / 2
 * 
 * If N < K * (K + 1) / 2, it is impossible to satisfy the conditions because 
 * even with the smallest possible distinct values, we exceed the available balls.
 * 
 * If N >= K * (K + 1) / 2, we can always satisfy the condition. 
 * We can start with the distribution {1, 2, 3, ..., K-1, X}, where X is the 
 * remaining balls: X = N - (1 + 2 + ... + K-1).
 * Since N >= K(K+1)/2, then X >= K. 
 * Because X >= K and the other boxes contain values up to K-1, all values 
 * are distinct and each box has at least 1 ball.
 * 
 * Constraints:
 * N <= 10^9, K <= 10^4.
 * K * (K + 1) / 2 can be up to ~5 * 10^7, which fits in a standard 32-bit integer,
 * but using long long is safer to prevent overflow during calculation.
 */

void solve() {
    long long N, K;
    cin >> N >> K;

    // The minimum sum of K distinct positive integers is K*(K+1)/2
    long long min_sum = K * (K + 1) / 2;

    if (N >= min_sum) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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