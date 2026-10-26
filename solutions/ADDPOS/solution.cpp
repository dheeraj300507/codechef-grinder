#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of length N.
 * We want to find the minimum non-negative integer X such that:
 * Sum(A_i + X) >= 0 for all i from 1 to N.
 * 
 * Expanding the sum:
 * Sum(A_i) + Sum(X) >= 0
 * Sum(A_i) + N * X >= 0
 * N * X >= -Sum(A_i)
 * X >= -Sum(A_i) / N
 * 
 * Since X must be a non-negative integer:
 * If Sum(A_i) >= 0, then X = 0 is sufficient.
 * If Sum(A_i) < 0, then X >= ceil(-Sum(A_i) / N).
 * 
 * Let S = Sum(A_i).
 * If S < 0, we need N * X >= -S.
 * X = ceil(-S / N).
 * In integer arithmetic, ceil(a / b) for positive a, b is (a + b - 1) / b.
 */

void solve() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum += a;
    }

    if (sum >= 0) {
        cout << 0 << "\n";
    } else {
        // We need N * X >= -sum
        // X >= (-sum) / N
        // Since we need the smallest integer X, we use ceiling division
        long long target = -sum;
        long long x = (target + N - 1) / N;
        cout << x << "\n";
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