#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N assignments already completed with scores A_1, ..., A_N.
 * There is one more assignment (the (N+1)-th).
 * Total assignments = N + 1.
 * Total possible marks = (N + 1) * 100.
 * To pass, Chef needs at least 50% of the total possible marks.
 * Required total marks = 0.5 * (N + 1) * 100 = 50 * (N + 1).
 * Let S be the sum of the first N assignments.
 * Let X be the score on the (N+1)-th assignment.
 * We need: S + X >= 50 * (N + 1)
 * Therefore: X >= 50 * (N + 1) - S
 * 
 * Constraints:
 * 0 <= X <= 100
 * If the calculated X is > 100, it's impossible (-1).
 * If the calculated X is < 0, it means he already has enough marks, so he needs 0.
 */

void solve() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        sum += a;
    }

    long long target = 50LL * (N + 1);
    long long needed = target - sum;

    if (needed > 100) {
        cout << -1 << "\n";
    } else if (needed < 0) {
        cout << 0 << "\n";
    } else {
        cout << needed << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}