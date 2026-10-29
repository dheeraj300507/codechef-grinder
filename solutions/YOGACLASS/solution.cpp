#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Type 1: 1 hour, earns X.
 * Type 2: 2 hours, earns Y.
 * We want to maximize earnings.
 * 
 * Since Type 2 sessions are 2 hours long, we can take at most N/2 sessions of Type 2.
 * Let k be the number of Type 2 sessions (0 <= k <= N/2).
 * The remaining (N - 2k) hours will be filled with Type 1 sessions.
 * Total earnings = k * Y + (N - 2k) * X.
 * 
 * We can iterate through all possible values of k from 0 to N/2 and find the maximum.
 * Given N <= 1000, an O(N) approach per test case is well within the time limit.
 */

void solve() {
    int N, X, Y;
    cin >> N >> X >> Y;

    long long max_earnings = 0;

    // k is the number of Type 2 sessions
    for (int k = 0; k <= N / 2; ++k) {
        long long current_earnings = (long long)k * Y + (long long)(N - 2 * k) * X;
        if (current_earnings > max_earnings) {
            max_earnings = current_earnings;
        }
    }

    cout << max_earnings << "\n";
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